#include "real_time_effects.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace my_streaming_software::effects;
using namespace testing;

class MockFFmpegWrapper : public my_streaming_software::utils::FFmpegWrapper {
public:
    MOCK_METHOD(bool, initialize, (const std::string&), (override));
    MOCK_METHOD(bool, applyFilter, (const std::string&), (override));
    MOCK_METHOD(bool, save, (const std::string&), (override));
};

class RealTimeEffectsTest : public Test {
protected:
    RealTimeEffects realTimeEffects;
    MockFFmpegWrapper mockFFmpegWrapper;

    void SetUp() override {
        realTimeEffects.ffmpegWrapper = &mockFFmpegWrapper;
    }
};

TEST_F(RealTimeEffectsTest, ApplyEffect) {
    EXPECT_CALL(mockFFmpegWrapper, initialize(_)).WillOnce(Return(true));
    EXPECT_CALL(mockFFmpegWrapper, applyFilter(_)).WillOnce(Return(true));
    EXPECT_CALL(mockFFmpegWrapper, save(_)).WillOnce(Return(true));

    bool result = realTimeEffects.applyEffect("test_effect", "input.mp4", "output.mp4");

    EXPECT_TRUE(result);
}
