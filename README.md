<div align="center">

# Live Doodle on Camera

### Real-Time Computer Vision Drawing Application

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
[![OpenCV](https://img.shields.io/badge/OpenCV-4.x-blue.svg?logo=opencv)](https://opencv.org/)
[![C++](https://img.shields.io/badge/C++-17-00599C.svg?logo=c%2B%2B)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey.svg)](https://github.com/chetx27/live-doodle-on-cam)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](http://makeapullrequest.com)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/chetx27/live-doodle-on-cam)

[Features](#features) •
[Installation](#installation) •
[Usage](#usage) •
[Architecture](#architecture) •
[Configuration](#configuration) •
[Contributing](#contributing)

![GitHub Stars](https://img.shields.io/github/stars/chetx27/live-doodle-on-cam?style=social)
![GitHub Forks](https://img.shields.io/github/forks/chetx27/live-doodle-on-cam?style=social)
![GitHub Watchers](https://img.shields.io/github/watchers/chetx27/live-doodle-on-cam?style=social)

---

**Enterprise-grade real-time drawing application leveraging OpenCV and modern C++**  
*Optimized for presentations, educational content, digital art creation, and computer vision research*

### Technical Specifications

**8 Drawing Tools** | **10 Color Presets** | **20-Level History** | **PNG Export** | **30+ FPS Performance** | **Cross-Platform**

</div>

---

## Features

<table>
<tr>
<td width="50%">

### Drawing Tools

- **Brush** - Freehand vector drawing with anti-aliasing
- **Eraser** - Selective stroke removal
- **Line** - Precise straight line rendering
- **Rectangle** - Rectangular shape primitive
- **Circle** - Circular shape primitive
- **Ellipse** - Elliptical shape primitive
- **Spray** - Particle-based spray paint effect
- **Fill** - Flood fill algorithm implementation

</td>
<td width="50%">

### Color Management

- **10 Preset Colors** - Predefined color palette
- **Click Selection** - Instant color switching interface
- **Dynamic Sizing** - 1-20 pixel brush adjustment
- **Anti-aliasing** - Smooth edge rendering
- **Real-time Preview** - Live shape visualization
- **RGB Support** - Full color spectrum access

</td>
</tr>
<tr>
<td width="50%">

### Advanced Capabilities

- **Undo/Redo** - 20-level action history
- **PNG Export** - Timestamped file output
- **Performance** - Consistent 30+ FPS rendering
- **Memory Management** - Optimized resource utilization
- **Live Overlay** - Non-destructive preview mode
- **Hotkeys** - Keyboard shortcut support

</td>
<td width="50%">

### User Interface

- **Interactive Palette** - Top-aligned color selector
- **Help System** - Contextual assistance (H key)
- **Status Indicators** - Active tool visualization
- **Fast Switching** - Single-key tool selection
- **Visual Feedback** - Selection highlighting
- **Minimal UI** - Distraction-free workspace

</td>
</tr>
</table>

---

## Demo

<div align="center">

### Application Preview

```
Demo Video/GIF - Coming Soon
```

### Screenshots

<table>
  <tr>
    <td align="center">
      <img src="https://via.placeholder.com/300x200/1e1e1e/00ff00?text=Drawing+Mode" alt="Drawing Mode" width="300"/>
      <br />
      <b>Drawing Mode</b>
    </td>
    <td align="center">
      <img src="https://via.placeholder.com/300x200/1e1e1e/ff0000?text=Shape+Tools" alt="Shape Tools" width="300"/>
      <br />
      <b>Shape Tools</b>
    </td>
    <td align="center">
      <img src="https://via.placeholder.com/300x200/1e1e1e/0099ff?text=Color+Palette" alt="Color Palette" width="300"/>
      <br />
      <b>Color Palette</b>
    </td>
  </tr>
</table>

</div>

---

## Quick Start

```bash
# Clone the repository
git clone https://github.com/chetx27/live-doodle-on-cam.git
cd live-doodle-on-cam

# Compile (Linux/macOS)
g++ -std=c++11 main_advanced.cpp -o live_doodle `pkg-config --cflags --libs opencv4`

# Execute
./live_doodle
```

<div align="center">

**Application ready for deployment**

</div>

---

## Installation

<details>
<summary><b>Linux (Ubuntu/Debian)</b></summary>
<br>

```bash
# Install dependencies
sudo apt-get update
sudo apt-get install -y build-essential cmake
sudo apt-get install -y libopencv-dev

# Clone repository
git clone https://github.com/chetx27/live-doodle-on-cam.git
cd live-doodle-on-cam

# Build with CMake
mkdir build && cd build
cmake ..
make

# Execute
./live_doodle_advanced
```

</details>

<details>
<summary><b>macOS</b></summary>
<br>

```bash
# Install Homebrew (if not installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install dependencies
brew install cmake
brew install opencv

# Clone repository
git clone https://github.com/chetx27/live-doodle-on-cam.git
cd live-doodle-on-cam

# Compile
g++ -std=c++11 main_advanced.cpp -o live_doodle_advanced \
    `pkg-config --cflags --libs opencv4`

# Execute
./live_doodle_advanced
```

</details>

<details>
<summary><b>Windows</b></summary>
<br>

### Option 1: Using vcpkg (Recommended)

```powershell
# Install vcpkg
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat

# Install OpenCV
.\vcpkg install opencv4:x64-windows

# Clone repository
git clone https://github.com/chetx27/live-doodle-on-cam.git
cd live-doodle-on-cam

# Build with CMake
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[vcpkg root]/scripts/buildsystems/vcpkg.cmake
cmake --build .

# Execute
.\Debug\live_doodle_advanced.exe
```

### Option 2: Pre-built OpenCV

1. Download OpenCV from [opencv.org](https://opencv.org/releases/)
2. Extract to `C:\opencv`
3. Compile:

```cmd
g++ main_advanced.cpp -o live_doodle_advanced.exe ^
    -IC:\opencv\build\include ^
    -LC:\opencv\build\x64\vc15\lib ^
    -lopencv_world480
```

</details>

---

## Usage

### Control Reference

| Action | Input | Description |
|--------|-------|-------------|
| **Draw** | Left Click + Drag | Activate current drawing tool |
| **Brush Size** | Mouse Wheel | Adjust brush radius (1-20px) |
| **Color Selection** | Click Palette | Select color from top bar |
| **Clear Canvas** | <kbd>C</kbd> | Reset drawing surface |
| **Undo** | <kbd>Z</kbd> | Revert last action |
| **Redo** | <kbd>X</kbd> | Restore undone action |
| **Export** | <kbd>S</kbd> | Save as timestamped PNG |
| **Help** | <kbd>H</kbd> | Toggle help overlay |
| **Exit** | <kbd>ESC</kbd> | Terminate application |

### Tool Selection Mapping

| Key | Tool | Key | Tool |
|-----|------|-----|------|
| <kbd>1</kbd> | Brush | <kbd>5</kbd> | Circle |
| <kbd>2</kbd> | Eraser | <kbd>6</kbd> | Ellipse |
| <kbd>3</kbd> | Line | <kbd>7</kbd> | Spray |
| <kbd>4</kbd> | Rectangle | <kbd>8</kbd> | Fill |

---

## Documentation

### Project Structure

```
live-doodle-on-cam/
│
├── main.cpp                 # Original implementation
├── main_advanced.cpp        # Enhanced implementation
├── CMakeLists.txt           # Build configuration
├── config.json              # Runtime configuration
├── LICENSE                  # MIT License
├── README.md                # Documentation
└── .gitignore               # Version control exclusions
```

### API Reference

<details>
<summary><b>Core Functions</b></summary>

```cpp
// Event handling
void mouseCallback(int event, int x, int y, int flags, void* userdata);

// State management
void saveState();           // Save current canvas state
void undo();               // Revert to previous state
void redo();               // Restore undone state

// Drawing operations
void sprayPaint(Mat& img, Point center, Scalar color, int radius);
void floodFillTool(Mat& img, Point seed, Scalar newColor);

// UI rendering
void drawColorPalette(Mat& img);
void drawHelpText(Mat& img);

// File operations
void saveDrawing();        // Export as PNG
```

</details>

---

## Architecture

### Technology Stack

<div align="center">

| Technology | Purpose | Version |
|------------|---------|----------|
| **C++** | Core Language | C++17 |
| **OpenCV** | Computer Vision Framework | 4.x |
| **CMake** | Build Automation | 3.10+ |
| **STL** | Standard Library | C++17 |

</div>

### System Components

| Component | Responsibility | Implementation |
|-----------|----------------|----------------|
| **Video Capture** | Real-time camera input | OpenCV VideoCapture API |
| **Drawing Engine** | Tool rendering pipeline | OpenCV drawing primitives |
| **State Manager** | History management | STL stack with Mat cloning |
| **UI Renderer** | Interface overlay system | OpenCV text and shapes |
| **Event Handler** | Input processing | OpenCV callback system |
| **File Manager** | Export operations | OpenCV imwrite API |

---

## Configuration

### Camera Settings

Modify camera parameters in `main_advanced.cpp`:

```cpp
// Camera device selection (0 = default, 1+ = additional devices)
VideoCapture camera(0);

// Resolution configuration
camera.set(CAP_PROP_FRAME_WIDTH, 1280);    // Default: 640
camera.set(CAP_PROP_FRAME_HEIGHT, 720);    // Default: 480

// Frame rate configuration
camera.set(CAP_PROP_FPS, 30);
```

### Drawing Parameters

Adjust default drawing settings:

```cpp
// Brush configuration
int brushSize = 3;                          // Range: 1-20 pixels
Scalar drawColor = Scalar(0, 0, 255);       // BGR format (Red)

// History configuration
int maxUndoLevels = 20;                     // Stack depth

// UI configuration
bool showHelp = true;                       // Initial help state
bool showColorPalette = true;               // Palette visibility
```

### Runtime Configuration

Use `config.json` for persistent settings:

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
    "max_brush_size": 20
  },
  "ui": {
    "show_help_on_startup": true,
    "show_color_palette": true
  }
}
```

---

## Contributing

<div align="center">

**Contributions Welcome**

[![Contributors](https://img.shields.io/github/contributors/chetx27/live-doodle-on-cam.svg)](https://github.com/chetx27/live-doodle-on-cam/graphs/contributors)
[![Issues](https://img.shields.io/github/issues/chetx27/live-doodle-on-cam.svg)](https://github.com/chetx27/live-doodle-on-cam/issues)
[![Pull Requests](https://img.shields.io/github/issues-pr/chetx27/live-doodle-on-cam.svg)](https://github.com/chetx27/live-doodle-on-cam/pulls)

</div>

### Contribution Workflow

1. **Fork** the repository
2. **Create** feature branch (`git checkout -b feature/Enhancement`)
3. **Commit** changes (`git commit -m 'Add Enhancement'`)
4. **Push** to branch (`git push origin feature/Enhancement`)
5. **Submit** Pull Request

### Development Roadmap

Priority enhancement opportunities:

- **Hand Tracking** - MediaPipe integration for gesture control
- **Video Recording** - Screen capture with audio support
- **Text Annotation** - Font rendering and text tool
- **Advanced Color Picker** - HSV color space interface
- **Layer System** - Multi-layer composition support
- **Background Processing** - Blur and freeze capabilities
- **Texture Support** - Custom brush patterns

### Code Standards

- Adhere to [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- Use descriptive variable naming conventions
- Document complex algorithmic implementations
- Provide API documentation for public interfaces
- Maintain code readability and modularity

---

## Known Issues

- **Camera Compatibility** - USB camera device index may vary by system
- **Performance** - Resolution >1080p may reduce FPS on legacy hardware
- **Windows Path Handling** - Spaces in OpenCV installation path can cause build failures

**Issue Reporting** - [GitHub Issues](https://github.com/chetx27/live-doodle-on-cam/issues)

---

## License

<div align="center">

Licensed under the **MIT License**

See [LICENSE](LICENSE) for complete terms

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

</div>

---

<div align="center">

## Author

**Chethana G**

Software Engineer | Computer Vision Developer

[![GitHub](https://img.shields.io/badge/GitHub-chetx27-181717?logo=github)](https://github.com/chetx27)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0077B5?logo=linkedin)](https://linkedin.com/in/chetx27)
[![Email](https://img.shields.io/badge/Email-Contact-red?logo=gmail)](mailto:chethana.workspace@gmail.com)

---

## Project Metrics

![GitHub Language](https://img.shields.io/github/languages/top/chetx27/live-doodle-on-cam)
![Code Size](https://img.shields.io/github/languages/code-size/chetx27/live-doodle-on-cam)
![Repository Size](https://img.shields.io/github/repo-size/chetx27/live-doodle-on-cam)
![Last Commit](https://img.shields.io/github/last-commit/chetx27/live-doodle-on-cam)
![Open Issues](https://img.shields.io/github/issues/chetx27/live-doodle-on-cam)

**Codebase** - 500+ LOC | **Tools** - 8 | **Color Palette** - 10 | **History Depth** - 20

---

### Support This Project

**Star** the repository | **Watch** for updates | **Fork** for development | **Share** with community

---

**Engineered for performance and reliability**

*Copyright © 2025 Chethana G. All rights reserved.*

</div>
