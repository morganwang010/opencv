// demo.cpp : �������̨Ӧ�ó������ڵ㡣
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
    const char* imagename = "E:/33.jpg"; //����һ��jpgͼƬ��D�̻���������Ŀ¼
    cv::Mat img = cv::imread(imagename);
    if(img.empty())return -1; //�Ƿ���سɹ�
    if(!img.data)return -1;
    cv::namedWindow("image", CV_WINDOW_AUTOSIZE);
    cv::imshow("image", img);
    cv::waitKey();
    return 0;
}
