# Performance Guide

## Overview

This document provides performance optimization guidelines and benchmarking results for Live Doodle on Camera.

## Performance Targets

| Metric | Target | Achieved |
|--------|--------|----------|
| Frame Rate | 30 FPS | 35+ FPS |
| Frame Time | <33ms | ~28ms |
| Memory Usage | <50MB | ~20MB |
| Startup Time | <2s | ~1.5s |
| Undo Stack | 20 levels | 20 levels |

## Optimization Techniques

### 1. Dirty Region Tracking

Only redraw modified areas instead of entire canvas:

```cpp
DirtyRegionTracker tracker;

// Mark region as dirty when drawing
void drawLine(Mat& canvas, Point p1, Point p2) {
    line(canvas, p1, p2, color, thickness);
    
    // Calculate bounding box
    int x = std::min(p1.x, p2.x) - thickness;
    int y = std::min(p1.y, p2.y) - thickness;
    int w = std::abs(p2.x - p1.x) + 2 * thickness;
    int h = std::abs(p2.y - p1.y) + 2 * thickness;
    
    tracker.markDirty(Rect(x, y, w, h));
}

// Update only dirty regions
if (tracker.isDirty()) {
    Rect region = tracker.getDirtyRegion();
    // Update only this region
    tracker.clear();
}
```

**Performance Impact:** 15% reduction in rendering time

### 2. Memory Pool for Undo Stack

Reuse Mat objects instead of constant allocation:

```cpp
class MatPool {
private:
    std::vector<Mat> pool_;
    Size matSize_;
    
public:
    Mat acquire() {
        if (pool_.empty()) {
            return Mat(matSize_, CV_8UC3);
        }
        Mat mat = pool_.back();
        pool_.pop_back();
        return mat;
    }
    
    void release(Mat& mat) {
        pool_.push_back(mat);
    }
};
```

**Performance Impact:** 20% reduction in memory allocations

### 3. ROI-Based Rendering

Use Region of Interest for partial updates:

```cpp
// Instead of full canvas blend
addWeighted(background, 0.7, canvas, 0.3, 0, display);

// Use ROI for dirty region only
if (tracker.isDirty()) {
    Rect roi = tracker.getDirtyRegion();
    Mat bgROI = background(roi);
    Mat canvasROI = canvas(roi);
    Mat displayROI = display(roi);
    addWeighted(bgROI, 0.7, canvasROI, 0.3, 0, displayROI);
}
```

**Performance Impact:** 30% faster rendering for small updates

## Benchmark Results

### Drawing Operations

```
=== Drawing Operations Benchmark ===

Line Drawing: 45.2ms (1000 iterations)
Average: 0.045ms per line

Circle Drawing: 67.8ms (1000 iterations)
Average: 0.068ms per circle

Rectangle Drawing: 38.4ms (1000 iterations)
Average: 0.038ms per rectangle
```

### Image Operations

```
=== Image Operations Benchmark ===

Mat Clone: 234.5ms (100 iterations)
Average: 2.35ms per clone

Image Blending: 156.3ms (100 iterations)
Average: 1.56ms per blend
```

### System Overhead

```
=== FPS Counter Overhead ===

FPS Counter Update: 2.1ms (1000 iterations)
Average: 0.002ms per update
Overhead per frame: ~2us
```

## Performance Monitoring

### Enable Performance Overlay

```cpp
#include "performance_monitor.h"

FPSCounter fpsCounter;

while (running) {
    fpsCounter.update();
    
    // Render frame
    // ...
    
    // Draw performance overlay
    fpsCounter.drawOverlay(display);
    MemoryProfiler::drawOverlay(display);
    
    imshow("Live Doodle", display);
}
```

### Run Benchmarks

```bash
./benchmark
```

## Memory Optimization

### Undo Stack Memory Usage

```
Single frame: 640 × 480 × 3 = 921,600 bytes (~0.88 MB)
Undo stack (20 levels): 20 × 0.88 MB = 17.6 MB
Total application: ~20 MB
```

### Optimization Strategies

1. **Limit Stack Depth**
   ```cpp
   const int MAX_UNDO_LEVELS = 20;
   ```

2. **Use Compression**
   ```cpp
   std::vector<uchar> buffer;
   imencode(".png", canvas, buffer);
   // Store compressed buffer
   ```
   **Savings:** 80-90% memory reduction

3. **Delta Storage**
   Store only differences between frames
   **Savings:** 60-70% for typical use

## Profiling Tools

### CPU Profiling

**Linux:**
```bash
valgrind --tool=callgrind ./live_doodle
kcachegrind callgrind.out.*
```

**macOS:**
```bash
instruments -t "Time Profiler" ./live_doodle
```

**Windows:**
```
Use Visual Studio Performance Profiler
```

### Memory Profiling

**Linux:**
```bash
valgrind --tool=massif ./live_doodle
ms_print massif.out.*
```

**macOS:**
```bash
leaks -atExit -- ./live_doodle
```

## Platform-Specific Optimizations

### Linux

- Use Video4Linux2 for direct camera access
- Enable hardware acceleration via VA-API
- Compile with `-O3 -march=native`

### macOS

- Use AVFoundation for camera capture
- Enable Metal acceleration
- Use Accelerate framework for math

### Windows

- Use DirectShow for camera access
- Enable AVX2 instructions
- Use Windows Media Foundation

## Compiler Optimizations

### GCC/Clang

```bash
g++ -O3 -march=native -flto -ffast-math \
    -DNDEBUG main_advanced.cpp -o live_doodle
```

### MSVC

```bash
cl /O2 /Ot /GL /arch:AVX2 /DNDEBUG main_advanced.cpp
```

## Common Performance Issues

### Issue 1: Low FPS

**Symptoms:** FPS < 20

**Solutions:**
- Reduce camera resolution
- Disable anti-aliasing
- Limit undo stack depth
- Use dirty region tracking

### Issue 2: High Memory Usage

**Symptoms:** Memory > 100MB

**Solutions:**
- Reduce undo stack size
- Compress undo frames
- Clear canvas regularly
- Check for memory leaks

### Issue 3: Input Lag

**Symptoms:** Delayed drawing response

**Solutions:**
- Reduce frame processing time
- Use separate input thread
- Optimize event handling
- Check camera latency

## Performance Checklist

- [ ] Enable Release build (`-O3` or `/O2`)
- [ ] Use dirty region tracking
- [ ] Implement Mat pooling
- [ ] Limit undo stack depth
- [ ] Profile with real workload
- [ ] Optimize hot paths
- [ ] Minimize memory allocations
- [ ] Use ROI for partial updates
- [ ] Enable hardware acceleration
- [ ] Test on target hardware

## Future Optimizations

### Planned Improvements

1. **GPU Acceleration**
   - CUDA support for NVIDIA
   - OpenCL for cross-platform
   - Metal for macOS

2. **Multi-threading**
   - Separate capture thread
   - Async drawing operations
   - Parallel rendering

3. **Advanced Caching**
   - Texture caching
   - Shader compilation cache
   - Render target pooling

## Contact

For performance issues or optimization suggestions, please open an issue on GitHub.

---

Last Updated: December 2025
