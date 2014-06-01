// demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv.hpp>
#include <iostream>
#include <string>
using namespace std;

#include <highgui\highgui.hpp>
#include <core/core.hpp>
  #include <imgproc/imgproc.hpp>
int main()
{   
    const char* imagename = "E:/33.jpg"; //随便放一张jpg图片在D盘或另行设置目录
    cv::Mat img = cv::imread(imagename);
    if(img.empty())return -1; //是否加载成功
    if(!img.data)return -1;
    cv::namedWindow("image", CV_WINDOW_AUTOSIZE);
    cv::imshow("image", img);
    cv::waitKey();
    return 0;
}
