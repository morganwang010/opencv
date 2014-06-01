// cam_capture.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	const char* imagename = "E:/33.jpg";
   IplImage* image = cvLoadImage(imagename);
   if(image==NULL)
	   exit(1);
   cvNamedWindow("aaa" ,CV_WINDOW_AUTOSIZE);
   uchar *pchar;
   int width = image->width;
   int height = image->height;
   int channel = image->nChannels;
   int widthStep = image->widthStep;
   int i,j;
   for(i=0;i<height;i++)
   {
	   pchar = (uchar*)image->imageData + i*widthStep;
	   for(j=0;j<width;j++)
	   {
		   uchar* temp = pchar + j*channel;
		   temp[0] +=105;
		   temp[1] +=10;
		   temp[2] -=35;


	   }
   }


	   cvShowImage("aaa",image);
	   cvWaitKey(0);
	   cvReleaseImage(&image);
	   cvDestroyWindow("aaa");
   
    return 0;

}
