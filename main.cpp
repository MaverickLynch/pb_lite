#include <iostream>
#include<opencv4/opencv2/opencv.hpp>
#include "kernals.h"
#include<vector>
#include "imageHelper.h"
#include "DoG.h"



int main(int argc, char** argv) {
    if (argc != 2){
        std::cout << "Usage: DisplayImage.out <image_path>\n";
        return -1;
    }

    cv::Mat image;
    image = cv::imread(argv[1], 1);
    if(!image.data){
        std::cout << "No Image data \n";
        return -1;
    }

    //DISPLAYIMG_H::display(image);
    cv::Mat filter = kernals::gaussian2d(3,3);

    cv::Mat gauss_img;

    cv::filter2D(image,gauss_img,-1,filter,{-1,-1},0,cv::BORDER_DEFAULT);
    //display(image);
    //display(gauss_img);

    vector<vector<cv::Mat>> OrientedDoG = DoG::generateDoG(5,{3,5},7);

    std::cout << "Successful";
    return 0;








}
