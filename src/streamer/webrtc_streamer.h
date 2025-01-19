#ifndef WEBRTC_STREAMER_H
#define WEBRTC_STREAMER_H

#include <string>
#include <webrtc/api/peer_connection_interface.h>

namespace my_streaming_software {
namespace streamer {

class WebRTCStreamer {
public:
    WebRTCStreamer();
    ~WebRTCStreamer();

    bool initialize(const std::string& url);
    bool sendData(const char* data, int size);

private:
    void logError(const std::string& errorMessage);
    void handleError(const std::string& errorMessage);

    webrtc::PeerConnectionInterface* peerConnection;
};

} // namespace streamer
} // namespace my_streaming_software

#endif // WEBRTC_STREAMER_H
