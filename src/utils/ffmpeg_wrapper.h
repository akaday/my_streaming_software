#ifndef FFMPEG_WRAPPER_H
#define FFMPEG_WRAPPER_H

#include <string>

namespace my_streaming_software {
namespace utils {

class FFmpegWrapper {
public:
    bool initialize(const std::string& inputFilePath);
    bool applyFilter(const std::string& filterName);
    bool save(const std::string& outputFilePath);
    bool start();
    bool stop();

    // Methods for applying real-time effects
    bool applyRealTimeEffect(const std::string& effectName);
    bool removeRealTimeEffect(const std::string& effectName);
};

} // namespace utils
} // namespace my_streaming_software

#endif // FFMPEG_WRAPPER_H
