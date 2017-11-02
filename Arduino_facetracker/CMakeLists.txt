
cmake_minimum_required(VERSION 2.8)
project( FaceDetect )
find_package( OpenCV REQUIRED )
add_executable( Arduino_FaceDetection Arduino_FaceDetection.cpp )
target_link_libraries( Arduino_FaceDetection ${OpenCV_LIBS} )
