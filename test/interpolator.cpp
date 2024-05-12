#include "interpolator.h"

cv::Mat bilinearInterpolator::getFrame(cv::Mat frame, cv::Size size)
{
    double xScale = 1.*frame.cols/size.width,
           yScale = 1.*frame.rows/size.height;
    int channels = frame.channels();

    cv::Mat result(size.height, size.width, frame.type());

    for(int c = 0; c < channels; ++c)
    {
        for(double i = 0.5; i < size.width; ++i)
        {
            for(double j = 0.5; j < size.height; ++j)
            {
                double x = i * xScale, y = j * yScale; // координаты центра текущего пикселя в старой картинке
                int xLeft = floor(x - 0.5) >= 0  ? floor(x - 0.5) : 0,
                    yLeft = floor(y - 0.5) >= 0 ? floor(y - 0.5) : 0;

                double A = frame.at<cv::Vec3b>(yLeft, xLeft)[c]*((xLeft + 1.) - x + 0.5) +
                           frame.at<cv::Vec3b>(yLeft, xLeft + 1)[c]*(x - xLeft - 0.5);
                double B = frame.at<cv::Vec3b>(yLeft + 1, xLeft)[c]*((xLeft + 1.) - x + 0.5) +
                           frame.at<cv::Vec3b>(yLeft + 1, xLeft + 1)[c]*(x - xLeft - 0.5);

                // !!! Vec3b will not work with all types of video
                double color =  A*(yLeft + 1 - y + 0.5) + B*(y - yLeft - 0.5);
                result.at<cv::Vec3b>(floor(j), floor(i))[c] = color;
            }
        }
    }
    return result;
}

/*
                //std::cout << "i: " << i << " j: " << j <<  " c: " << c << std::endl;
                double x = i * xScale, y = j * yScale; // координаты центра текущего пикселя в старой картинке
                int xLeft = floor(x + 0.5), yLeft = floor(y + 0.5); // верхний левый угол в старой, мб надо сделать -0.5
                //std::cout << "Left top: " << xLeft << " " << yLeft << std::endl;

                double fx = ((x + 0.5) * xScale - 0.5) - floor((x + 0.5) * xScale - 0.5);
                double fy = ((y + 0.5) * yScale - 0.5) - floor((y + 0.5) * yScale - 0.5);
                //std::cout << "f: " << fx << " " << fy << std::endl;

                // !!! Vec3b will not work with all types of video
                double color = frame.at<cv::Vec3b>(yLeft, xLeft)[c] * (1 - fy) * (1 - fx) +
                               frame.at<cv::Vec3b>(yLeft + 1, xLeft)[c] * fy * (1 - fx)   +
                               frame.at<cv::Vec3b>(yLeft, xLeft + 1)[c] * (1 - fy) * fx   +
                               frame.at<cv::Vec3b>(yLeft + 1, xLeft + 1)[c] * fy * fx;
                //std::cout << "color " << color << std::endl;
                //std::cout << "To: " << floor(i) << " " << floor(j) << std::endl;
                result.at<cv::Vec3b>(floor(j), floor(i))[c] = color;
*/
