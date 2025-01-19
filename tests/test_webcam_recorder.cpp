#include "webcam_recorder.h"
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

class WebcamRecorderTest : public Test {
protected:
    WebcamRecorder recorder;
    MockFFmpegWrapper mockFFmpegWrapper;

    void SetUp() override {
        recorder.ffmpegWrapper = &mockFFmpegWrapper;
    }
};

TEST_F(WebcamRecorderTest, StartCapture) {
    EXPECT_CALL(mockFFmpegWrapper, initialize(_)).WillOnce(Return(true));
    EXPECT_CALL(mockFFmpegWrapper, start()).WillOnce(Return(true));

    recorder.startCapture("test.mp4");

    EXPECT_TRUE(recorder.isCapturing);
}

TEST_F(WebcamRecorderTest, StopCapture) {
    EXPECT_CALL(mockFFmpegWrapper, stop()).WillOnce(Return(true));

    recorder.isCapturing = true;
    recorder.stopCapture();

    EXPECT_FALSE(recorder.isCapturing);
}

TEST_F(WebcamRecorderTest, SaveCapture) {
    EXPECT_CALL(mockFFmpegWrapper, save(_)).WillOnce(Return(true));

    recorder.isCapturing = false;
    recorder.saveCapture();

    EXPECT_EQ(recorder.filePath, "test.mp4");
}
