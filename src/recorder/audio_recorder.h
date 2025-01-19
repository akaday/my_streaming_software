#ifndef AUDIO_RECORDER_H
#define AUDIO_RECORDER_H

#include <string>
#include "ffmpeg_wrapper.h"

namespace my_streaming_software {
namespace recorder {

class AudioRecorder {
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

#endif // AUDIO_RECORDER_H
