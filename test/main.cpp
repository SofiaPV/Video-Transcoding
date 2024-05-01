#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
int main()
{
    std::string image_path = "/home/sofia/6semestr/project/1.jpg";
    Mat img = imread(image_path, IMREAD_COLOR);

    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    return 0;
}
