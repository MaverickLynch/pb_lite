//
// Created by maverick on 9/8/22.
//

#ifndef imageHelper
#define imageHelper
#include<opencv2/opencv.hpp>

int display(cv::Mat image){
    cv::namedWindow("DisplayImage", cv::WINDOW_AUTOSIZE);
    cv::imshow("DisplayImage", image);
    cv::waitKey(0);
    return 0;
}

void rotate(cv::Mat& src, double angle, cv::Mat& dst){
    cv::Point2f ptCp(src.cols*0.5, src.rows*0.5);
    cv::Mat M = cv::getRotationMatrix2D(ptCp, angle, 1.0);
    cv::warpAffine(src, dst, M, src.size(), cv::INTER_CUBIC); //Nearest is too rough,
}

#endif //imageHelper
