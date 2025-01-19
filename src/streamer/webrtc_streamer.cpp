#include "webrtc_streamer.h"
#include <iostream>
#include <stdexcept>

namespace my_streaming_software {
namespace streamer {

WebRTCStreamer::WebRTCStreamer() : peerConnection(nullptr) {}

WebRTCStreamer::~WebRTCStreamer() {
    if (peerConnection) {
        // Close and clean up the peer connection
        peerConnection->Close();
        delete peerConnection;
    }
}

bool WebRTCStreamer::initialize(const std::string& url) {
    // Initialize WebRTC connection
    peerConnection = new webrtc::PeerConnectionInterface();
    if (!peerConnection) {
        logError("Failed to create WebRTC peer connection.");
        return false;
    }

    // Set up the WebRTC connection with the provided URL
    if (!peerConnection->Setup(url)) {
        logError("Failed to set up WebRTC connection.");
        return false;
    }

    return true;
}

bool WebRTCStreamer::sendData(const char* data, int size) {
    if (!peerConnection) {
        logError("WebRTC peer connection is not initialized.");
        return false;
    }

    // Send data over the WebRTC connection
    int result = peerConnection->SendData(data, size);
    if (result <= 0) {
        logError("Failed to send data over WebRTC connection.");
        return false;
    }

    return true;
}

void WebRTCStreamer::logError(const std::string& errorMessage) {
    std::cerr << "WebRTCStreamer Error: " << errorMessage << std::endl;
}

void WebRTCStreamer::handleError(const std::string& errorMessage) {
    logError(errorMessage);
    // Implement retry logic or other error handling mechanisms here
}

} // namespace streamer
} // namespace my_streaming_software
