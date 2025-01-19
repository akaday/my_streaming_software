cmake_minimum_required(VERSION 3.10)

project(my_streaming_software)

set(CMAKE_CXX_STANDARD 17)

# Include Qt libraries and modules
find_package(Qt5 COMPONENTS Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

# Include FFmpeg library
find_package(PkgConfig REQUIRED)
pkg_check_modules(FFMPEG REQUIRED libavcodec libavformat libavutil libswscale)
include_directories(${FFMPEG_INCLUDE_DIRS})
link_directories(${FFMPEG_LIBRARY_DIRS})
add_definitions(${FFMPEG_CFLAGS_OTHER})

# Include necessary libraries for RTMP streaming
find_package(LibRtmp REQUIRED)
include_directories(${LIBRTMP_INCLUDE_DIRS})
link_directories(${LIBRTMP_LIBRARY_DIRS})
add_definitions(${LIBRTMP_CFLAGS_OTHER})

# Include necessary libraries for WebRTC streaming
find_package(WebRTC REQUIRED)
include_directories(${WEBRTC_INCLUDE_DIRS})
link_directories(${WEBRTC_LIBRARY_DIRS})
add_definitions(${WEBRTC_CFLAGS_OTHER})

# Add source files
set(SOURCES
    src/main.cpp
    src/recorder/screen_recorder.cpp
    src/streamer/live_streamer.cpp
    src/gui/main_window.cpp
    src/streamer/rtmp_streamer.cpp
    src/streamer/webrtc_streamer.cpp
)

# Add header files
set(HEADERS
    src/recorder/screen_recorder.h
    src/streamer/live_streamer.h
    src/gui/main_window.h
    src/streamer/rtmp_streamer.h
    src/streamer/webrtc_streamer.h
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${Qt5Widgets_LIBRARIES} ${FFMPEG_LIBRARIES} ${LIBRTMP_LIBRARIES} ${WEBRTC_LIBRARIES})
