#ifndef WEBCAM_RECORDER_H
#define WEBCAM_RECORDER_H

#include <string>
#include "ffmpeg_wrapper.h"

namespace my_streaming_software {
namespace recorder {

class WebcamRecorder {
public:
    void startCapture(const std::string& filePath);
    void stopCapture();
    void saveCapture();

private:
    bool isCapturing = false;
    std::string filePath;
    utils::FFmpegWrapper ffmpegWrapper;
};

} // namespace recorder
} // namespace my_streaming_software

#endif // WEBCAM_RECORDER_H
