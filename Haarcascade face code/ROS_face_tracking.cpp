#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sstream>
#include <std_msgs/Int16.h>
#include <sensor_msgs/Image.h>
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;

#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480

cv::VideoCapture cap;

int main(int argc, char** argv){

    int count = 0;
    ros::init(argc, argv, "camera_driver");
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub = it.advertise("frame_raw", 1);

    cap.open(1);
    cap.set(3, IMAGE_WIDTH);
    cap.set(4, IMAGE_HEIGHT);

    cv::Mat img;

    // Load cascate classifier placed in sulution folder
     cv::CascadeClassifier detector;
     string cascadeName = "/home/phoenix/Desktop/data/haarcascades/haarcascade_frontalface_alt.xml";
     bool loaded = detector.load(cascadeName);
    // Parameters of detectMultiscale Cascade Classifier
     int groundThreshold = 2;
     double scaleStep = 1.1;
     cv::Size minimalObjectSize(80, 80);
     cv::Size maximalObjectSize(200, 200);

    // Vector of returned faces
     vector< cv::Rect_<int> > found;

     for (;;)
     {

          cap >> img;

          // Convert input to greyscale
          cv::Mat image_grey;
          cv::cvtColor(img, image_grey, CV_BGR2GRAY);

          found.clear();

          // Detect faces
          detector.detectMultiScale(image_grey, found, scaleStep, groundThreshold, 0 | cv::CASCADE_SCALE_IMAGE, minimalObjectSize,maximalObjectSize);

          // Draw the results into mat retrieved from webcam
          if (found.size() > 0) {
                for (int i = 0; i <= found.size() - 1; i++) {
                 cv::rectangle(img, found[i].br(), found[i].tl(), cv::Scalar(0, 255, 0), 5, 8, 0);
                 }
          }

        //Show the results

         cv::imshow("Face detection", img);
         cv::waitKey(10);

     }
     return 0;
}

