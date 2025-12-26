#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <ctime>
#include <random>

using namespace cv;
using namespace std;

// Enums for tools
enum DrawTool {
    BRUSH,
    ERASER,
    LINE,
    RECTANGLE,
    CIRCLE,
    ELLIPSE,
    SPRAY,
    FILL
};

// Global variables
Mat frame, doodleLayer, tempLayer;
stack<Mat> undoStack, redoStack;
bool drawing = false;
Point lastPoint, startPoint;
Scalar drawColor = Scalar(0, 0, 255);
Scalar backgroundColor = Scalar(0, 0, 0);
int brushSize = 3;
bool showHelp = true;
bool showColorPalette = true;
DrawTool currentTool = BRUSH;
string toolNames[] = {"Brush", "Eraser", "Line", "Rectangle", "Circle", "Ellipse", "Spray", "Fill"};

// Color palette
vector<Scalar> colorPalette = {
    Scalar(0, 0, 255),      // Red
    Scalar(0, 255, 0),      // Green
    Scalar(255, 0, 0),      // Blue
    Scalar(0, 255, 255),    // Yellow
    Scalar(255, 0, 255),    // Magenta
    Scalar(255, 255, 0),    // Cyan
    Scalar(255, 255, 255),  // White
    Scalar(128, 128, 128),  // Gray
    Scalar(0, 128, 255),    // Orange
    Scalar(203, 192, 255)   // Pink
};

// Random number generator for spray
default_random_engine generator;
uniform_int_distribution<int> distribution(-10, 10);

// Function to save current state for undo
void saveState() {
    undoStack.push(doodleLayer.clone());
    // Clear redo stack when new action is performed
    while (!redoStack.empty()) {
        redoStack.pop();
    }
    // Limit undo stack to 20 states to save memory
    if (undoStack.size() > 20) {
        stack<Mat> tempStack;
        while (undoStack.size() > 1) {
            tempStack.push(undoStack.top());
            undoStack.pop();
        }
        undoStack.pop();
        while (!tempStack.empty()) {
            undoStack.push(tempStack.top());
            tempStack.pop();
        }
    }
}

// Undo function
void undo() {
    if (!undoStack.empty()) {
        redoStack.push(doodleLayer.clone());
        doodleLayer = undoStack.top().clone();
        undoStack.pop();
        cout << "Undo performed" << endl;
    } else {
        cout << "Nothing to undo" << endl;
    }
}

// Redo function
void redo() {
    if (!redoStack.empty()) {
        undoStack.push(doodleLayer.clone());
        doodleLayer = redoStack.top().clone();
        redoStack.pop();
        cout << "Redo performed" << endl;
    } else {
        cout << "Nothing to redo" << endl;
    }
}

// Spray paint effect
void sprayPaint(Mat& img, Point center, Scalar color, int radius) {
    int numParticles = radius * 2;
    for (int i = 0; i < numParticles; i++) {
        int offsetX = distribution(generator) * radius / 10;
        int offsetY = distribution(generator) * radius / 10;
        Point particle = Point(center.x + offsetX, center.y + offsetY);
        if (particle.x >= 0 && particle.x < img.cols && particle.y >= 0 && particle.y < img.rows) {
            circle(img, particle, 1, color, -1);
        }
    }
}

// Flood fill function
void floodFillTool(Mat& img, Point seed, Scalar newColor) {
    if (seed.x < 0 || seed.x >= img.cols || seed.y < 0 || seed.y >= img.rows) {
        return;
    }
    Scalar tolerance = Scalar(10, 10, 10);
    floodFill(img, seed, newColor, nullptr, tolerance, tolerance, FLOODFILL_FIXED_RANGE);
}

