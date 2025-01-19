#ifndef SCREEN_RECORDER_H
#define SCREEN_RECORDER_H

#include <string>
#include "ffmpeg_wrapper.h"

namespace my_streaming_software {
namespace recorder {

class ScreenRecorder {
public:
    void startRecording(const std::string& filePath);
    void stopRecording();
    void saveRecording();

private:
    bool isRecording = false;
    std::string filePath;
    utils::FFmpegWrapper ffmpegWrapper;
};

} // namespace recorder
} // namespace my_streaming_software

#endif // SCREEN_RECORDER_H
