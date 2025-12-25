#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

// Global variables
Mat frame, doodleLayer;
bool drawing = false;
Point lastPoint;
Scalar drawColor = Scalar(0, 0, 255);
int brushSize = 3;
bool showHelp = true;

// Mouse callback function
void mouseCallback(int event, int x, int y, int flags, void* userdata) {
    
    if (event == EVENT_LBUTTONDOWN) {
        drawing = true;
        lastPoint = Point(x, y);
        cout << "Drawing started at: (" << x << ", " << y << ")" << endl;
    }
    
    else if (event == EVENT_MOUSEMOVE && drawing) {
        line(doodleLayer, lastPoint, Point(x, y), drawColor, brushSize);
        lastPoint = Point(x, y);
    }
    
    else if (event == EVENT_LBUTTONUP) {
        drawing = false;
        cout << "Drawing stopped" << endl;
    }
    
    else if (event == EVENT_MOUSEWHEEL) {
        if (flags > 0) {
            brushSize += 1;
            if (brushSize > 10) brushSize = 10;
            cout << "Brush size: " << brushSize << endl;
        } else {
            brushSize -= 1;
            if (brushSize < 1) brushSize = 1;
            cout << "Brush size: " << brushSize << endl;
        }
    }
}

// Draw help text on frame
void drawHelpText(Mat& img) {
    int fontFace = FONT_HERSHEY_SIMPLEX;
    double fontScale = 0.5;
    int thickness = 1;
    Scalar textColor = Scalar(255, 255, 255);
    int lineType = LINE_AA;
    
    rectangle(img, Point(10, 10), Point(300, 200), Scalar(0, 0, 0), -1);
    rectangle(img, Point(10, 10), Point(300, 200), Scalar(255, 255, 255), 2);
    
    putText(img, "CONTROLS:", Point(20, 30), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "Click & Drag: Draw", Point(20, 50), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "C: Clear", Point(20, 70), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "R: Red | G: Green | B: Blue", Point(20, 90), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "Y: Yellow | P: Purple", Point(20, 110), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "Scroll: Brush Size", Point(20, 130), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "H: Toggle Help", Point(20, 150), fontFace, fontScale, textColor, thickness, lineType);
    putText(img, "ESC: Exit", Point(20, 170), fontFace, fontScale, textColor, thickness, lineType);
    
    string brushInfo = "Brush: " + to_string(brushSize) + "px";
    putText(img, brushInfo, Point(20, 190), fontFace, fontScale, textColor, thickness, lineType);
}

// Main function
int main() {
    cout << "Live Doodle on Camera - Advanced" << endl;
    cout << "=================================" << endl << endl;
    
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
    string windowName = "Live Doodle on Camera";
    namedWindow(windowName, WINDOW_AUTOSIZE);
    
    // Register mouse callback
    cout << "Registering mouse callback..." << endl;
    setMouseCallback(windowName, mouseCallback, nullptr);
    
    // Print instructions
    cout << endl << "INSTRUCTIONS:" << endl;
    cout << "=================================" << endl;
    cout << "Click and drag mouse to draw lines" << endl;
    cout << "Scroll mouse wheel to change brush size" << endl;
    cout << "Press 'C' to clear all drawings" << endl;
    cout << "Press 'R' for red, 'G' for green, 'B' for blue" << endl;
    cout << "Press 'Y' for yellow, 'P' for purple" << endl;
    cout << "Press 'H' to toggle help menu" << endl;
    cout << "Press 'ESC' to exit program" << endl;
    cout << "=================================" << endl << endl;
    
    cout << "Program is running. Press ESC to exit." << endl << endl;
    
    // Main loop
    while (true) {
        camera >> frame;
        
        if (frame.empty()) {
            cerr << "Error: Failed to capture frame." << endl;
            break;
        }
        
        if (doodleLayer.empty()) {
            doodleLayer = Mat::zeros(frame.size(), CV_8UC3);
        }
        
        Mat output;
        addWeighted(frame, 1.0, doodleLayer, 1.0, 0, output);
        
        if (showHelp) {
            drawHelpText(output);
        }
        
        imshow(windowName, output);
        
        int key = waitKey(1) & 0xFF;
        
        if (key == 'c' || key == 'C') {
            doodleLayer = Mat::zeros(frame.size(), CV_8UC3);
            cout << "Drawing cleared" << endl;
        }
        else if (key == 'r' || key == 'R') {
            drawColor = Scalar(0, 0, 255);
            cout << "Red color selected" << endl;
        }
        else if (key == 'g' || key == 'G') {
            drawColor = Scalar(0, 255, 0);
            cout << "Green color selected" << endl;
        }
        else if (key == 'b' || key == 'B') {
            drawColor = Scalar(255, 0, 0);
            cout << "Blue color selected" << endl;
        }
        else if (key == 'y' || key == 'Y') {
            drawColor = Scalar(0, 255, 255);
            cout << "Yellow color selected" << endl;
        }
        else if (key == 'p' || key == 'P') {
            drawColor = Scalar(255, 0, 255);
            cout << "Purple color selected" << endl;
        }
        else if (key == 'h' || key == 'H') {
            showHelp = !showHelp;
            if (showHelp) {
                cout << "Help enabled" << endl;
            } else {
                cout << "Help disabled" << endl;
            }
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