// Mouse callback function
void mouseCallback(int event, int x, int y, int flags, void* userdata) {
    
    if (event == EVENT_LBUTTONDOWN) {
        // Check if clicking on color palette
        if (showColorPalette && y < 60 && x > 10 && x < 10 + colorPalette.size() * 40) {
            int colorIndex = (x - 10) / 40;
            if (colorIndex < colorPalette.size()) {
                drawColor = colorPalette[colorIndex];
                cout << "Color changed" << endl;
                return;
            }
        }
        
        drawing = true;
        lastPoint = Point(x, y);
        startPoint = Point(x, y);
        
        if (currentTool == FILL) {
            saveState();
            floodFillTool(doodleLayer, Point(x, y), drawColor);
            cout << "Fill applied at: (" << x << ", " << y << ")" << endl;
        } else if (currentTool == SPRAY) {
            saveState();
            sprayPaint(doodleLayer, Point(x, y), drawColor, brushSize * 2);
        } else if (currentTool == BRUSH || currentTool == ERASER) {
            saveState();
        } else {
            // For shape tools, save state when drawing starts
            tempLayer = doodleLayer.clone();
        }
        
        cout << "Drawing started at: (" << x << ", " << y << ")" << endl;
    }
    
    else if (event == EVENT_MOUSEMOVE && drawing) {
        if (currentTool == BRUSH) {
            line(doodleLayer, lastPoint, Point(x, y), drawColor, brushSize, LINE_AA);
            lastPoint = Point(x, y);
        }
        else if (currentTool == ERASER) {
            line(doodleLayer, lastPoint, Point(x, y), backgroundColor, brushSize * 2, LINE_AA);
            lastPoint = Point(x, y);
        }
        else if (currentTool == SPRAY) {
            sprayPaint(doodleLayer, Point(x, y), drawColor, brushSize * 2);
        }
        else if (currentTool == LINE) {
            doodleLayer = tempLayer.clone();
            line(doodleLayer, startPoint, Point(x, y), drawColor, brushSize, LINE_AA);
        }
        else if (currentTool == RECTANGLE) {
            doodleLayer = tempLayer.clone();
            rectangle(doodleLayer, startPoint, Point(x, y), drawColor, brushSize);
        }
        else if (currentTool == CIRCLE) {
            doodleLayer = tempLayer.clone();
            int radius = (int)sqrt(pow(x - startPoint.x, 2) + pow(y - startPoint.y, 2));
            circle(doodleLayer, startPoint, radius, drawColor, brushSize);
        }
        else if (currentTool == ELLIPSE) {
            doodleLayer = tempLayer.clone();
            int width = abs(x - startPoint.x);
            int height = abs(y - startPoint.y);
            Point center = Point((startPoint.x + x) / 2, (startPoint.y + y) / 2);
            ellipse(doodleLayer, center, Size(width / 2, height / 2), 0, 0, 360, drawColor, brushSize);
        }
    }
    
    else if (event == EVENT_LBUTTONUP) {
        if (drawing && (currentTool >= LINE && currentTool <= ELLIPSE)) {
            saveState();
        }
        drawing = false;
        cout << "Drawing stopped" << endl;
    }
    
    else if (event == EVENT_MOUSEWHEEL) {
        if (flags > 0) {
            brushSize += 1;
            if (brushSize > 20) brushSize = 20;
            cout << "Brush size: " << brushSize << endl;
        } else {
            brushSize -= 1;
            if (brushSize < 1) brushSize = 1;
            cout << "Brush size: " << brushSize << endl;
        }
    }
}

// Draw color palette
void drawColorPalette(Mat& img) {
    int startX = 10;
    int startY = 10;
    int size = 40;
    
    for (int i = 0; i < colorPalette.size(); i++) {
        rectangle(img, Point(startX + i * size, startY), 
                  Point(startX + (i + 1) * size - 5, startY + size), 
                  colorPalette[i], -1);
        rectangle(img, Point(startX + i * size, startY), 
                  Point(startX + (i + 1) * size - 5, startY + size), 
                  Scalar(255, 255, 255), 2);
        
        // Highlight selected color
        if (drawColor == colorPalette[i]) {
            rectangle(img, Point(startX + i * size - 2, startY - 2), 
                      Point(startX + (i + 1) * size - 3, startY + size + 2), 
                      Scalar(255, 255, 0), 3);
        }
    }
}

// Draw help text on frame
void drawHelpText(Mat& img) {
    int fontFace = FONT_HERSHEY_SIMPLEX;
    double fontScale = 0.45;
    int thickness = 1;
    Scalar textColor = Scalar(255, 255, 255);
    int lineType = LINE_AA;
    
    rectangle(img, Point(10, 70), Point(350, 380), Scalar(0, 0, 0, 180), -1);
    rectangle(img, Point(10, 70), Point(350, 380), Scalar(255, 255, 255), 2);
    
    putText(img, "ADVANCED CONTROLS:", Point(20, 90), fontFace, 0.5, textColor, thickness + 1, lineType);
    putText(img, "===================", Point(20, 105), fontFace, fontScale, textColor, thickness, lineType);
    
    putText(img, "DRAWING:", Point(20, 125), fontFace, fontScale, Scalar(0, 255, 255), thickness, lineType);
    putText(img, "  Left Click & Drag: Draw", Point(20, 145), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "  Scroll Wheel: Brush Size", Point(20, 160), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "  Click Palette: Change Color", Point(20, 175), fontFace, fontScale, textColor, thickness, lineType);
    
    putText(img, "TOOLS: (1-8 keys)", Point(20, 195), fontFace, fontScale, Scalar(0, 255, 255), thickness, lineType);
    putText(img, "  1: Brush  2: Eraser  3: Line", Point(20, 210), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "  4: Rectangle  5: Circle", Point(20, 225), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "  6: Ellipse  7: Spray  8: Fill", Point(20, 240), fontFace, fontScale, textColor, thickness, lineType);
    
    putText(img, "ACTIONS:", Point(20, 260), fontFace, fontScale, Scalar(0, 255, 255), thickness, lineType);
    putText(img, "  C: Clear Canvas", Point(20, 275), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "  Z: Undo  X: Redo", Point(20, 290), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "  S: Save Drawing", Point(20, 305), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "  P: Toggle Palette", Point(20, 320), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "  H: Toggle Help", Point(20, 335), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "  ESC: Exit", Point(20, 350), fontFace, fontScale, textColor, thickness, lineType);
    
    string info = "Tool: " + toolNames[currentTool] + " | Size: " + to_string(brushSize) + "px";
    putText(img, info, Point(20, 370), fontFace, fontScale, Scalar(0, 255, 0), thickness, lineType);
}

