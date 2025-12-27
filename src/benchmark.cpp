/**
 * @file benchmark.cpp
 * @brief Performance benchmark utility
 * @author Chethana G
 * @date 2025-12-27
 */

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include "performance_monitor.h"

using namespace cv;
using namespace performance;

/**
 * @brief Benchmark drawing operations
 */
void benchmarkDrawingOps() {
    std::cout << "\n=== Drawing Operations Benchmark ===\n" << std::endl;
    
    Mat canvas(480, 640, CV_8UC3, Scalar(0, 0, 0));
    PerformanceTimer timer;
    const int iterations = 1000;
    
    // Benchmark line drawing
    timer.start();
    for (int i = 0; i < iterations; i++) {
        line(canvas, Point(0, 0), Point(640, 480), Scalar(255, 255, 255), 2);
    }
    double lineTime = timer.stop();
    std::cout << "Line Drawing: " << lineTime << "ms (" 
              << iterations << " iterations)" << std::endl;
    std::cout << "Average: " << lineTime / iterations << "ms per line\n" << std::endl;
    
    // Benchmark circle drawing
    timer.start();
    for (int i = 0; i < iterations; i++) {
        circle(canvas, Point(320, 240), 50, Scalar(255, 255, 255), 2);
    }
    double circleTime = timer.stop();
    std::cout << "Circle Drawing: " << circleTime << "ms (" 
              << iterations << " iterations)" << std::endl;
    std::cout << "Average: " << circleTime / iterations << "ms per circle\n" << std::endl;
    
    // Benchmark rectangle drawing
    timer.start();
    for (int i = 0; i < iterations; i++) {
        rectangle(canvas, Point(100, 100), Point(540, 380),
                 Scalar(255, 255, 255), 2);
    }
    double rectTime = timer.stop();
    std::cout << "Rectangle Drawing: " << rectTime << "ms (" 
              << iterations << " iterations)" << std::endl;
    std::cout << "Average: " << rectTime / iterations << "ms per rectangle\n" << std::endl;
}

/**
 * @brief Benchmark image operations
 */
void benchmarkImageOps() {
    std::cout << "\n=== Image Operations Benchmark ===\n" << std::endl;
    
    Mat src(480, 640, CV_8UC3);
    Mat dst;
    randu(src, Scalar(0, 0, 0), Scalar(255, 255, 255));
    
    PerformanceTimer timer;
    const int iterations = 100;
    
    // Benchmark Mat clone
    timer.start();
    for (int i = 0; i < iterations; i++) {
        dst = src.clone();
    }
    double cloneTime = timer.stop();
    std::cout << "Mat Clone: " << cloneTime << "ms (" 
              << iterations << " iterations)" << std::endl;
    std::cout << "Average: " << cloneTime / iterations << "ms per clone\n" << std::endl;
    
    // Benchmark addWeighted
    Mat overlay = src.clone();
    timer.start();
    for (int i = 0; i < iterations; i++) {
        addWeighted(src, 0.7, overlay, 0.3, 0, dst);
    }
    double blendTime = timer.stop();
    std::cout << "Image Blending: " << blendTime << "ms (" 
              << iterations << " iterations)" << std::endl;
    std::cout << "Average: " << blendTime / iterations << "ms per blend\n" << std::endl;
}

/**
 * @brief Benchmark FPS counter overhead
 */
void benchmarkFPSCounter() {
    std::cout << "\n=== FPS Counter Overhead ===\n" << std::endl;
    
    FPSCounter fpsCounter;
    PerformanceTimer timer;
    const int iterations = 1000;
    
    timer.start();
    for (int i = 0; i < iterations; i++) {
        fpsCounter.update();
    }
    double fpsTime = timer.stop();
    
    std::cout << "FPS Counter Update: " << fpsTime << "ms (" 
              << iterations << " iterations)" << std::endl;
    std::cout << "Average: " << fpsTime / iterations << "ms per update" << std::endl;
    std::cout << "Overhead per frame: ~" << (fpsTime / iterations) * 1000 
              << "us\n" << std::endl;
}

/**
 * @brief Main benchmark runner
 */
int main() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  Live Doodle Performance Benchmark" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // System info
    std::cout << "\nOpenCV Version: " << CV_VERSION << std::endl;
    std::cout << "Build Type: "
#ifdef NDEBUG
              << "Release"
#else
              << "Debug"
#endif
              << std::endl;
    
    // Run benchmarks
    benchmarkDrawingOps();
    benchmarkImageOps();
    benchmarkFPSCounter();
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "  Benchmark Complete" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    return 0;
}
