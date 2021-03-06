// filter2D.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/** @function main */
int main ( int argc, char** argv )
{
  /// Declare variables
  Mat src, dst;

  Mat kernel;
  Point anchor;
  double delta;
  int ddepth;
  int kernel_size;
  char* window_name = "filter2D Demo";

  int c;
  const char* imagefile = "E:/33.jpg";
  /// Load an image
  src = imread( imagefile );
  Mat gray_image;
  cvtColor( src, gray_image, CV_BGR2GRAY );//change the RGB to gray pic--by morgan
  imshow("gray window",gray_image);
  if( !src.data )
  { return -1; }

  /// Create window
  namedWindow( window_name, CV_WINDOW_AUTOSIZE );

  /// Initialize arguments for the filter
  anchor = Point( -1, -1 );
  delta = 0;
  ddepth = -1;

  /// Loop - Will filter the image with different kernel sizes each 0.5 seconds
  int ind = 0;
  while( true )
    {
      c = waitKey(500);
      /// Press 'ESC' to exit the program
      if( (char)c == 27 )
        { break; }

      /// Update kernel size for a normalized box filter
      kernel_size = 3 + 2*( ind%5 );
      kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size); //blur the pic by the kernel function which reduce the px to 1/9 in this example---  by morgan
	  
	  /*
	  kernel = (Mat_<char>(3,3) <<  0, -2,  0,
                               -1,  5, 1,
                                0, -1,  0); //construct the matrix to enhance the contrast of pic --by morgan
		*/
      /// Apply filter
      filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
      imshow( window_name, dst );
      ind++;
    }

  return 0;
}
