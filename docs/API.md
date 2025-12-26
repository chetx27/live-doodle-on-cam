# API Reference

## Table of Contents

- [Core Classes](#core-classes)
- [Drawing Functions](#drawing-functions)
- [State Management](#state-management)
- [UI Components](#ui-components)
- [File Operations](#file-operations)
- [Utility Functions](#utility-functions)

---

## Core Classes

### DrawingState

Manages the application state and drawing context.

```cpp
struct DrawingState {
    cv::Mat canvas;              // Drawing layer
    cv::Mat background;          // Camera frame
    cv::Scalar currentColor;     // Active color
    int brushSize;               // Brush radius
    Tool currentTool;            // Active tool
    bool isDrawing;              // Drawing state flag
};
```

**Members:**
- `canvas`: The drawing layer (transparent background)
- `background`: Current camera frame
- `currentColor`: BGR color value
- `brushSize`: Brush radius in pixels (1-20)
- `currentTool`: Enum representing active tool
- `isDrawing`: Boolean flag for active drawing operation

---

## Drawing Functions

### mouseCallback

```cpp
void mouseCallback(int event, int x, int y, int flags, void* userdata);
```

**Description:**  
Handles mouse events for drawing operations.

**Parameters:**
- `event`: OpenCV mouse event type (EVENT_LBUTTONDOWN, EVENT_MOUSEMOVE, EVENT_LBUTTONUP)
- `x`: X coordinate of mouse position
- `y`: Y coordinate of mouse position
- `flags`: Additional event flags
- `userdata`: Pointer to DrawingState structure

**Events Handled:**
- `EVENT_LBUTTONDOWN`: Start drawing operation
- `EVENT_MOUSEMOVE`: Continue drawing or show preview
- `EVENT_LBUTTONUP`: Complete drawing operation

**Example:**
```cpp
DrawingState state;
cv::setMouseCallback("Live Doodle", mouseCallback, &state);
```

---

### drawLine

```cpp
void drawLine(cv::Mat& img, cv::Point start, cv::Point end, 
              cv::Scalar color, int thickness);
```

**Description:**  
Draws an anti-aliased line between two points.

**Parameters:**
- `img`: Target image matrix
- `start`: Starting point
- `end`: Ending point
- `color`: Line color (BGR)
- `thickness`: Line thickness in pixels

**Implementation:**
```cpp
cv::line(img, start, end, color, thickness, cv::LINE_AA);
```

---

### drawRectangle

```cpp
void drawRectangle(cv::Mat& img, cv::Point topLeft, cv::Point bottomRight,
                   cv::Scalar color, int thickness);
```

**Description:**  
Draws a rectangle with specified corners.

**Parameters:**
- `img`: Target image matrix
- `topLeft`: Top-left corner coordinate
- `bottomRight`: Bottom-right corner coordinate
- `color`: Rectangle color (BGR)
- `thickness`: Border thickness (-1 for filled)

---

### drawCircle

```cpp
void drawCircle(cv::Mat& img, cv::Point center, int radius,
                cv::Scalar color, int thickness);
```

**Description:**  
Draws a circle with specified center and radius.

**Parameters:**
- `img`: Target image matrix
- `center`: Circle center point
- `radius`: Circle radius in pixels
- `color`: Circle color (BGR)
- `thickness`: Border thickness (-1 for filled)

**Example:**
```cpp
cv::Point center(320, 240);
int radius = 50;
drawCircle(canvas, center, radius, cv::Scalar(0, 255, 0), 2);
```

---

### drawEllipse

```cpp
void drawEllipse(cv::Mat& img, cv::Point center, cv::Size axes,
                 double angle, cv::Scalar color, int thickness);
```

**Description:**  
Draws an ellipse with specified parameters.

**Parameters:**
- `img`: Target image matrix
- `center`: Ellipse center point
- `axes`: Size of ellipse axes (width, height)
- `angle`: Rotation angle in degrees
- `color`: Ellipse color (BGR)
- `thickness`: Border thickness (-1 for filled)

---

### sprayPaint

```cpp
void sprayPaint(cv::Mat& img, cv::Point center, cv::Scalar color, 
                int radius, int density = 50);
```

**Description:**  
Creates a spray paint effect using random particle distribution.

**Parameters:**
- `img`: Target image matrix
- `center`: Spray center point
- `color`: Particle color (BGR)
- `radius`: Spray radius in pixels
- `density`: Number of particles (default: 50)

**Algorithm:**
```cpp
for (int i = 0; i < density; i++) {
    int offsetX = (rand() % (2 * radius)) - radius;
    int offsetY = (rand() % (2 * radius)) - radius;
    if (offsetX * offsetX + offsetY * offsetY <= radius * radius) {
        cv::circle(img, center + cv::Point(offsetX, offsetY), 
                  1, color, -1, cv::LINE_AA);
    }
}
```

---

### floodFillTool

```cpp
void floodFillTool(cv::Mat& img, cv::Point seed, cv::Scalar newColor);
```

**Description:**  
Performs flood fill operation on connected region.

**Parameters:**
- `img`: Target image matrix
- `seed`: Starting point for fill
- `newColor`: Fill color (BGR)

**Implementation:**
```cpp
cv::floodFill(img, seed, newColor, nullptr, 
              cv::Scalar(10, 10, 10), cv::Scalar(10, 10, 10));
```

---

## State Management

### saveState

```cpp
void saveState(std::stack<cv::Mat>& undoStack, 
               std::stack<cv::Mat>& redoStack,
               const cv::Mat& canvas, 
               int maxLevels = 20);
```

**Description:**  
Saves current canvas state to undo stack.

**Parameters:**
- `undoStack`: Stack for undo operations
- `redoStack`: Stack for redo operations (cleared on new action)
- `canvas`: Current canvas state
- `maxLevels`: Maximum stack depth (default: 20)

**Behavior:**
- Clones current canvas
- Pushes to undo stack
- Clears redo stack
- Maintains maximum stack size

---

### undo

```cpp
bool undo(std::stack<cv::Mat>& undoStack, 
          std::stack<cv::Mat>& redoStack,
          cv::Mat& canvas);
```

**Description:**  
Reverts to previous canvas state.

**Parameters:**
- `undoStack`: Stack containing previous states
- `redoStack`: Stack for storing undone states
- `canvas`: Current canvas to be restored

**Returns:**
- `true`: Undo successful
- `false`: Undo stack empty

---

### redo

```cpp
bool redo(std::stack<cv::Mat>& undoStack,
          std::stack<cv::Mat>& redoStack,
          cv::Mat& canvas);
```

**Description:**  
Restores previously undone state.

**Parameters:**
- `undoStack`: Stack for saving current state
- `redoStack`: Stack containing undone states
- `canvas`: Current canvas to be updated

**Returns:**
- `true`: Redo successful
- `false`: Redo stack empty

---

## UI Components

### drawColorPalette

```cpp
void drawColorPalette(cv::Mat& img, const std::vector<cv::Scalar>& colors,
                     int selectedIndex, int barHeight = 40);
```

**Description:**  
Renders interactive color palette at top of screen.

**Parameters:**
- `img`: Target image for palette overlay
- `colors`: Vector of available colors
- `selectedIndex`: Index of currently selected color
- `barHeight`: Palette height in pixels (default: 40)

**Layout:**
- Divides screen width by number of colors
- Highlights selected color with border
- Click detection: `index = x / (width / colors.size())`

---

### drawHelpText

```cpp
void drawHelpText(cv::Mat& img, bool show);
```

**Description:**  
Displays help overlay with keyboard shortcuts.

**Parameters:**
- `img`: Target image for help overlay
- `show`: Visibility flag

**Content:**
- Tool shortcuts (1-8)
- Action keys (C, Z, X, S, H, ESC)
- Mouse controls
- Current tool and color info

---

### drawToolIndicator

```cpp
void drawToolIndicator(cv::Mat& img, Tool currentTool, 
                      cv::Point position);
```

**Description:**  
Displays current tool name and icon.

**Parameters:**
- `img`: Target image
- `currentTool`: Active tool enum
- `position`: Screen position for indicator

---

## File Operations

### saveDrawing

```cpp
bool saveDrawing(const cv::Mat& canvas, const std::string& directory = ".");
```

**Description:**  
Exports canvas to PNG file with timestamp.

**Parameters:**
- `canvas`: Drawing canvas to export
- `directory`: Save directory (default: current)

**Returns:**
- `true`: Save successful
- `false`: Save failed

**Filename Format:**
```
doodle_YYYYMMDD_HHMMSS.png
```

**Example:**
```cpp
if (saveDrawing(canvas, "./drawings")) {
    std::cout << "Drawing saved successfully" << std::endl;
}
```

---

### loadConfiguration

```cpp
bool loadConfiguration(const std::string& filename, Configuration& config);
```

**Description:**  
Loads application settings from JSON file.

**Parameters:**
- `filename`: Path to config.json
- `config`: Configuration structure to populate

**Returns:**
- `true`: Load successful
- `false`: File not found or parse error

---

## Utility Functions

### getTimestamp

```cpp
std::string getTimestamp();
```

**Description:**  
Generates timestamp string for file naming.

**Returns:**  
Formatted timestamp: "YYYYMMDD_HHMMSS"

**Implementation:**
```cpp
std::time_t now = std::time(nullptr);
std::tm* localTime = std::localtime(&now);
char buffer[20];
std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);
return std::string(buffer);
```

---

### calculateDistance

```cpp
double calculateDistance(cv::Point p1, cv::Point p2);
```

**Description:**  
Calculates Euclidean distance between two points.

**Parameters:**
- `p1`: First point
- `p2`: Second point

**Returns:**  
Distance in pixels

**Formula:**
```cpp
return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
```

---

## Constants

```cpp
const int MAX_BRUSH_SIZE = 20;          // Maximum brush radius
const int MIN_BRUSH_SIZE = 1;           // Minimum brush radius
const int DEFAULT_BRUSH_SIZE = 3;       // Default brush radius
const int MAX_UNDO_LEVELS = 20;         // Undo stack depth
const int PALETTE_HEIGHT = 40;          // Color palette height
const int DEFAULT_FPS = 30;             // Target frame rate
const cv::Size DEFAULT_RESOLUTION(640, 480);  // Default camera resolution
```

---

## Enumerations

### Tool

```cpp
enum class Tool {
    BRUSH,       // Freehand drawing
    ERASER,      // Stroke removal
    LINE,        // Straight line
    RECTANGLE,   // Rectangle shape
    CIRCLE,      // Circle shape
    ELLIPSE,     // Ellipse shape
    SPRAY,       // Spray paint
    FILL         // Flood fill
};
```

---

## Error Codes

```cpp
enum class ErrorCode {
    SUCCESS = 0,
    CAMERA_NOT_FOUND = 1,
    CAMERA_INIT_FAILED = 2,
    FILE_SAVE_FAILED = 3,
    FILE_LOAD_FAILED = 4,
    INVALID_PARAMETER = 5,
    OUT_OF_MEMORY = 6
};
```

---

## Usage Examples

### Basic Drawing Loop

```cpp
int main() {
    cv::VideoCapture camera(0);
    if (!camera.isOpened()) {
        return ErrorCode::CAMERA_NOT_FOUND;
    }
    
    DrawingState state;
    state.canvas = cv::Mat::zeros(480, 640, CV_8UC3);
    state.currentTool = Tool::BRUSH;
    state.brushSize = DEFAULT_BRUSH_SIZE;
    
    cv::setMouseCallback("Live Doodle", mouseCallback, &state);
    
    while (true) {
        camera >> state.background;
        cv::Mat display = state.background.clone();
        cv::addWeighted(display, 0.7, state.canvas, 0.3, 0, display);
        
        cv::imshow("Live Doodle", display);
        
        int key = cv::waitKey(1);
        if (key == 27) break;  // ESC
    }
    
    return ErrorCode::SUCCESS;
}
```

### Complete Drawing Operation

```cpp
void handleDrawing(DrawingState& state, cv::Point current) {
    if (!state.isDrawing) return;
    
    switch (state.currentTool) {
        case Tool::BRUSH:
            cv::line(state.canvas, state.lastPoint, current,
                    state.currentColor, state.brushSize, cv::LINE_AA);
            break;
            
        case Tool::SPRAY:
            sprayPaint(state.canvas, current, state.currentColor,
                      state.brushSize);
            break;
            
        case Tool::FILL:
            floodFillTool(state.canvas, current, state.currentColor);
            break;
    }
    
    state.lastPoint = current;
}
```

---

## Performance Considerations

- Use `cv::Mat::clone()` sparingly (expensive operation)
- Implement dirty region tracking for large canvases
- Consider GPU acceleration for real-time processing
- Profile undo/redo stack memory usage
- Optimize spray paint density for performance

---

## Thread Safety

Current implementation is single-threaded. For multi-threaded applications:

- Protect shared state with mutexes
- Use atomic operations for flags
- Consider lock-free queues for event handling

---

Last Updated: December 2025
