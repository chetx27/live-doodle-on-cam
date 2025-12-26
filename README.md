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

<img src="https://img.shields.io/github/stars/chetx27/live-doodle-on-cam?style=social" alt="GitHub stars">
<img src="https://img.shields.io/github/forks/chetx27/live-doodle-on-cam?style=social" alt="GitHub forks">
<img src="https://img.shields.io/github/watchers/chetx27/live-doodle-on-cam?style=social" alt="GitHub watchers">

---

**A powerful, real-time drawing application built with OpenCV and C++**  
*Perfect for presentations, tutorials, digital art, and learning computer vision*

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
| **Clear** | C | Clear all drawings |
| **Undo** | Z | Undo last action |
| **Redo** | X | Redo undone action |
| **Save** | S | Save as PNG with timestamp |
| **Help** | H | Toggle help menu |
| **Exit** | ESC | Close application |

### **Tool Selection**

| Key | Tool | Key | Tool |
|-----|------|-----|------|
| **1** | Brush | **5** | Circle |
| **2** | Eraser | **6** | Ellipse |
| **3** | Line | **7** | Spray Paint |
| **4** | Rectangle | **8** | Fill Tool |

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

- **C++17** - Core programming language
- **OpenCV 4.x** - Computer vision library
- **CMake** - Cross-platform build system

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

### **Drawing Defaults**

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

---

## 📄 License

<div align="center">

This project is licensed under the **MIT License**

See [LICENSE](LICENSE) file for details

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

</div>

---

<div align="center">

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

⭐ **If you find this project helpful, please star the repository!**

**Made with ❤️ and OpenCV**

🚀 **Happy Doodling!**

</div>
