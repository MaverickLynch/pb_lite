//
// Created by maverick on 9/9/22.
//

#ifndef DoG
#define DoG

#include<opencv2/opencv.hpp>
#include<vector>
#include "kernals.h"
#include "imageHelper.h"
#include "linespace.h"
using namespace std;

std::vector<vector<cv::Mat>> generateDoG(int orientations, std::vector<int> scales, int size_Gauss){
    std::vector<vector<cv::Mat>> OrientedDoG;
    vector<float> orient = linespace::Linespace<float>(0,360,orientations);


    for(int i: scales){
        vector<cv::Mat> rowDoG;
        for(float j: orient){
            cv::Mat gaussian_kernel = kernals::gaussian2d(size_Gauss,i);
            cv::Mat GxS, RGxS;
            cv::filter2D(gaussian_kernel, GxS, -1, sobelX(), {-1,-1},0,cv::BORDER_DEFAULT);
            imageHelper::rotate(GxS, j, RGxS);
            rowDoG.push_back(RGxS);
        }
        OrientedDoG.push_back(rowDoG);
    }
    for(std::vector<cv::Mat> i: OrientedDoG){
        for(cv::Mat j: i) {
            cout << j << "\n\n";
        }
        cout << "\n\n\n";
    }

}





#endif //DoG
