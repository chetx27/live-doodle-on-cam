<div align="center">

# 🎨 Live Doodle on Camera

### *Transform Your Webcam into an Interactive Canvas*

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
[![OpenCV](https://img.shields.io/badge/OpenCV-4.x-blue.svg?logo=opencv)](https://opencv.org/)
[![C++](https://img.shields.io/badge/C++-17-00599C.svg?logo=c%2B%2B)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey.svg)](https://github.com/chetx27/live-doodle-on-cam)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](http://makeapullrequest.com)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/chetx27/live-doodle-on-cam)

[Features](#-features) •
[Demo](#-demo) •
[Installation](#-installation) •
[Usage](#-usage) •
[Documentation](#-documentation) •
[Contributing](#-contributing)

<img src="https://img.shields.io/github/stars/chetx27/live-doodle-on-cam?style=social" alt="GitHub stars">
<img src="https://img.shields.io/github/forks/chetx27/live-doodle-on-cam?style=social" alt="GitHub forks">
<img src="https://img.shields.io/github/watchers/chetx27/live-doodle-on-cam?style=social" alt="GitHub watchers">

---

**A powerful, real-time drawing application built with OpenCV and C++**  
*Perfect for presentations, tutorials, digital art, and learning computer vision*

</div>

---

## 💁 Table of Contents

- [✨ Features](#-features)
- [🎥 Demo](#-demo)
- [🚀 Quick Start](#-quick-start)
- [💻 Installation](#-installation)
- [🎮 Usage](#-usage)
- [📖 Documentation](#-documentation)
- [🏗️ Architecture](#%EF%B8%8F-architecture)
- [🛠️ Configuration](#%EF%B8%8F-configuration)
- [🎓 Learning](#-learning)
- [🤝 Contributing](#-contributing)
- [🐛 Troubleshooting](#-troubleshooting)
- [📊 Roadmap](#-roadmap)
- [📄 License](#-license)

---

## ✨ Features

<table>
<tr>
<td width="50%">

### 🖌️ **Drawing Tools**

- 🖌️ **Brush** - Smooth freehand drawing
- ✂️ **Eraser** - Remove unwanted strokes
- 📏 **Line** - Perfect straight lines
- ▭ **Rectangle** - Draw rectangles
- ◯ **Circle** - Create circles
- 🕸️ **Ellipse** - Elliptical shapes
- 🎨 **Spray Paint** - Artistic particle effects
- 🌈 **Fill Tool** - Flood fill areas

</td>
<td width="50%">

### 🎨 **Colors & Styling**

- 🎨 **10 Preset Colors** with visual palette
- 👆 **Click-to-Select** instant color switching
- 📍 **Adjustable Brush** (1-20px)
- ✨ **Anti-aliased** smooth rendering
- 🎯 **Real-time Preview** for shapes
- 🌈 **RGB Support** for custom colors

</td>
</tr>
<tr>
<td width="50%">

### 💾 **Advanced Features**

- ⏪ **Undo/Redo** (20 levels)
- 💾 **Save as PNG** with timestamps
- ⏱️ **Real-time Performance** (30+ FPS)
- 🧠 **Memory Efficient** auto-management
- 🎬 **Live Preview** overlay mode
- ⌨️ **Keyboard Shortcuts** for speed

</td>
<td width="50%">

### 🎯 **User Interface**

- 📊 **Interactive Palette** at screen top
- ❓ **Help Menu** toggle (H key)
- 📍 **Tool Indicator** shows current state
- ⚡ **Fast Tool Switching** (1-8 keys)
- 🔆 **Highlighted Selection** visual feedback
- 🎨 **Clean UI** minimal distraction

</td>
</tr>
</table>

---

## 🎥 Demo

<div align="center">

### 🎞️ **Application in Action**

<!-- Add demo GIF or video here -->
```
🎬 Coming Soon: Demo Video/GIF
```

### 📸 **Screenshots**

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

## 🚀 Quick Start

```bash
# Clone the repository
git clone https://github.com/chetx27/live-doodle-on-cam.git
cd live-doodle-on-cam

# Compile (Linux/macOS)
g++ -std=c++11 main_advanced.cpp -o live_doodle `pkg-config --cflags --libs opencv4`

# Run
./live_doodle
```

<div align="center">

**🎉 That's it! Start drawing on your webcam feed!**

</div>

---

## 💻 Installation

<details>
<summary><b>🐧 Linux (Ubuntu/Debian)</b></summary>
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

# Run
./live_doodle_advanced
```

</details>

<details>
<summary><b>🍎 macOS</b></summary>
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

# Run
./live_doodle_advanced
```

</details>

<details>
<summary><b>🪟 Windows</b></summary>
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

# Run
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

## 🎮 Usage

### ⏯️ **Controls Reference**

<table>
<tr>
<th>Category</th>
<th>Action</th>
<th>Key/Mouse</th>
<th>Description</th>
</tr>
<tr>
<td rowspan="3"><b>Drawing</b></td>
<td>Draw</td>
<td><kbd>Left Click</kbd> + <kbd>Drag</kbd></td>
<td>Draw with current tool</td>
</tr>
<tr>
<td>Brush Size</td>
<td><kbd>Mouse Wheel</kbd></td>
<td>Scroll up/down to adjust (1-20px)</td>
</tr>
<tr>
<td>Change Color</td>
<td><kbd>Click Palette</kbd></td>
<td>Click color bar at top of screen</td>
</tr>
<tr>
<td rowspan="8"><b>Tools</b></td>
<td>Brush</td>
<td><kbd>1</kbd></td>
<td>Freehand drawing tool</td>
</tr>
<tr>
<td>Eraser</td>
<td><kbd>2</kbd></td>
<td>Remove drawings</td>
</tr>
<tr>
<td>Line</td>
<td><kbd>3</kbd></td>
<td>Draw straight lines</td>
</tr>
<tr>
<td>Rectangle</td>
<td><kbd>4</kbd></td>
<td>Draw rectangles</td>
</tr>
<tr>
<td>Circle</td>
<td><kbd>5</kbd></td>
<td>Draw circles from center</td>
</tr>
<tr>
<td>Ellipse</td>
<td><kbd>6</kbd></td>
<td>Draw elliptical shapes</td>
</tr>
<tr>
<td>Spray</td>
<td><kbd>7</kbd></td>
<td>Spray paint effect</td>
</tr>
<tr>
<td>Fill</td>
<td><kbd>8</kbd></td>
<td>Flood fill enclosed areas</td>
</tr>
<tr>
<td rowspan="6"><b>Actions</b></td>
<td>Clear Canvas</td>
<td><kbd>C</kbd></td>
<td>Erase all drawings</td>
</tr>
<tr>
<td>Undo</td>
<td><kbd>Z</kbd></td>
<td>Undo last action (20 levels)</td>
</tr>
<tr>
<td>Redo</td>
<td><kbd>X</kbd></td>
<td>Redo undone action</td>
</tr>
<tr>
<td>Save</td>
<td><kbd>S</kbd></td>
<td>Save as PNG with timestamp</td>
</tr>
<tr>
<td>Toggle Help</td>
<td><kbd>H</kbd></td>
<td>Show/hide help overlay</td>
</tr>
<tr>
<td>Toggle Palette</td>
<td><kbd>P</kbd></td>
<td>Show/hide color palette</td>
</tr>
<tr>
<td rowspan="1"><b>System</b></td>
<td>Exit</td>
<td><kbd>ESC</kbd></td>
<td>Close application</td>
</tr>
</table>

### 📚 **Usage Tips**

<details>
<summary><b>🖌️ Shape Tools (Line, Rectangle, Circle, Ellipse)</b></summary>

1. Select tool with number keys (3-6)
2. Click and hold to set starting point
3. Drag mouse to desired size/position
4. Real-time preview shows shape while dragging
5. Release mouse button to finalize

**Pro Tip**: Hold <kbd>Shift</kbd> for perfect squares/circles (coming soon)

</details>

<details>
<summary><b>🌈 Fill Tool</b></summary>

1. Press <kbd>8</kbd> to select Fill tool
2. Choose desired color from palette
3. Click inside any enclosed area
4. Area fills with selected color

**Note**: Small gaps in boundaries may cause overflow

</details>

<details>
<summary><b>🎨 Spray Paint</b></summary>

1. Press <kbd>7</kbd> for Spray tool
2. Adjust brush size for spray radius
3. Click and drag slowly for dense coverage
4. Move faster for lighter, scattered effect

**Creative Uses**: Shading, textures, artistic effects

</details>

<details>
<summary><b>⏪ Undo/Redo System</b></summary>

- **Undo**: <kbd>Z</kbd> - Reverts last 20 actions
- **Redo**: <kbd>X</kbd> - Restores undone actions
- Redo stack clears when new action is performed
- Memory-efficient circular buffer

**Note**: Clear canvas (<kbd>C</kbd>) is also undoable

</details>

<details>
<summary><b>💾 Saving Drawings</b></summary>

1. Press <kbd>S</kbd> to save current drawing
2. File saved as `doodle_YYYYMMDD_HHMMSS.png`
3. Saved in current working directory
4. Contains only drawing layer (transparent background)
5. Compatible with image editors (Photoshop, GIMP, etc.)

**Pro Tip**: Create a `drawings/` folder for organization

</details>

### 🎯 **Use Cases**

| Use Case | Description | Best Tools |
|----------|-------------|------------|
| **🎬 Presentations** | Annotate slides and diagrams | Line, Rectangle, Brush |
| **🎨 Digital Art** | Create artwork on live video | Brush, Spray, Fill |
| **🏫 Teaching** | Explain concepts visually | All tools, Multiple colors |
| **👨‍💻 Tutorials** | Record annotated screencasts | Brush, Line, Eraser |
| **🎮 Gaming** | Add effects to streams | Spray, Circle, Custom colors |
| **📝 Note-taking** | Visual notes with webcam | Brush, Text (coming soon) |

---

## 📖 Documentation

### 🎯 **Project Structure**

```
live-doodle-on-cam/
│
├── main.cpp                 # Original basic version
├── main_advanced.cpp        # Enhanced version with all features
├── CMakeLists.txt           # Build configuration
├── config.json              # Configuration file
├── LICENSE                  # MIT License
├── README.md                # This file
├── .gitignore               # Git ignore rules
│
├── docs/                    # Documentation (coming soon)
│   ├── API.md
│   ├── CONTRIBUTING.md
│   └── CHANGELOG.md
│
└── examples/                # Example drawings (coming soon)
    ├── tutorial.png
    └── artwork.png
```

### 📚 **API Reference**

<details>
<summary><b>Core Functions</b></summary>

```cpp
// Mouse callback handler
void mouseCallback(int event, int x, int y, int flags, void* userdata);

// State management
void saveState();           // Save current state for undo
void undo();               // Undo last action
void redo();               // Redo undone action

// Drawing functions
void sprayPaint(Mat& img, Point center, Scalar color, int radius);
void floodFillTool(Mat& img, Point seed, Scalar newColor);

// UI rendering
void drawColorPalette(Mat& img);
void drawHelpText(Mat& img);

// File operations
void saveDrawing();        // Save as PNG with timestamp
```

</details>

---

## 🏗️ Architecture

### 💻 **Technology Stack**

<table>
<tr>
<td width="33%" align="center">
<b>C++17</b>
<br>Core Language
</td>
<td width="33%" align="center">
<b>OpenCV 4.x</b>
<br>Computer Vision
</td>
<td width="33%" align="center">
<b>CMake</b>
<br>Build System
</td>
</tr>
</table>

### 🧩 **Component Breakdown**

| Component | Responsibility | Key Technologies |
|-----------|----------------|------------------|
| **Video Capture** | Real-time camera input | OpenCV VideoCapture |
| **Drawing Engine** | Tool implementations | OpenCV drawing functions |
| **State Manager** | Undo/redo system | STL stack, Mat cloning |
| **UI Renderer** | Overlays and menus | OpenCV text & shapes |
| **Event Handler** | User input processing | OpenCV callbacks |
| **File Manager** | Save/export operations | OpenCV imwrite |

---

## 🛠️ Configuration

### ⚙️ **Camera Settings**

```cpp
// In main_advanced.cpp

// Change camera device (0 = default, 1 = second camera)
VideoCapture camera(0);

// Set resolution
camera.set(CAP_PROP_FRAME_WIDTH, 1280);    // Width in pixels
camera.set(CAP_PROP_FRAME_HEIGHT, 720);    // Height in pixels

// Set frame rate (if supported by camera)
camera.set(CAP_PROP_FPS, 30);
```

### 🎨 **Drawing Defaults**

```cpp
// Brush settings
int brushSize = 3;                          // 1-20 pixels
Scalar drawColor = Scalar(0, 0, 255);       // Red (BGR format)

// Undo settings
int maxUndoLevels = 20;                     // History depth

// UI settings
bool showHelp = true;                       // Show help at startup
bool showColorPalette = true;               // Show palette
```

### 📝 **config.json**

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

## 🎓 Learning

### 🎯 **What You'll Learn**

<table>
<tr>
<td width="50%">

#### **Computer Vision**
- ✅ Real-time video processing
- ✅ Frame manipulation & overlay
- ✅ Mouse event handling
- ✅ Drawing primitives
- ✅ Color space operations
- ✅ Image I/O operations

</td>
<td width="50%">

#### **C++ Programming**
- ✅ Modern C++ features
- ✅ STL containers (stack, vector)
- ✅ Event-driven architecture
- ✅ Memory management
- ✅ Object-oriented design
- ✅ Error handling

</td>
</tr>
<tr>
<td width="50%">

#### **Software Engineering**
- ✅ State management patterns
- ✅ Undo/redo implementation
- ✅ UI/UX design principles
- ✅ Modular code structure
- ✅ Performance optimization
- ✅ Cross-platform development

</td>
<td width="50%">

#### **Tools & Technologies**
- ✅ CMake build system
- ✅ Git version control
- ✅ OpenCV library
- ✅ Debugging techniques
- ✅ Documentation practices
- ✅ Package managers (vcpkg, brew)

</td>
</tr>
</table>

### 📚 **Recommended Reading**

- [OpenCV Documentation](https://docs.opencv.org/)
- [C++ Reference](https://en.cppreference.com/)
- [Modern C++ Best Practices](https://github.com/cpp-best-practices/cppbestpractices)
- [Computer Vision: Algorithms and Applications](http://szeliski.org/Book/)

---

## 🤝 Contributing

<div align="center">

**We love contributions! 🚀**

[![Contributors](https://img.shields.io/github/contributors/chetx27/live-doodle-on-cam.svg)](https://github.com/chetx27/live-doodle-on-cam/graphs/contributors)
[![Issues](https://img.shields.io/github/issues/chetx27/live-doodle-on-cam.svg)](https://github.com/chetx27/live-doodle-on-cam/issues)
[![Pull Requests](https://img.shields.io/github/issues-pr/chetx27/live-doodle-on-cam.svg)](https://github.com/chetx27/live-doodle-on-cam/pulls)

</div>

### 👥 **How to Contribute**

1. **🍴 Fork** the repository
2. **🌱 Create** your feature branch
   ```bash
   git checkout -b feature/AmazingFeature
   ```
3. **✨ Commit** your changes
   ```bash
   git commit -m 'Add some AmazingFeature'
   ```
4. **🚀 Push** to the branch
   ```bash
   git push origin feature/AmazingFeature
   ```
5. **🎉 Open** a Pull Request

### 💡 **Feature Ideas**

<details>
<summary><b>High Priority</b></summary>

- [ ] Hand gesture recognition (MediaPipe)
- [ ] Video recording functionality
- [ ] Text annotation tool
- [ ] Custom color picker (RGB/HSV)
- [ ] Layer system (multiple drawing layers)

</details>

<details>
<summary><b>Medium Priority</b></summary>

- [ ] Background blur/freeze option
- [ ] Brush texture patterns
- [ ] Polygon drawing tool
- [ ] Gradient fills
- [ ] Screenshot capture

</details>

<details>
<summary><b>Nice to Have</b></summary>

- [ ] Face filters/AR effects
- [ ] Touch/stylus support
- [ ] Collaborative drawing
- [ ] Mobile app version
- [ ] Plugin system

</details>

### 📜 **Code Style**

- Follow [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- Use meaningful variable names
- Comment complex logic
- Add documentation for public functions
- Write clean, readable code

---

## 🐛 Troubleshooting

<details>
<summary><b>❌ Camera Not Opening</b></summary>

**Error Message:**
```
Error: Cannot open camera. Check if it's connected.
```

**Solutions:**
1. Check physical camera connection
2. Try different camera index (0, 1, 2...)
3. Close other apps using camera (Zoom, Teams, etc.)
4. Check camera permissions:
   - **macOS**: System Preferences → Security & Privacy → Camera
   - **Linux**: `ls /dev/video*` to list cameras
   - **Windows**: Settings → Privacy → Camera
5. Verify camera works in other apps

</details>

<details>
<summary><b>❌ OpenCV Not Found</b></summary>

**Error Message:**
```
fatal error: opencv2/opencv.hpp: No such file or directory
```

**Solutions:**
1. **Linux**: Install with `sudo apt-get install libopencv-dev`
2. **macOS**: Install with `brew install opencv`
3. **Windows**: 
   - Use vcpkg: `vcpkg install opencv4:x64-windows`
   - Or download from [opencv.org](https://opencv.org/releases/)
4. Set environment variables:
   ```bash
   export PKG_CONFIG_PATH=/path/to/opencv/lib/pkgconfig
   ```
5. For CMake, set `OpenCV_DIR` to OpenCV installation

</details>

<details>
<summary><b>⚠️ Performance Issues</b></summary>

**Symptoms:**
- Low FPS (< 20)
- Laggy drawing
- Delayed response

**Solutions:**
1. **Reduce resolution**:
   ```cpp
   camera.set(CAP_PROP_FRAME_WIDTH, 320);
   camera.set(CAP_PROP_FRAME_HEIGHT, 240);
   ```
2. **Limit undo stack**: Change `maxUndoLevels` to 10
3. **Use release build**:
   ```bash
   cmake -DCMAKE_BUILD_TYPE=Release ..
   ```
4. **Close background apps**
5. **Update graphics drivers**

</details>

<details>
<summary><b>❌ Compilation Errors</b></summary>

**Common Issues:**

1. **C++11 not enabled**:
   ```bash
   g++ -std=c++11 main_advanced.cpp ...
   ```

2. **Missing libraries**:
   ```bash
   # Check OpenCV installation
   pkg-config --modversion opencv4
   
   # List required libraries
   pkg-config --libs opencv4
   ```

3. **Linker errors**: Add missing OpenCV modules
   ```bash
   -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_imgproc
   ```

</details>

---

## 📊 Roadmap

### 🔮 **Version 2.0** (Q1-Q2 2025)

- [ ] 👋 Hand tracking for touchless drawing (MediaPipe)
- [ ] 🎬 Video recording with audio commentary
- [ ] 💁 Face filters and AR effects
- [ ] 📂 Multiple layer support with blend modes
- [ ] 🎨 Custom brush textures and patterns
- [ ] ⚙️ Configuration file (JSON/YAML)
- [ ] 🖋️ Touch/stylus support for tablets

### 🚀 **Version 3.0** (Q3-Q4 2025)

- [ ] 🤖 AI-powered drawing assistance
- [ ] 🌍 Collaborative drawing over network
- [ ] 📏 3D doodles with depth mapping
- [ ] 📱 Mobile app version (OpenCV Android/iOS)
- [ ] ☁️ Cloud save and sync
- [ ] 🎮 Plugin/extension system

---

## 📄 License

<div align="center">

This project is licensed under the **MIT License**

See [LICENSE](LICENSE) file for details

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

</div>

---

## 👏 Acknowledgments

<div align="center">

**Special Thanks To:**

🙏 OpenCV Community | 📚 Open Source Contributors | 🎓 Computer Vision Researchers

---

### 👨‍💻 Author

**Chethana G (Chet)**

[![GitHub](https://img.shields.io/badge/GitHub-chetx27-181717?logo=github)](https://github.com/chetx27)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0077B5?logo=linkedin)](https://linkedin.com/in/chetx27)

---

### 📊 Project Stats

![Code Size](https://img.shields.io/github/languages/code-size/chetx27/live-doodle-on-cam)
![Repo Size](https://img.shields.io/github/repo-size/chetx27/live-doodle-on-cam)
![Last Commit](https://img.shields.io/github/last-commit/chetx27/live-doodle-on-cam)

**Lines of Code**: 500+ | **Features**: 15+ | **OpenCV Functions**: 20+

---

<h3>If you find this project helpful, please consider:</h3>

⭐ **Starring the repository**  
👁️ **Watching for updates**  
🍴 **Forking for your own use**  
💬 **Sharing with others**  

---

**Made with ❤️ and OpenCV**

🚀 **Happy Doodling!**

</div>
