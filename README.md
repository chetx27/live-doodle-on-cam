# Live Doodle on Camera

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![OpenCV](https://img.shields.io/badge/OpenCV-4.x-green.svg)](https://opencv.org/)
[![C++17](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg)](https://github.com/chetx27/live-doodle-on-cam)

Real-time computer vision drawing application built with OpenCV and modern C++.

## Overview

Live Doodle on Camera is a high-performance drawing application that overlays vector graphics on live camera feeds. Designed for presentations, education, and interactive demonstrations.

**Key Features:**
- 8 drawing primitives (brush, line, shapes, spray, fill)
- 20-level undo/redo system
- Real-time rendering at 30+ FPS
- PNG export with transparency
- Cross-platform compatibility

## Requirements

- CMake 3.10+
- OpenCV 4.x
- C++17 compatible compiler
  - GCC 7+
  - Clang 5+
  - MSVC 2017+

## Building

### Linux / macOS

```bash
git clone https://github.com/chetx27/live-doodle-on-cam.git
cd live-doodle-on-cam
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

### Windows

```powershell
git clone https://github.com/chetx27/live-doodle-on-cam.git
cd live-doodle-on-cam
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

## Usage

```bash
./live_doodle
```

### Controls

| Input | Action |
|-------|--------|
| `1-8` | Select drawing tool |
| `Left Click + Drag` | Draw |
| `Mouse Wheel` | Adjust brush size |
| `C` | Clear canvas |
| `Z` | Undo |
| `X` | Redo |
| `S` | Save as PNG |
| `H` | Toggle help |
| `ESC` | Exit |

## Architecture

The application follows a modular event-driven architecture:

- **Video Capture Module** - Camera input and frame management
- **Drawing Engine** - Tool implementations and rendering pipeline
- **State Manager** - Undo/redo stack with circular buffer
- **UI Layer** - Overlay rendering and user interface

See [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) for detailed system design.

## Configuration

Modify `config.json` to customize:

```json
{
  "camera": {
    "device_id": 0,
    "resolution": {"width": 640, "height": 480}
  },
  "drawing": {
    "default_brush_size": 3,
    "max_undo_levels": 20
  }
}
```

## API Reference

Complete API documentation available in [docs/API.md](docs/API.md).

Core functions:

```cpp
void mouseCallback(int event, int x, int y, int flags, void* userdata);
void saveState(std::stack<cv::Mat>& undoStack, const cv::Mat& canvas);
void sprayPaint(cv::Mat& img, cv::Point center, cv::Scalar color, int radius);
```

## Contributing

Contributions are welcome. Please read [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

### Development Priorities

- Hand gesture recognition (MediaPipe)
- Video recording functionality
- Multi-layer support
- Text annotation tool

## Security

Security vulnerabilities should be reported via email to chethana.workspace@gmail.com. See [SECURITY.md](SECURITY.md) for details.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Citation

If you use this software in your research, please cite:

```bibtex
@software{live_doodle_2025,
  author = {Chethana G},
  title = {Live Doodle on Camera},
  year = {2025},
  url = {https://github.com/chetx27/live-doodle-on-cam}
}
```

## References

- [OpenCV Documentation](https://docs.opencv.org/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)

---

**Project Status:** Active Development | **Version:** 1.0.0 | **Maintainer:** [Chethana G](https://github.com/chetx27)
