#ifndef CVER_H
#define CVER_H


#include "opencv/cv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

class CVER
{
public:
    CVER();
    uchar* convert_images(uchar* data, int width, int height) {
        cv::Mat inputMat(1309, 1040,CV_8UC3,data);
        cv::Mat outputMat(width, height, CV_8UC3);
        cv::Size size(width, height);
        cv::resize(inputMat, outputMat, size);
        uchar* x = (uchar*)malloc(height*width * 3);
        uchar* tmp = outputMat.ptr();
        for (int i = 0; i < height*width * 3; ++i){
            x[i] = tmp[i];
        }
        return tmp;
    }
};

#endif // CVER_H
