# my_streaming_software

## Overview

my_streaming_software is a software application designed for screen recording and live streaming. It provides a user-friendly interface for capturing and broadcasting your screen activities.

## Features

- Screen recording using FFmpeg library
- Live streaming to various platforms
- User-friendly GUI

## Screen Recording

The screen recording functionality is implemented in the `src/recorder/screen_recorder.cpp` file. It uses the FFmpeg library to capture and save screen recordings.

### Usage

To use the screen recording functionality, follow these steps:

1. Include the `screen_recorder.h` header file in your project.
2. Create an instance of the `ScreenRecorder` class.
3. Call the `startRecording` method to start recording.
4. Call the `stopRecording` method to stop recording.
5. Call the `saveRecording` method to save the recorded file.

### Example

```cpp
#include "screen_recorder.h"

int main() {
    my_streaming_software::recorder::ScreenRecorder recorder;

    // Start recording
    recorder.startRecording("output.mp4");

    // Perform screen activities...

    // Stop recording
    recorder.stopRecording();

    // Save the recording
    recorder.saveRecording();

    return 0;
}
```

## Live Streaming

The live streaming functionality is implemented in the `src/streamer/live_streamer.cpp` file. It uses the RTMP protocol to stream to various platforms.

### Usage

To use the live streaming functionality, follow these steps:

1. Include the `live_streamer.h` header file in your project.
2. Create an instance of the `LiveStreamer` class.
3. Call the `startStreaming` method to start streaming.
4. Call the `stopStreaming` method to stop streaming.

### Example

```cpp
#include "live_streamer.h"

int main() {
    my_streaming_software::streamer::LiveStreamer streamer;

    // Start streaming
    streamer.startStreaming("rtmp://your_streaming_server/live");

    // Perform streaming activities...

    // Stop streaming
    streamer.stopStreaming();

    return 0;
}
```

## Webcam Capture

The webcam capture functionality is implemented in the `src/recorder/webcam_recorder.cpp` file. It uses the FFmpeg library to capture webcam input.

### Usage

To use the webcam capture functionality, follow these steps:

1. Include the `webcam_recorder.h` header file in your project.
2. Create an instance of the `WebcamRecorder` class.
3. Call the `startCapture` method to start capturing.
4. Call the `stopCapture` method to stop capturing.
5. Call the `saveCapture` method to save the captured file.

### Example

```cpp
#include "webcam_recorder.h"

int main() {
    my_streaming_software::recorder::WebcamRecorder recorder;

    // Start capturing
    recorder.startCapture("webcam_output.mp4");

    // Perform webcam activities...

    // Stop capturing
    recorder.stopCapture();

    // Save the capture
    recorder.saveCapture();

    return 0;
}
```

## Audio Input

The audio input functionality is implemented in the `src/recorder/audio_recorder.cpp` file. It uses the FFmpeg library to capture audio input.

### Usage

To use the audio input functionality, follow these steps:

1. Include the `audio_recorder.h` header file in your project.
2. Create an instance of the `AudioRecorder` class.
3. Call the `startRecording` method to start recording audio.
4. Call the `stopRecording` method to stop recording audio.
5. Call the `saveRecording` method to save the recorded audio file.

### Example

```cpp
#include "audio_recorder.h"

int main() {
    my_streaming_software::recorder::AudioRecorder recorder;

    // Start recording audio
    recorder.startRecording("audio_output.mp3");

    // Perform audio activities...

    // Stop recording audio
    recorder.stopRecording();

    // Save the recording
    recorder.saveRecording();

    return 0;
}
```

## Installation

To install my_streaming_software, follow the instructions in the `docs/INSTALL.md` file.

## Contributing

If you would like to contribute to the project, please refer to the `docs/CONTRIBUTING.md` file for guidelines.

## License

This project is licensed under the terms of the MIT license. See the `LICENSE` file for more details.
