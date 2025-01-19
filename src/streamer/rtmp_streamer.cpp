#include "rtmp_streamer.h"
#include <iostream>
#include <stdexcept>

namespace my_streaming_software {
namespace streamer {

RTMPStreamer::RTMPStreamer() : rtmp(nullptr) {}

RTMPStreamer::~RTMPStreamer() {
    if (rtmp) {
        RTMP_Close(rtmp);
        RTMP_Free(rtmp);
    }
}

bool RTMPStreamer::initialize(const std::string& url) {
    rtmp = RTMP_Alloc();
    if (!rtmp) {
        logError("Failed to allocate RTMP context.");
        return false;
    }

    RTMP_Init(rtmp);
    if (!RTMP_SetupURL(rtmp, const_cast<char*>(url.c_str()))) {
        logError("Failed to set up RTMP URL.");
        return false;
    }

    RTMP_EnableWrite(rtmp);
    if (!RTMP_Connect(rtmp, nullptr)) {
        logError("Failed to connect to RTMP server.");
        return false;
    }

    if (!RTMP_ConnectStream(rtmp, 0)) {
        logError("Failed to connect RTMP stream.");
        return false;
    }

    return true;
}

bool RTMPStreamer::sendData(const char* data, int size) {
    if (!rtmp) {
        logError("RTMP context is not initialized.");
        return false;
    }

    int result = RTMP_Write(rtmp, data, size);
    if (result <= 0) {
        logError("Failed to send data to RTMP server.");
        return false;
    }

    return true;
}

void RTMPStreamer::logError(const std::string& errorMessage) {
    std::cerr << "RTMPStreamer Error: " << errorMessage << std::endl;
}

void RTMPStreamer::handleError(const std::string& errorMessage) {
    logError(errorMessage);
    // Implement retry logic or other error handling mechanisms here
}

} // namespace streamer
} // namespace my_streaming_software
