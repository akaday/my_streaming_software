#include "audio_recorder.h"
#include "ffmpeg_wrapper.h"
#include <iostream>

namespace my_streaming_software {
namespace recorder {

void AudioRecorder::startRecording(const std::string& filePath) {
    if (isRecording) {
        std::cerr << "Recording is already in progress." << std::endl;
        return;
    }

    this->filePath = filePath;
    isRecording = true;

    // Initialize FFmpeg and start recording
    if (!ffmpegWrapper.initialize(filePath)) {
        std::cerr << "Failed to initialize FFmpeg." << std::endl;
        isRecording = false;
        return;
    }

    if (!ffmpegWrapper.start()) {
        std::cerr << "Failed to start recording." << std::endl;
        isRecording = false;
        return;
    }

    std::cout << "Recording started." << std::endl;
}

void AudioRecorder::stopRecording() {
    if (!isRecording) {
        std::cerr << "No recording is in progress." << std::endl;
        return;
    }

    // Stop FFmpeg recording
    if (!ffmpegWrapper.stop()) {
        std::cerr << "Failed to stop recording." << std::endl;
        return;
    }

    isRecording = false;
    std::cout << "Recording stopped." << std::endl;
}

void AudioRecorder::saveRecording() {
    if (isRecording) {
        std::cerr << "Cannot save while recording is in progress." << std::endl;
        return;
    }

    // Save the recorded file
    if (!ffmpegWrapper.save(filePath)) {
        std::cerr << "Failed to save recording." << std::endl;
        return;
    }

    std::cout << "Recording saved to " << filePath << std::endl;
}

} // namespace recorder
} // namespace my_streaming_software
