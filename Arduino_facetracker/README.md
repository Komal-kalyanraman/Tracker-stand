Arduino has a dedicated serial library. No need for ROS. When using QT keep all these files in "src" and create a seperate
"build, devel" folder outside. Arduino code is in the project folder.

While running QT we need to parse arduino serial port details after the executable i.e."./Arduino_FaceDetection /dev/ttyUSB0".
In QT this can be done by adding "/dev/ttyUSB0" in "Command line argument" in RUN in project option. Refrence links are provided
below.

Refrence:
https://github.com/embecosm/esp9-arduino-facetracker
http://www.instructables.com/id/Face-detection-and-tracking-with-Arduino-and-OpenC/
