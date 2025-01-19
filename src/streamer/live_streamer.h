#ifndef LIVE_STREAMER_H
#define LIVE_STREAMER_H

#include <string>
#include "ffmpeg_wrapper.h"

namespace my_streaming_software {
namespace streamer {

class LiveStreamer {
public:
    bool initialize(const std::string& url);
    bool startStreaming();
    bool stopStreaming();

private:
    bool isStreaming = false;
    std::string url;
    utils::FFmpegWrapper ffmpegWrapper;
};

} // namespace streamer
} // namespace my_streaming_software

#endif // LIVE_STREAMER_H
