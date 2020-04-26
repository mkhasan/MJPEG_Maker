cmake_minimum_required(VERSION 2.8)

project(mjpeg_maker)
set (APP ${PROJECT_NAME})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_definitions(-DDATA_DIR="$ENV{DATA_DIR}")  

include_directories($ENV{ACE_ROOT})
include_directories($ENV{OPENCV_INSTALL_DIR}/include)
#include_directories($ENV{HOME}/ffmpeg_build/include /usr/local/include/opencv4/)
include_directories(/usr/local/include)

link_directories(/usr/local/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -Wall -Wno-narrowing -D_GNU_SOURCE=1 -D_REENTRANT -I/usr/local/include -I/usr/include/SDL")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L$ENV{ACE_ROOT}/lib -L$ENV{OPENCV_INSTALL_DIR}/lib" )
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L$ENV{HOME}/ffmpeg_build/lib -L/usr/local/lib -lavformat -lavcodec -ldl -lxcb-xfixes -lxcb-render -lxcb-shape -lxcb -lX11 -lz -lswresample -lswscale -lavutil -lm -lSDL" )

set ( SRC
	src/${APP}.cpp
	src/client_handler.cpp
	src/CStreamer.cpp
	src/JPEGSamples.cpp
	src/CRtspSession.cpp
	src/image_writer.cpp
	src/jpeg_writer.cpp
	src/stream_source.cpp
	src/fake_source.cpp
)			
	
add_executable(${APP} ${SRC})

target_link_libraries (${APP} ACE avformat avcodec dl xcb-xfixes xcb-render xcb-shape xcb X11 z swresample swscale avutil m SDL pthread jpeg pthread)

