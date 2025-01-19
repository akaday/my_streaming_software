#ifndef LIVE_STREAMER_H
#define LIVE_STREAMER_H

#include <string>
#include "ffmpeg_wrapper.h"
#include "rtmp_streamer.h"
#include "webrtc_streamer.h"

namespace my_streaming_software {
namespace streamer {

class LiveStreamer {
public:
    bool initialize(const std::string& url);
    bool startStreaming();
    bool stopStreaming();

    LiveStreamer();
    ~LiveStreamer();

    bool initializeRTMP(const std::string& url);
    bool initializeWebRTC(const std::string& url);
    bool sendRTMPData(const char* data, int size);
    bool sendWebRTCData(const char* data, int size);

private:
    bool isStreaming = false;
    std::string url;
    utils::FFmpegWrapper ffmpegWrapper;
    RTMPStreamer* rtmpStreamer;
    WebRTCStreamer* webrtcStreamer;
};

} // namespace streamer
} // namespace my_streaming_software

#endif // LIVE_STREAMER_H
