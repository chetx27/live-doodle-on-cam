# System Architecture

## Overview

Live Doodle on Camera is designed as a modular, event-driven application leveraging OpenCV for computer vision capabilities and C++17 for performance and memory safety.

---

## High-Level Architecture

```
┌─────────────────────────────────────────┐
│           Application Entry Point            │
│                  main()                      │
└──────────────────┬──────────────────────┘
                   │
        ┌──────────┼──────────┐
        │           │           │
   ┌────┴────┐  ┌──┴───┐  ┌──┴───┐
   │  Input   │  │  Core  │  │   UI   │
   │ Handler │  │ Engine│  │ Render │
   └────┬────┘  └──┬───┘  └──┬───┘
        │           │           │
        └──────────┼──────────┘
                   │
        ┌──────────┼──────────┐
        │           │           │
   ┌────┴────┐  ┌──┴───┐  ┌──┴───┐
   │  State  │  │ Video │  │  File  │
   │ Manager│  │Capture│  │Manager│
   └─────────┘  └───────┘  └───────┘
```

---

## Component Details

### 1. Input Handler

**Responsibilities:**
- Mouse event processing
- Keyboard input handling
- Event routing to appropriate handlers

**Key Functions:**
- `mouseCallback()` - Process mouse events
- `handleKeyPress()` - Process keyboard input
- `mapToolSelection()` - Convert key to tool enum

**Event Flow:**
```
User Input → OS Event Queue → OpenCV Callback → Event Handler → Core Engine
```

---

### 2. Core Engine

**Responsibilities:**
- Drawing operations
- Tool implementations
- Algorithm execution

**Modules:**

#### Drawing Module
- Line rendering
- Shape primitives (rectangle, circle, ellipse)
- Freehand brush
- Spray paint algorithm
- Flood fill implementation

#### Tool Module
```cpp
class Tool {
public:
    virtual void onMouseDown(Point pos) = 0;
    virtual void onMouseMove(Point pos) = 0;
    virtual void onMouseUp(Point pos) = 0;
    virtual void render(Mat& canvas) = 0;
};
```

---

### 3. State Manager

**Responsibilities:**
- Application state persistence
- Undo/redo stack management
- Configuration management

**Data Structures:**
```cpp
struct ApplicationState {
    Mat canvas;                      // Current drawing
    std::stack<Mat> undoStack;       // Undo history
    std::stack<Mat> redoStack;       // Redo history
    Tool currentTool;                // Active tool
    Scalar currentColor;             // Active color
    int brushSize;                   // Brush radius
    Configuration config;            // Settings
};
```

**Memory Management:**
- Circular buffer for undo stack (max 20 levels)
- Automatic cleanup of excess history
- Efficient Mat cloning strategy

---

### 4. Video Capture

**Responsibilities:**
- Camera initialization
- Frame acquisition
- Resolution management
- FPS control

**Implementation:**
```cpp
class CameraManager {
private:
    VideoCapture capture;
    int deviceId;
    Size resolution;
    int fps;
    
public:
    bool initialize();
    bool getFrame(Mat& frame);
    void setResolution(Size res);
    void setFPS(int fps);
};
```

---

### 5. UI Renderer

**Responsibilities:**
- Color palette rendering
- Help overlay display
- Tool indicator rendering
- Status information display

**Rendering Pipeline:**
```
Camera Frame → Drawing Overlay → UI Elements → Display Buffer → Screen
```

**Layers:**
1. Background (camera feed)
2. Drawing canvas (transparent overlay)
3. UI elements (palette, indicators)
4. Help overlay (optional)

---

### 6. File Manager

**Responsibilities:**
- PNG export
- Configuration file I/O
- Directory management

**Export Pipeline:**
```
Canvas Mat → Format Conversion → Compression → File Write → Disk
```

---

## Data Flow

### Drawing Operation Flow

```
1. User clicks mouse
   ↓
2. OS generates event
   ↓
3. OpenCV callback triggered
   ↓
4. mouseCallback() processes event
   ↓
5. Determine current tool
   ↓
6. Execute tool-specific logic
   ↓
7. Update canvas Mat
   ↓
8. Save state to undo stack (if needed)
   ↓
9. Render updated canvas
   ↓
10. Display to screen
```

### Undo Operation Flow

