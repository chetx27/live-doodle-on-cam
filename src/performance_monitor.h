/**
 * @file performance_monitor.h
 * @brief Performance monitoring and profiling utilities
 * @author Chethana G
 * @date 2025-12-27
 */

#ifndef PERFORMANCE_MONITOR_H
#define PERFORMANCE_MONITOR_H

#include <chrono>
#include <deque>
#include <string>
#include <opencv2/opencv.hpp>

namespace performance {

/**
 * @class FPSCounter
 * @brief Calculates and displays frames per second
 */
class FPSCounter {
public:
    FPSCounter(int windowSize = 30)
        : windowSize_(windowSize), fps_(0.0) {}

    /**
     * @brief Update FPS calculation with new frame time
     */
    void update() {
        auto now = std::chrono::high_resolution_clock::now();
        
        if (lastFrame_.time_since_epoch().count() > 0) {
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                now - lastFrame_).count();
            frameTimes_.push_back(duration);
            
            if (frameTimes_.size() > windowSize_) {
                frameTimes_.pop_front();
            }
            
            // Calculate average FPS
            double avgTime = 0.0;
            for (const auto& time : frameTimes_) {
                avgTime += time;
            }
            avgTime /= frameTimes_.size();
            
            fps_ = (avgTime > 0) ? 1000.0 / avgTime : 0.0;
        }
        
        lastFrame_ = now;
    }

    /**
     * @brief Get current FPS
     * @return Current frames per second
     */
    double getFPS() const { return fps_; }

    /**
     * @brief Get average frame time in milliseconds
     * @return Average frame time
     */
    double getAvgFrameTime() const {
        if (frameTimes_.empty()) return 0.0;
        
        double sum = 0.0;
        for (const auto& time : frameTimes_) {
            sum += time;
        }
        return sum / frameTimes_.size();
    }

    /**
     * @brief Draw FPS overlay on image
     * @param img Target image
     * @param position Text position
     */
    void drawOverlay(cv::Mat& img, cv::Point position = cv::Point(10, 30)) {
        std::string fpsText = "FPS: " + std::to_string(static_cast<int>(fps_));
        std::string frameTimeText = "Frame: " + 
            std::to_string(static_cast<int>(getAvgFrameTime())) + "ms";
        
        cv::putText(img, fpsText, position, cv::FONT_HERSHEY_SIMPLEX,
                   0.7, cv::Scalar(0, 255, 0), 2);
        cv::putText(img, frameTimeText, position + cv::Point(0, 30),
                   cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(0, 255, 0), 2);
    }

private:
    int windowSize_;
    double fps_;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastFrame_;
    std::deque<double> frameTimes_;
};

/**
 * @class MemoryProfiler
 * @brief Monitors memory usage
 */
class MemoryProfiler {
public:
    /**
     * @brief Get current memory usage in MB
     * @return Memory usage in megabytes
     */
    static double getCurrentMemoryMB() {
#ifdef _WIN32
        PROCESS_MEMORY_COUNTERS_EX pmc;
        GetProcessMemoryInfo(GetCurrentProcess(),
                           (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
        return pmc.WorkingSetSize / (1024.0 * 1024.0);
#elif __APPLE__
        struct task_basic_info info;
        mach_msg_type_number_t size = sizeof(info);
        kern_return_t kerr = task_info(mach_task_self(),
                                       TASK_BASIC_INFO,
                                       (task_info_t)&info, &size);
        return (kerr == KERN_SUCCESS) ? info.resident_size / (1024.0 * 1024.0) : 0.0;
#else
        // Linux
        long rss = 0L;
        FILE* fp = fopen("/proc/self/statm", "r");
        if (fp) {
            if (fscanf(fp, "%*s%ld", &rss) == 1) {
                fclose(fp);
                return (rss * sysconf(_SC_PAGESIZE)) / (1024.0 * 1024.0);
            }
            fclose(fp);
        }
        return 0.0;
#endif
    }

    /**
     * @brief Draw memory usage overlay
     * @param img Target image
     * @param position Text position
     */
    static void drawOverlay(cv::Mat& img, cv::Point position = cv::Point(10, 90)) {
        double memoryMB = getCurrentMemoryMB();
        std::string memText = "Memory: " + 
            std::to_string(static_cast<int>(memoryMB)) + " MB";
        
        cv::putText(img, memText, position, cv::FONT_HERSHEY_SIMPLEX,
                   0.7, cv::Scalar(255, 255, 0), 2);
    }
};

/**
 * @class PerformanceTimer
 * @brief High-precision timer for profiling
 */
class PerformanceTimer {
public:
    /**
     * @brief Start the timer
     */
    void start() {
        startTime_ = std::chrono::high_resolution_clock::now();
    }

    /**
     * @brief Stop the timer and return elapsed time
     * @return Elapsed time in milliseconds
     */
    double stop() {
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
            endTime - startTime_).count();
        return duration / 1000.0;  // Convert to milliseconds
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime_;
};

/**
 * @class DirtyRegionTracker
 * @brief Tracks modified regions for optimized rendering
 */
class DirtyRegionTracker {
public:
    DirtyRegionTracker() : isDirty_(false) {}

    /**
     * @brief Mark a region as dirty
     * @param rect Rectangle to mark as dirty
     */
    void markDirty(const cv::Rect& rect) {
        if (!isDirty_) {
            dirtyRegion_ = rect;
            isDirty_ = true;
        } else {
            // Expand dirty region to include new rect
            int x1 = std::min(dirtyRegion_.x, rect.x);
            int y1 = std::min(dirtyRegion_.y, rect.y);
            int x2 = std::max(dirtyRegion_.x + dirtyRegion_.width,
                            rect.x + rect.width);
            int y2 = std::max(dirtyRegion_.y + dirtyRegion_.height,
                            rect.y + rect.height);
            
            dirtyRegion_ = cv::Rect(x1, y1, x2 - x1, y2 - y1);
        }
    }

    /**
     * @brief Check if there are dirty regions
     * @return True if dirty regions exist
     */
    bool isDirty() const { return isDirty_; }

    /**
     * @brief Get the dirty region
     * @return Dirty region rectangle
     */
    cv::Rect getDirtyRegion() const { return dirtyRegion_; }

    /**
     * @brief Clear dirty region
     */
    void clear() {
        isDirty_ = false;
        dirtyRegion_ = cv::Rect();
    }

private:
    bool isDirty_;
    cv::Rect dirtyRegion_;
};

}  // namespace performance

#endif  // PERFORMANCE_MONITOR_H
