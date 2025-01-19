#include "live_streamer.h"
#include "rtmp_streamer.h"
#include "webrtc_streamer.h"

namespace my_streaming_software {
namespace streamer {

LiveStreamer::LiveStreamer() {
    rtmpStreamer = new RTMPStreamer();
    webrtcStreamer = new WebRTCStreamer();
}

LiveStreamer::~LiveStreamer() {
    delete rtmpStreamer;
    delete webrtcStreamer;
}

bool LiveStreamer::initializeRTMP(const std::string& url) {
    return rtmpStreamer->initialize(url);
}

bool LiveStreamer::initializeWebRTC(const std::string& url) {
    return webrtcStreamer->initialize(url);
}

bool LiveStreamer::sendRTMPData(const char* data, int size) {
    return rtmpStreamer->sendData(data, size);
}

bool LiveStreamer::sendWebRTCData(const char* data, int size) {
    return webrtcStreamer->sendData(data, size);
}

} // namespace streamer
} // namespace my_streaming_software
