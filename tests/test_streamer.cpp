#include "rtmp_streamer.h"
#include "webrtc_streamer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace my_streaming_software::streamer;
using namespace testing;

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

class RTMPStreamerTest : public Test {
protected:
    MockRTMPStreamer mockRTMPStreamer;
};

class WebRTCStreamerTest : public Test {
protected:
    MockWebRTCStreamer mockWebRTCStreamer;
};

TEST_F(RTMPStreamerTest, InitializeRTMP) {
    EXPECT_CALL(mockRTMPStreamer, initialize(_)).WillOnce(Return(true));

    bool result = mockRTMPStreamer.initialize("rtmp://test.url");

    EXPECT_TRUE(result);
}

TEST_F(RTMPStreamerTest, SendRTMPData) {
    EXPECT_CALL(mockRTMPStreamer, sendData(_, _)).WillOnce(Return(true));

    bool result = mockRTMPStreamer.sendData("test data", 9);

    EXPECT_TRUE(result);
}

TEST_F(WebRTCStreamerTest, InitializeWebRTC) {
    EXPECT_CALL(mockWebRTCStreamer, initialize(_)).WillOnce(Return(true));

    bool result = mockWebRTCStreamer.initialize("webrtc://test.url");

    EXPECT_TRUE(result);
}

TEST_F(WebRTCStreamerTest, SendWebRTCData) {
    EXPECT_CALL(mockWebRTCStreamer, sendData(_, _)).WillOnce(Return(true));

    bool result = mockWebRTCStreamer.sendData("test data", 9);

    EXPECT_TRUE(result);
}

TEST_F(RTMPStreamerTest, HandleRTMPError) {
    EXPECT_CALL(mockRTMPStreamer, initialize(_)).WillOnce(Return(false));

    bool result = mockRTMPStreamer.initialize("rtmp://test.url");

    EXPECT_FALSE(result);
}

TEST_F(WebRTCStreamerTest, HandleWebRTCError) {
    EXPECT_CALL(mockWebRTCStreamer, initialize(_)).WillOnce(Return(false));

    bool result = mockWebRTCStreamer.initialize("webrtc://test.url");

    EXPECT_FALSE(result);
}
