#include "real_time_effects.h"
#include "ffmpeg_wrapper.h"
#include <iostream>

namespace my_streaming_software {
namespace effects {

bool RealTimeEffects::applyEffect(const std::string& effectName, const std::string& inputFilePath, const std::string& outputFilePath) {
    utils::FFmpegWrapper ffmpegWrapper;

    if (!ffmpegWrapper.initialize(inputFilePath)) {
        std::cerr << "Failed to initialize FFmpeg for input file: " << inputFilePath << std::endl;
        return false;
    }

    if (!ffmpegWrapper.applyFilter(effectName)) {
        std::cerr << "Failed to apply effect: " << effectName << std::endl;
        return false;
    }

    if (!ffmpegWrapper.save(outputFilePath)) {
        std::cerr << "Failed to save output file: " << outputFilePath << std::endl;
        return false;
    }

    std::cout << "Effect " << effectName << " applied successfully to " << inputFilePath << " and saved to " << outputFilePath << std::endl;
    return true;
}

} // namespace effects
} // namespace my_streaming_software
