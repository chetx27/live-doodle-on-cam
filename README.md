# 🎨 Live Doodle on Camera - Advanced Edition

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![OpenCV](https://img.shields.io/badge/OpenCV-4.x-blue.svg)](https://opencv.org/)
[![C++](https://img.shields.io/badge/C++-17-green.svg)](https://isocpp.org/)

An advanced real-time drawing application that lets you doodle on your webcam feed using OpenCV and C++. Perfect for learning computer vision, creating fun videos, or interactive presentations!

![Demo](https://img.shields.io/badge/Status-Active-success)

## ✨ Features

### 🖌️ Drawing Tools
- **Brush Tool**: Smooth freehand drawing with adjustable size
- **Eraser Tool**: Remove unwanted drawings
- **Line Tool**: Draw straight lines between two points
- **Rectangle Tool**: Create rectangular shapes
- **Circle Tool**: Draw circles from center point
- **Ellipse Tool**: Create elliptical shapes
- **Spray Paint**: Artistic spray paint effect
- **Fill Tool**: Flood fill enclosed areas with color

### 🎨 Color & Styling
- **10 Preset Colors**: Red, Green, Blue, Yellow, Magenta, Cyan, White, Gray, Orange, Pink
- **Interactive Color Palette**: Click to select colors instantly
- **Adjustable Brush Size**: Use mouse wheel to change (1-20px)
- **Smooth Anti-aliased Lines**: Professional-quality rendering

### 💾 Advanced Features
- **Undo/Redo**: Up to 20 levels of undo history (Z/X keys)
- **Save Drawings**: Export your artwork as PNG with timestamp
- **Real-time Preview**: Live camera feed with drawing overlay
- **Toggle UI Elements**: Show/hide help menu and color palette
- **Memory Efficient**: Automatic history management

### 🎯 User Interface
- **Interactive Color Palette**: Visual color selection at top of screen
- **Comprehensive Help Menu**: Toggle with 'H' key
- **Tool Indicator**: Shows current tool and brush size
- **Keyboard Shortcuts**: Fast tool switching with number keys
- **Highlighted Selection**: Current color outlined in palette

## 🚀 Getting Started

### Prerequisites

- **C++ Compiler** (C++11 or higher)
  - GCC 7.0+
  - Clang 5.0+
  - MSVC 2017+
  - Or any C++11 compliant compiler

- **OpenCV 4.x**
  ```bash
  # Ubuntu/Debian
  sudo apt-get install libopencv-dev
  
  # macOS (using Homebrew)
  brew install opencv
  
  # Windows (using vcpkg)
  vcpkg install opencv4
  ```

- **CMake 3.10+** (optional, for build automation)
  ```bash
  # Ubuntu/Debian
  sudo apt-get install cmake
  
  # macOS
  brew install cmake
  ```

- **Webcam** connected to your system

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/chetx27/live-doodle-on-cam.git
   cd live-doodle-on-cam
   ```

2. **Build using CMake (Recommended)**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./live_doodle_advanced
   ```

3. **Or compile directly**
   ```bash
   # Linux/macOS
   g++ -std=c++11 main_advanced.cpp -o live_doodle_advanced `pkg-config --cflags --libs opencv4`
   
   # Run
   ./live_doodle_advanced
   ```

   ```bash
   # Windows (adjust paths as needed)
   g++ main_advanced.cpp -o live_doodle_advanced.exe -I"C:/opencv/include" -L"C:/opencv/lib" -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_imgproc
   ```

## 📖 Usage Guide

### Basic Controls

| Action | Key/Mouse | Description |
|--------|-----------|-------------|
| **Draw** | Left Click + Drag | Draw with current tool |
| **Change Color** | Click Palette | Select from 10 colors |
| **Brush Size** | Scroll Wheel | Increase/decrease size (1-20px) |
| **Clear** | C | Clear entire canvas |
| **Save** | S | Save drawing as PNG file |
| **Undo** | Z | Undo last action |
| **Redo** | X | Redo undone action |
| **Help Menu** | H | Toggle help overlay |
| **Color Palette** | P | Toggle color palette |
| **Exit** | ESC | Close application |

### Tool Selection

| Key | Tool | Description |
|-----|------|-------------|
| **1** | Brush | Freehand drawing |
| **2** | Eraser | Remove drawings |
| **3** | Line | Draw straight lines |
| **4** | Rectangle | Draw rectangles |
| **5** | Circle | Draw circles |
| **6** | Ellipse | Draw ellipses |
| **7** | Spray | Spray paint effect |
| **8** | Fill | Flood fill areas |

### Tips & Tricks

💡 **Shape Tools (Line, Rectangle, Circle, Ellipse)**
- Click and hold to set starting point
- Drag to desired size/position
- Release to finalize shape
- Preview shows in real-time while dragging

💡 **Fill Tool**
- Click on any enclosed area to fill with current color
- Works best with complete shapes
- Small gaps may cause overflow

💡 **Spray Paint**
- Creates artistic, scattered particle effect
- Move mouse slowly for denser coverage
- Adjust brush size for different spray patterns

💡 **Undo/Redo**
- Supports up to 20 undo levels
- Redo stack clears when new action is performed
- Memory-efficient circular buffer

💡 **Saving Drawings**
- Files saved with timestamp: `doodle_YYYYMMDD_HHMMSS.png`
- Saved in current directory
- Transparent background (drawing layer only)

## 🎥 Demo

### Sample Workflows

**1. Creating Annotated Videos**
```
1. Start the application
2. Press H to hide help menu
3. Draw annotations on camera feed
4. Press S to save important frames
5. Use different colors for emphasis
```

**2. Digital Art Creation**
```
1. Use Circle (5) and Rectangle (4) for structure
2. Switch to Brush (1) for details
3. Apply Spray (7) for shading effects
4. Use Fill (8) to add colors
5. Save final artwork with S
```

**3. Interactive Presentations**
```
1. Position yourself in frame
2. Draw diagrams or highlight points
3. Use Eraser (2) to correct mistakes
4. Clear (C) between topics
5. Multiple colors for organization
```

## 🏗️ Architecture

### Core Components

```
main_advanced.cpp
├── Drawing Engine
│   ├── Mouse callback handler
│   ├── Tool implementations
│   └── Real-time preview
├── State Management
│   ├── Undo/Redo stacks
│   └── History management
├── UI Rendering
│   ├── Color palette
│   ├── Help overlay
│   └── Tool indicators
└── File I/O
    └── PNG export with timestamps
```

### Key Technologies

- **OpenCV VideoCapture**: Real-time camera input
- **OpenCV Drawing Functions**: Line, circle, rectangle, ellipse
- **OpenCV FloodFill**: Fill tool implementation
- **STL Stack**: Undo/redo state management
- **Random Library**: Spray paint particle generation

## 🔧 Configuration

### Camera Settings

Modify in `main_advanced.cpp`:
```cpp
// Change camera resolution
camera.set(CAP_PROP_FRAME_WIDTH, 1280);   // Default: 640
camera.set(CAP_PROP_FRAME_HEIGHT, 720);   // Default: 480

// Change camera device
VideoCapture camera(1);  // 0 = default, 1 = second camera
```

### Default Values

```cpp
// Brush settings
int brushSize = 3;              // 1-20 pixels
Scalar drawColor = Scalar(0, 0, 255);  // Red (BGR)

// Undo history
int maxUndoLevels = 20;         // Maximum undo states

// UI display
bool showHelp = true;           // Show help at startup
bool showColorPalette = true;   // Show color palette
```

## 🎓 Learning Objectives

This project is perfect for learning:

### Computer Vision Concepts
- ✅ Real-time video capture and processing
- ✅ Frame overlay and alpha blending
- ✅ Mouse event handling in CV applications
- ✅ Drawing primitives and rendering

### C++ Programming
- ✅ Object-oriented design patterns
- ✅ STL containers (stack, vector)
- ✅ Event-driven programming
- ✅ File I/O operations

### Software Engineering
- ✅ State management (undo/redo)
- ✅ Memory optimization
- ✅ User interface design
- ✅ Modular code architecture

## 🤝 Contributing

Contributions are welcome! Here are some ideas:

### Feature Requests
- [ ] Hand gesture recognition for touchless drawing
- [ ] Video recording of drawing sessions
- [ ] Multiple layer support
- [ ] Custom color picker with RGB sliders
- [ ] Background blur/freeze option
- [ ] Brush texture patterns
- [ ] Polygon drawing tool
- [ ] Text annotation tool

### How to Contribute

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 🐛 Troubleshooting

### Camera Not Opening
```
Error: Cannot open camera
```
**Solution**: 
- Check camera connection
- Try different camera index (0, 1, 2...)
- Verify camera permissions (especially on macOS/Linux)
- Close other apps using the camera

### OpenCV Not Found
```
fatal error: opencv2/opencv.hpp: No such file or directory
```
**Solution**:
- Install OpenCV development packages
- Set PKG_CONFIG_PATH environment variable
- For CMake: Set OpenCV_DIR to OpenCV installation

### Drawing Lag
**Solution**:
- Reduce camera resolution
- Limit undo stack size
- Use release build instead of debug

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Chet** - [@chetx27](https://github.com/chetx27)

## 🌟 Acknowledgments

- OpenCV community for excellent documentation
- Computer vision tutorials and resources
- All contributors and users of this project

## 📊 Project Stats

- **Lines of Code**: ~500+
- **Features**: 15+ tools and functions
- **OpenCV Functions Used**: 20+
- **Supported Platforms**: Windows, macOS, Linux

## 🔮 Future Roadmap

### Version 2.0 (Planned)
- [ ] Hand tracking for gesture-based drawing
- [ ] Face filters and AR effects
- [ ] Video recording functionality
- [ ] Multi-layer support
- [ ] Custom brush textures
- [ ] Configuration file for settings
- [ ] Touch/stylus support for tablets

### Version 3.0 (Vision)
- [ ] AI-powered drawing assistance
- [ ] Collaborative drawing over network
- [ ] 3D doodles with depth mapping
- [ ] Mobile app version (OpenCV Android)

---

⭐ **If you find this project helpful, please consider giving it a star!**

📧 **Questions or suggestions?** Open an issue or reach out!

🚀 **Happy Doodling!**
