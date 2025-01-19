#include "live_streamer.h"
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

class LiveStreamerTest : public Test {
protected:
    LiveStreamer streamer;
    MockFFmpegWrapper mockFFmpegWrapper;

    void SetUp() override {
        streamer.ffmpegWrapper = &mockFFmpegWrapper;
    }
};

TEST_F(LiveStreamerTest, Initialize) {
    EXPECT_CALL(mockFFmpegWrapper, initialize(_)).WillOnce(Return(true));

    bool result = streamer.initialize("rtmp://your_streaming_server/live");

    EXPECT_TRUE(result);
}

TEST_F(LiveStreamerTest, StartStreaming) {
    EXPECT_CALL(mockFFmpegWrapper, start()).WillOnce(Return(true));

    streamer.isStreaming = false;
    bool result = streamer.startStreaming();

    EXPECT_TRUE(result);
    EXPECT_TRUE(streamer.isStreaming);
}

TEST_F(LiveStreamerTest, StopStreaming) {
    EXPECT_CALL(mockFFmpegWrapper, stop()).WillOnce(Return(true));

    streamer.isStreaming = true;
    bool result = streamer.stopStreaming();

    EXPECT_TRUE(result);
    EXPECT_FALSE(streamer.isStreaming);
}
