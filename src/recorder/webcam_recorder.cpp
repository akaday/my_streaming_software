#include "webcam_recorder.h"
#include "ffmpeg_wrapper.h"
#include <iostream>

namespace my_streaming_software {
namespace recorder {

void WebcamRecorder::startCapture(const std::string& filePath) {
    if (isCapturing) {
        std::cerr << "Capture is already in progress." << std::endl;
        return;
    }

    this->filePath = filePath;
    isCapturing = true;

    // Initialize FFmpeg and start capturing
    if (!ffmpegWrapper.initialize(filePath)) {
        std::cerr << "Failed to initialize FFmpeg." << std::endl;
        isCapturing = false;
        return;
    }

    if (!ffmpegWrapper.start()) {
        std::cerr << "Failed to start capturing." << std::endl;
        isCapturing = false;
        return;
    }

    std::cout << "Capture started." << std::endl;
}

void WebcamRecorder::stopCapture() {
    if (!isCapturing) {
        std::cerr << "No capture is in progress." << std::endl;
        return;
    }

    // Stop FFmpeg capturing
    if (!ffmpegWrapper.stop()) {
        std::cerr << "Failed to stop capturing." << std::endl;
        return;
    }

    isCapturing = false;
    std::cout << "Capture stopped." << std::endl;
}

void WebcamRecorder::saveCapture() {
    if (isCapturing) {
        std::cerr << "Cannot save while capture is in progress." << std::endl;
        return;
    }

    // Save the captured file
    if (!ffmpegWrapper.save(filePath)) {
        std::cerr << "Failed to save capture." << std::endl;
        return;
    }

    std::cout << "Capture saved to " << filePath << std::endl;
}

} // namespace recorder
} // namespace my_streaming_software
