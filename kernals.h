//
// Created by maverick on 9/8/22.
//

#ifndef kernals
#define kernals

#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
#include<math.h>

using namespace std;


cv::Mat gaussian2d(int size, int sigma){
    cv::Mat filter = cv::Mat::zeros(size,size, CV_32F);
    size /= 2;

    float norm = 1/(2*M_PI*sigma*sigma);
    float sum = 0;

    for(int i=-size; i<size+1; i++){
        for(int j=-size; j<size+1; j++) {
            float calc = exp((-(pow(i,2)+pow(j,2))/(2*pow(sigma,2))));
            calc *= norm;
            filter.at<float>(j+size, i+size) = calc;
            sum += calc;
        }
    }

//    for(int i=-size; i<; i++){
//        for(int j=0; j<3; j++){
//            filter.at<float>(j,i) /= sum;
//        }
//        cout << "\n";
//    }

    return filter/sum;
}


cv::Mat sobelX() {
    cv::Mat filter = (cv::Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
    return filter;
}
cv::Mat sobelY() {
    cv::Mat filter = (cv::Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
    return filter;
}

#endif //kernals
