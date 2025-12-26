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
[Configuration](#-configuration) •
[Contributing](#-contributing)

![GitHub Stars](https://img.shields.io/github/stars/chetx27/live-doodle-on-cam?style=social)
![GitHub Forks](https://img.shields.io/github/forks/chetx27/live-doodle-on-cam?style=social)
![GitHub Watchers](https://img.shields.io/github/watchers/chetx27/live-doodle-on-cam?style=social)

---

**A powerful, real-time drawing application built with OpenCV and C++**  
*Perfect for presentations, tutorials, digital art, and learning computer vision*

### 🌟 Quick Highlights

🖌️ **8 Drawing Tools** | 🎨 **10 Colors** | ⏪ **Undo/Redo** | 💾 **Save PNG** | ⚡ **30+ FPS** | 👌 **Easy to Use**

</div>

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

### **Basic Controls**

| Action | Key/Mouse | Description |
|--------|-----------|-------------|
| **Draw** | Left Click + Drag | Draw with current tool |
| **Brush Size** | Mouse Wheel | Scroll up/down (1-20px) |
| **Change Color** | Click Palette | Select color at top of screen |
| **Clear** | <kbd>C</kbd> | Clear all drawings |
| **Undo** | <kbd>Z</kbd> | Undo last action |
| **Redo** | <kbd>X</kbd> | Redo undone action |
| **Save** | <kbd>S</kbd> | Save as PNG with timestamp |
| **Help** | <kbd>H</kbd> | Toggle help menu |
| **Exit** | <kbd>ESC</kbd> | Close application |

### **Tool Selection**

| Key | Tool | Key | Tool |
|-----|------|-----|------|
| <kbd>1</kbd> | Brush | <kbd>5</kbd> | Circle |
| <kbd>2</kbd> | Eraser | <kbd>6</kbd> | Ellipse |
| <kbd>3</kbd> | Line | <kbd>7</kbd> | Spray Paint |
| <kbd>4</kbd> | Rectangle | <kbd>8</kbd> | Fill Tool |

---

## 📖 Documentation

### **Project Structure**

```
live-doodle-on-cam/
│
├── main.cpp                 # Original basic version
├── main_advanced.cpp        # Enhanced version with all features
├── CMakeLists.txt           # Build configuration
├── config.json              # Configuration file
├── LICENSE                  # MIT License
├── README.md                # This file
└── .gitignore               # Git ignore rules
```

### **API Reference**

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

### **Technology Stack**

<div align="center">

| Technology | Purpose | Version |
|------------|---------|----------|
| **C++** | Core Language | C++17 |
| **OpenCV** | Computer Vision | 4.x |
| **CMake** | Build System | 3.10+ |
| **STL** | Data Structures | Standard |

</div>

### **Component Breakdown**

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

### **Camera Settings**

Customize camera parameters in `main_advanced.cpp`:

```cpp
// Change camera device (0 = default, 1 = second camera)
VideoCapture camera(0);

// Set resolution
camera.set(CAP_PROP_FRAME_WIDTH, 1280);    // Default: 640
camera.set(CAP_PROP_FRAME_HEIGHT, 720);    // Default: 480

// Set frame rate (if supported by camera)
camera.set(CAP_PROP_FPS, 30);
```

### **Drawing Defaults**

Adjust default drawing parameters:

```cpp
// Brush settings
int brushSize = 3;                          // Range: 1-20 pixels
Scalar drawColor = Scalar(0, 0, 255);       // Default: Red (BGR)

// Undo settings
int maxUndoLevels = 20;                     // History depth

// UI settings
bool showHelp = true;                       // Show help at startup
bool showColorPalette = true;               // Show color palette
```

---

## 🤝 Contributing

<div align="center">

**We love contributions! 🚀**

[![Contributors](https://img.shields.io/github/contributors/chetx27/live-doodle-on-cam.svg)](https://github.com/chetx27/live-doodle-on-cam/graphs/contributors)
[![Issues](https://img.shields.io/github/issues/chetx27/live-doodle-on-cam.svg)](https://github.com/chetx27/live-doodle-on-cam/issues)
[![Pull Requests](https://img.shields.io/github/issues-pr/chetx27/live-doodle-on-cam.svg)](https://github.com/chetx27/live-doodle-on-cam/pulls)

</div>

### **How to Contribute**

1. **🍴 Fork** the repository
2. **🌱 Create** your feature branch (`git checkout -b feature/AmazingFeature`)
3. **✨ Commit** your changes (`git commit -m 'Add some AmazingFeature'`)
4. **🚀 Push** to the branch (`git push origin feature/AmazingFeature`)
5. **🎉 Open** a Pull Request

### **Feature Ideas**

Want to contribute? Here are some ideas:

- 👋 Hand gesture recognition (MediaPipe)
- 🎬 Video recording functionality
- 📝 Text annotation tool
- 🎨 Custom color picker with RGB sliders
- 📂 Multiple layer support
- 🌐 Background blur/freeze option
- 🖼️ Brush texture patterns

---

## 🐛 Known Issues

- **Camera Compatibility**: Some USB cameras may require different device indices
- **Performance**: High resolutions (>1080p) may impact FPS on older hardware
- **Windows**: Path spaces in OpenCV installation can cause compilation issues

**Found a bug?** [Open an issue](https://github.com/chetx27/live-doodle-on-cam/issues) →

---

## 📄 License

<div align="center">

This project is licensed under the **MIT License**

See [LICENSE](LICENSE) file for details

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

</div>

---

<div align="center">

## 👨‍💻 Author

**Chethana G (Chet)**

[![GitHub](https://img.shields.io/badge/GitHub-chetx27-181717?logo=github)](https://github.com/chetx27)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0077B5?logo=linkedin)](https://linkedin.com/in/chetx27)
[![Email](https://img.shields.io/badge/Email-Contact-red?logo=gmail)](mailto:chethana.workspace@gmail.com)

---

## 📊 Project Stats

![GitHub Language](https://img.shields.io/github/languages/top/chetx27/live-doodle-on-cam)
![Code Size](https://img.shields.io/github/languages/code-size/chetx27/live-doodle-on-cam)
![Repo Size](https://img.shields.io/github/repo-size/chetx27/live-doodle-on-cam)
![Last Commit](https://img.shields.io/github/last-commit/chetx27/live-doodle-on-cam)
![GitHub Issues](https://img.shields.io/github/issues/chetx27/live-doodle-on-cam)

**Lines of Code**: 500+ | **Drawing Tools**: 8 | **Colors**: 10 | **Undo Levels**: 20

---

### 🌟 Show Your Support

**If you find this project helpful:**

⭐ **Star this repository**  
👁️ **Watch for updates**  
🍴 **Fork for your own projects**  
💬 **Share with others**  
🐛 **Report issues**  
💡 **Suggest features**

---

<h3>Built for learners, creators, and innovators</h3>

**Made with ❤️ and OpenCV**

🚀 **Happy Doodling!**

---

*© 2025 Chethana G. All rights reserved.*

</div>
