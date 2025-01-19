#include "live_streamer.h"
#include <iostream>

namespace my_streaming_software {
namespace streamer {

bool LiveStreamer::initialize(const std::string& url) {
    this->url = url;
    // Initialize FFmpeg for streaming
    if (!ffmpegWrapper.initialize(url)) {
        std::cerr << "Failed to initialize FFmpeg for streaming." << std::endl;
        return false;
    }
    return true;
}

bool LiveStreamer::startStreaming() {
    if (isStreaming) {
        std::cerr << "Streaming is already in progress." << std::endl;
        return false;
    }

    isStreaming = true;

    // Start FFmpeg streaming
    if (!ffmpegWrapper.start()) {
        std::cerr << "Failed to start streaming." << std::endl;
        isStreaming = false;
        return false;
    }

    std::cout << "Streaming started." << std::endl;
    return true;
}

bool LiveStreamer::stopStreaming() {
    if (!isStreaming) {
        std::cerr << "No streaming is in progress." << std::endl;
        return false;
    }

    // Stop FFmpeg streaming
    if (!ffmpegWrapper.stop()) {
        std::cerr << "Failed to stop streaming." << std::endl;
        return false;
    }

    isStreaming = false;
    std::cout << "Streaming stopped." << std::endl;
    return true;
}

} // namespace streamer
} // namespace my_streaming_software
