// blendPic.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
using namespace std;
using namespace cv;

int main( int argc, char** argv )
{
 double alpha = 0.5; double beta; double input;

 Mat src1, src2, dst;

 /// Ask the user enter alpha
  cout<<" Simple Linear Blender "<<std::endl;
  cout<<"-----------------------"<<std::endl;
 std::cout<<"* Enter alpha [0-1]: ";
 std::cin>>input;

 /// We use the alpha provided by the user if it is between 0 and 1
 if( input >= 0.0 && input <= 1.0 )
   { alpha = input; }

 /// Read image ( same size, same type )
 src1 = imread("E:/23.jpg");
 src2 = imread("E:/22.jpg");

 if( !src1.data ) { printf("Error loading src1 \n"); return -1; }
 if( !src2.data ) { printf("Error loading src2 \n"); return -1; }

 /// Create Windows
 namedWindow("Linear Blend", CV_WINDOW_AUTOSIZE);

  //imshow( "Linear Blend", src2 );
 beta = ( 1.0 - alpha );
 addWeighted(src1, alpha, src2, beta, 7.0, dst);

 imshow( "Linear Blend", dst );

 waitKey(0);
 return 0;
}