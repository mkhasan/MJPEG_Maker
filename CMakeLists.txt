cmake_minimum_required(VERSION 2.8)

set (APP server)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_definitions(-DDATA_DIR="$ENV{DATA_DIR}")  

include_directories($ENV{ACE_ROOT})
include_directories($ENV{OPENCV_INSTALL_DIR}/include)
include_directories($ENV{HOME}/ffmpeg_build/include /usr/local/include/opencv4/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -Wall -Wno-narrowing -D_GNU_SOURCE=1 -D_REENTRANT -I/usr/local/include -I/usr/include/SDL")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L$ENV{ACE_ROOT}/lib -L$ENV{OPENCV_INSTALL_DIR}/lib" )
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L$ENV{HOME}/ffmpeg_build/lib -L/usr/local/lib -lavformat -lavcodec -ldl -lxcb-xfixes -lxcb-render -lxcb-shape -lxcb -lX11 -lz -lswresample -lswscale -lavutil -lm -lSDL" )

add_executable(${APP} src/${APP}.cpp src/client_handler.cpp src/CStreamer.cpp src/JPEGSamples.cpp src/CRtspSession.cpp src/JPEG_Test.cpp src/JPEG_Write.cpp)
target_link_libraries (${APP} ACE avformat avcodec dl xcb-xfixes xcb-render xcb-shape xcb X11 z swresample swscale avutil m SDL pthread jpeg pthread)

add_executable(compress src/compress.cpp)
target_link_libraries(compress opencv_core opencv_videoio opencv_imgcodecs opencv_highgui opencv_imgproc x265)

#add_executable(JPEG_Test src/JPEG_Test.cpp src/JPEG_Write.cpp)
#target_link_libraries(JPEG_Test avformat avcodec dl xcb-xfixes xcb-render xcb-shape xcb X11 z swresample swscale avutil m SDL pthread jpeg)




