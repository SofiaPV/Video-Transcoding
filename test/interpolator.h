#ifndef INTERPOLATOR_H
#define INTERPOLATOR_H

#include <opencv2/opencv.hpp>

class interpolator
{
public:
    virtual cv::Mat getFrame(cv::Mat frame, cv::Size size) = 0;
    //virtual cv::VideoWriter getVideo(cv::VideoCapture* cap, cv::Size size) = 0;
};

class bilinearInterpolator: public interpolator
{
public:
    cv::Mat getFrame(cv::Mat frame, cv::Size size) override;
    //cv::VideoWriter getVideo(cv::VideoCapture* cap, cv::Size size) override;
};
class cubicInterpolator: public interpolator {};


#endif // INTERPOLATOR_H
