# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Planned
- Hand gesture recognition using MediaPipe
- Video recording with audio support
- Text annotation tool
- Multi-layer composition support
- Advanced color picker with HSV interface

## [1.0.0] - 2025-12-26

### Added
- Initial release of Live Doodle on Camera
- 8 drawing tools: Brush, Eraser, Line, Rectangle, Circle, Ellipse, Spray, Fill
- 10 preset colors with interactive palette
- Adjustable brush size (1-20 pixels)
- 20-level undo/redo system
- PNG export with timestamp
- Real-time camera integration
- Keyboard shortcuts for all major functions
- Help overlay system
- Anti-aliased rendering
- Real-time shape preview
- Cross-platform support (Windows, macOS, Linux)
- CMake build system
- Comprehensive documentation

### Features

#### Drawing Tools
- **Brush Tool**: Smooth freehand drawing with anti-aliasing
- **Eraser Tool**: Selective stroke removal
- **Line Tool**: Precise straight line rendering
- **Rectangle Tool**: Rectangular shape primitive
- **Circle Tool**: Circular shape primitive from center
- **Ellipse Tool**: Elliptical shape primitive
- **Spray Tool**: Particle-based spray paint effect
- **Fill Tool**: Flood fill algorithm for enclosed areas

#### User Interface
- Interactive color palette at screen top
- Visual tool selection indicators
- Contextual help menu (toggle with H)
- Clean, minimal workspace design
- Real-time brush size indicator

#### Performance
- Consistent 30+ FPS at 720p resolution
- Optimized memory management
- Efficient undo/redo stack implementation
- Low latency input handling

#### Configuration
- Camera device selection
- Resolution adjustment
- Frame rate configuration
- Default tool and color settings
- JSON configuration file support

### Technical Specifications

- **Language**: C++17
- **Framework**: OpenCV 4.x
- **Build System**: CMake 3.10+
- **Supported Platforms**: Windows 10+, macOS 10.15+, Ubuntu 20.04+
- **Dependencies**: OpenCV 4.x, CMake, C++17 compiler

### Documentation

- Comprehensive README with installation instructions
- API reference documentation
- Code of Conduct
- Contributing guidelines
- Security policy
- Issue templates
- Pull request template

---

## Version History

### [1.0.0] - 2025-12-26
Initial stable release with core functionality

---

## Upgrade Guide

### From Pre-release to 1.0.0

No migration required for first stable release.

---

## Deprecation Notices

None at this time.

---

## Contributors

Thank you to all contributors who made this release possible:

- Chethana G (@chetx27) - Project Creator & Lead Developer

---

[Unreleased]: https://github.com/chetx27/live-doodle-on-cam/compare/v1.0.0...HEAD
[1.0.0]: https://github.com/chetx27/live-doodle-on-cam/releases/tag/v1.0.0
