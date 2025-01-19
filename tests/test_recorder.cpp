#include "screen_recorder.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace my_streaming_software::recorder;
using namespace testing;

class MockFFmpegWrapper : public my_streaming_software::utils::FFmpegWrapper {
public:
    MOCK_METHOD(bool, initialize, (const std::string&), (override));
    MOCK_METHOD(bool, start, (), (override));
    MOCK_METHOD(bool, stop, (), (override));
    MOCK_METHOD(bool, save, (const std::string&), (override));
};

class ScreenRecorderTest : public Test {
protected:
    ScreenRecorder recorder;
    MockFFmpegWrapper mockFFmpegWrapper;

    void SetUp() override {
        recorder.ffmpegWrapper = &mockFFmpegWrapper;
    }
};

TEST_F(ScreenRecorderTest, StartRecording) {
    EXPECT_CALL(mockFFmpegWrapper, initialize(_)).WillOnce(Return(true));
    EXPECT_CALL(mockFFmpegWrapper, start()).WillOnce(Return(true));

    recorder.startRecording("test.mp4");

    EXPECT_TRUE(recorder.isRecording);
}

TEST_F(ScreenRecorderTest, StopRecording) {
    EXPECT_CALL(mockFFmpegWrapper, stop()).WillOnce(Return(true));

    recorder.isRecording = true;
    recorder.stopRecording();

    EXPECT_FALSE(recorder.isRecording);
}

TEST_F(ScreenRecorderTest, SaveRecording) {
    EXPECT_CALL(mockFFmpegWrapper, save(_)).WillOnce(Return(true));

    recorder.isRecording = false;
    recorder.saveRecording();

    EXPECT_EQ(recorder.filePath, "test.mp4");
}