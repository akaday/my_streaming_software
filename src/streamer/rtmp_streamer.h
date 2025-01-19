#ifndef RTMP_STREAMER_H
#define RTMP_STREAMER_H

#include <string>
#include <librtmp/rtmp.h>

namespace my_streaming_software {
namespace streamer {

class RTMPStreamer {
public:
    RTMPStreamer();
    ~RTMPStreamer();

    bool initialize(const std::string& url);
    bool sendData(const char* data, int size);

private:
    void logError(const std::string& errorMessage);
    void handleError(const std::string& errorMessage);

    RTMP* rtmp;
};

} // namespace streamer
} // namespace my_streaming_software

#endif // RTMP_STREAMER_H