```
1. User presses 'Z' key
   ↓
2. Check if undo stack has entries
   ↓
3. Save current state to redo stack
   ↓
4. Pop state from undo stack
   ↓
5. Restore canvas from popped state
   ↓
6. Render restored canvas
   ↓
7. Display to screen
```

---

## Performance Optimization

### Memory Management

**Strategies:**
- Use smart pointers for automatic resource management
- Implement Mat reference counting
- Limit undo stack depth
- Release unused memory promptly

**Memory Profile:**
```
Camera Frame:    640x480x3 = 921 KB
Drawing Canvas:  640x480x3 = 921 KB
Undo Stack:      20 x 921 KB = 18 MB (max)
Total:           ~20 MB
```

### Rendering Optimization

**Techniques:**
- Dirty region tracking
- Incremental updates
- GPU acceleration (optional)
- Anti-aliasing optimization

**Frame Time Budget (30 FPS):**
```
Total:           33.3 ms
- Camera capture: 5 ms
- Processing:    10 ms
- Rendering:     15 ms
- Display:       3 ms
```

---

## Threading Model

### Current Implementation: Single-Threaded

```
Main Thread:
- Camera capture
- Event processing
- Drawing operations
- Rendering
- Display updates
```

### Future: Multi-Threaded Design

```
Capture Thread:     Camera frame acquisition
Processing Thread:  Drawing operations
Render Thread:      UI rendering
Main Thread:        Event coordination
```

---

## Error Handling

### Error Categories

1. **Initialization Errors**
   - Camera not found
   - OpenCV initialization failure
   - Configuration file errors

2. **Runtime Errors**
   - Frame capture failure
   - Memory allocation failure
   - File I/O errors

3. **User Errors**
   - Invalid input
   - Out of bounds operations

### Error Handling Strategy

```cpp
ErrorCode processFrame() {
    try {
        Mat frame;
        if (!camera.read(frame)) {
            return ErrorCode::FRAME_CAPTURE_FAILED;
        }
        
        // Process frame
        
        return ErrorCode::SUCCESS;
        
    } catch (const cv::Exception& e) {
        logError(e.what());
        return ErrorCode::OPENCV_ERROR;
    } catch (const std::exception& e) {
        logError(e.what());
        return ErrorCode::UNKNOWN_ERROR;
    }
}
```

---

## Configuration Management

### Configuration File Structure

```json
{
  "camera": {
    "device_id": 0,
    "resolution": {"width": 640, "height": 480},
    "fps": 30
  },
  "drawing": {
    "default_tool": "brush",
    "default_brush_size": 3,
    "max_brush_size": 20,
    "default_color": [0, 0, 255]
  },
  "ui": {
    "show_help_on_startup": true,
    "show_color_palette": true,
    "palette_height": 40
  },
  "system": {
    "max_undo_levels": 20,
    "auto_save_interval": 300
  }
}
```

---

## Future Architecture Enhancements

### 1. Plugin System

```cpp
class IPlugin {
public:
    virtual bool initialize() = 0;
    virtual void process(Mat& canvas) = 0;
    virtual void cleanup() = 0;
};
```

### 2. Layer System

```cpp
class Layer {
    Mat content;
    float opacity;
    BlendMode mode;
    bool visible;
};

class LayerManager {
    std::vector<Layer> layers;
    int activeLayer;
};
```

### 3. Network Integration

```
Local Instance ↔ WebSocket Server ↔ Remote Instances
```

---

## Dependencies

### Core Dependencies

- **OpenCV 4.x**: Computer vision operations
- **C++ Standard Library**: Data structures and algorithms
- **CMake**: Build system

### Platform-Specific Dependencies

**Linux:**
- GCC 7+ or Clang 5+
- X11 (for display)
- Video4Linux2 (camera access)

**macOS:**
- Xcode Command Line Tools
- AVFoundation (camera access)

**Windows:**
- MSVC 2017+ or MinGW
- DirectShow (camera access)

---

## Build System

### CMake Configuration

```cmake
cmake_minimum_required(VERSION 3.10)
project(LiveDoodleOnCamera)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV 4 REQUIRED)

add_executable(live_doodle main_advanced.cpp)
target_link_libraries(live_doodle ${OpenCV_LIBS})
```

---

## Security Considerations

### Input Validation
- Bounds checking for coordinates
- Validation of brush size
- Sanitization of file paths

### Resource Limits
- Maximum canvas size
- Undo stack depth limit
- Frame rate limiting

---

Last Updated: December 2025
