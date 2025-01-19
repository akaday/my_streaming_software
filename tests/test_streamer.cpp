#include "live_streamer.h"
#include "rtmp_streamer.h"
#include "webrtc_streamer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace my_streaming_software::streamer;
using namespace testing;

class MockFFmpegWrapper : public my_streaming_software::utils::FFmpegWrapper {
public:
    MOCK_METHOD(bool, initialize, (const std::string&), (override));
    MOCK_METHOD(bool, start, (), (override));
    MOCK_METHOD(bool, stop, (), (override));
};

class MockRTMPStreamer : public RTMPStreamer {
public:
    MOCK_METHOD(bool, initialize, (const std::string&), (override));
    MOCK_METHOD(bool, sendData, (const char*, int), (override));
};

class MockWebRTCStreamer : public WebRTCStreamer {
public:
    MOCK_METHOD(bool, initialize, (const std::string&), (override));
    MOCK_METHOD(bool, sendData, (const char*, int), (override));
};

class LiveStreamerTest : public Test {
protected:
    LiveStreamer streamer;
    MockFFmpegWrapper mockFFmpegWrapper;
    MockRTMPStreamer mockRTMPStreamer;
    MockWebRTCStreamer mockWebRTCStreamer;

    void SetUp() override {
        streamer.ffmpegWrapper = &mockFFmpegWrapper;
    }
};

TEST