// Save drawing to file
void saveDrawing() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char filename[100];
    sprintf(filename, "doodle_%04d%02d%02d_%02d%02d%02d.png",
            1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
            ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    
    imwrite(filename, doodleLayer);
    cout << "Drawing saved as: " << filename << endl;
}

// Main function
int main() {
    cout << "======================================" << endl;
    cout << "  Live Doodle on Camera - ADVANCED  " << endl;
    cout << "======================================" << endl << endl;
    
    // Initialize random seed
    generator.seed(time(0));
    
    // Initialize camera
    cout << "Initializing camera..." << endl;
    VideoCapture camera(0);
    
    if (!camera.isOpened()) {
        cerr << "Error: Cannot open camera. Check if it's connected." << endl;
        return -1;
    }
    cout << "Camera initialized successfully" << endl;
    
    // Set camera resolution
    camera.set(CAP_PROP_FRAME_WIDTH, 640);
    camera.set(CAP_PROP_FRAME_HEIGHT, 480);
    
    // Create window
    cout << "Creating display window..." << endl;
    string windowName = "Live Doodle on Camera - Advanced";
    namedWindow(windowName, WINDOW_AUTOSIZE);
    
    // Register mouse callback
    cout << "Registering mouse callback..." << endl;
    setMouseCallback(windowName, mouseCallback, nullptr);
    
    // Print instructions
    cout << endl << "NEW FEATURES:" << endl;
    cout << "======================================" << endl;
    cout << "✓ Undo/Redo (Z/X keys)" << endl;
    cout << "✓ Multiple drawing tools (1-8)" << endl;
    cout << "✓ Shape tools (Line, Rectangle, Circle, Ellipse)" << endl;
    cout << "✓ Spray paint & Fill tool" << endl;
    cout << "✓ Eraser tool" << endl;
    cout << "✓ Color palette" << endl;
    cout << "✓ Save drawings (S key)" << endl;
    cout << "✓ Enhanced controls" << endl;
    cout << "======================================" << endl << endl;
    
    cout << "Program is running. Press H for help, ESC to exit." << endl << endl;
    
    // Main loop
    while (true) {
        camera >> frame;
        
        if (frame.empty()) {
            cerr << "Error: Failed to capture frame." << endl;
            break;
        }
        
        if (doodleLayer.empty()) {
            doodleLayer = Mat::zeros(frame.size(), CV_8UC3);
            tempLayer = Mat::zeros(frame.size(), CV_8UC3);
        }
        
        Mat output;
        addWeighted(frame, 1.0, doodleLayer, 1.0, 0, output);
        
        if (showColorPalette) {
            drawColorPalette(output);
        }
        
        if (showHelp) {
            drawHelpText(output);
        }
        
        imshow(windowName, output);
        
        int key = waitKey(1) & 0xFF;
        
        // Tool selection
        if (key == '1') {
            currentTool = BRUSH;
            cout << "Tool: Brush" << endl;
        }
        else if (key == '2') {
            currentTool = ERASER;
            cout << "Tool: Eraser" << endl;
        }
        else if (key == '3') {
            currentTool = LINE;
            cout << "Tool: Line" << endl;
        }
        else if (key == '4') {
            currentTool = RECTANGLE;
            cout << "Tool: Rectangle" << endl;
        }
        else if (key == '5') {
            currentTool = CIRCLE;
            cout << "Tool: Circle" << endl;
        }
        else if (key == '6') {
            currentTool = ELLIPSE;
            cout << "Tool: Ellipse" << endl;
        }
        else if (key == '7') {
            currentTool = SPRAY;
            cout << "Tool: Spray Paint" << endl;
        }
        else if (key == '8') {
            currentTool = FILL;
            cout << "Tool: Fill" << endl;
        }
        // Actions
        else if (key == 'c' || key == 'C') {
            saveState();
            doodleLayer = Mat::zeros(frame.size(), CV_8UC3);
            cout << "Drawing cleared" << endl;
        }
        else if (key == 'z' || key == 'Z') {
            undo();
        }
        else if (key == 'x' || key == 'X') {
            redo();
        }
        else if (key == 's' || key == 'S') {
            saveDrawing();
        }
        else if (key == 'h' || key == 'H') {
            showHelp = !showHelp;
            cout << (showHelp ? "Help enabled" : "Help disabled") << endl;
        }
        else if (key == 'p' || key == 'P') {
            showColorPalette = !showColorPalette;
            cout << (showColorPalette ? "Palette enabled" : "Palette disabled") << endl;
        }
        else if (key == 27) {
            cout << endl << "Exiting program..." << endl;
            break;
        }
    }
    
    // Cleanup
    cout << "Releasing resources..." << endl;
    camera.release();
    destroyAllWindows();
    cout << "Done. Goodbye!" << endl << endl;
    
    return 0;
}
