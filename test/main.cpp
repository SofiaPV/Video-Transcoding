//#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#include "interpolator.h"
//using namespace cv;
//using namespace std;

int main()
{
    // Read the image file
     cv::Mat frame = cv::imread("/home/sofia/6semestr/project/samples/3.jpg");

     // Check for failure
     if (frame.empty())
     {
      std::cout << "Could not open or find the image" << std::endl;
      std::cin.get(); //wait for any key press
      return -1;
     }

     cv::String windowName = "Window"; //Name of the window
     cv::namedWindow(windowName); // Create a window

     bilinearInterpolator biInterp;
     cv::Size size(frame.cols*4, frame.rows*4);
     frame = biInterp.getFrame(frame, size);
     cv::imshow(windowName, frame); // Show our image inside the created window.

     cv::waitKey(0); // Wait for any keystroke in the window
     cv::destroyWindow(windowName); //destroy the created window

     return 0;
}

/*std::string fileName = "/home/sofia/6semestr/project/test2.MOV";
cv::VideoCapture cap(fileName);

if (cap.isOpened() == false)
{
    std::cout << "Cannot open the video file" << std::endl;
    std::cin.get(); //wait for any key press
    return -1;
}

cv::String window_name = "My First Video";
cv::namedWindow(window_name, cv::WINDOW_NORMAL); //create a window

bilinearInterpolator biInterp;
while (true)
{
    cv::Mat frame;
    bool bSuccess = cap.read(frame);
    if (bSuccess == false)
    {
        std::cout << "Found the end of the video" << std::endl;
        break;
    }

    cv::Size size(frame.cols, frame.rows);
    std::cout << "did spmething" << std::endl;
    frame = biInterp.getFrame(frame, size);

    cv::imshow(window_name, frame);

    if (cv::waitKey(10) == 27)
    {
        std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
        break;
    }
}

return 0; */


/*for (int i = 0; i < frame.rows; i++)
    for (int j = 0; j < frame.cols; j++)
        if ((i % 20 == 10 && j % 2 == 1) ||
            (j % 50 == 25 && i % 2 == 1))
        {
            frame.at<Vec3b>(i, j)[0] = 255;
            frame.at<Vec3b>(i, j)[1] = 255;
            frame.at<Vec3b>(i, j)[2] = 255;
        }
*/
