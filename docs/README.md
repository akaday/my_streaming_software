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

## Installation

To install my_streaming_software, follow the instructions in the `docs/INSTALL.md` file.

## Contributing

If you would like to contribute to the project, please refer to the `docs/CONTRIBUTING.md` file for guidelines.

## License

This project is licensed under the terms of the MIT license. See the `LICENSE` file for more details.
