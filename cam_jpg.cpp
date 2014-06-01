// cam_jpg.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

int main()
{
	 IplImage* pSaveFrame=NULL; 


	CvCapture* capture=cvCaptureFromCAM(0);
	 //VideoCapture capture(0);
	CvVideoWriter* video=NULL;
	IplImage* frame=NULL;
	IplImage* frame1=NULL;
	IplImage* img=NULL;
	
	char filename[20];
	int i=0;
	int p[3];  
   p[0] = CV_IMWRITE_JPEG_QUALITY;  
   p[1] = 10;  //质量值  
   p[2] = 0;  


	int n;
	if(!capture) //如果不能打开摄像头给出警告
	{
		cout<<"Can not open the camera."<<endl;
		return -1;
	}
	else
	{
		frame=cvQueryFrame(capture); //首先取得摄像头中的一帧
		int frameH    = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);  
		frame1=cvQueryFrame(capture); //首先取得摄像头中的一帧
		int frameW    = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
		
		int fps       = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);  
		int numFrames = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
		frame=cvQueryFrame(capture); //首先取得摄像头中的一帧
		img = cvRetrieveFrame(capture);
		video=cvCreateVideoWriter("camera.avi",-1,15,cvSize(frame->width,frame->height)); //创建CvVideoWriter对象并分配空间
		//保存的文件名为camera.avi，编码要在运行程序时选择，大小就是摄像头视频的大小，帧频率是32
		if(video) //如果能创建CvVideoWriter对象则表明成功
		{
			cout<<"VideoWriter has created."<<endl;
		}
		cvNamedWindow("Camera Video",1); //新建一个窗口
		while(1)
		{
			frame=cvQueryFrame(capture); //从CvCapture中获得一帧
			 
			if(!frame)
			{
				cout<<"Can not get frame from the capture."<<endl;
				break;
			}




			n=cvWriteFrame(video,frame); //判断是否写入成功，如果返回的是1，表示写入成功
			cout<<n<<endl;

			cvShowImage("Camera Video",frame); //显示视频内容的图片

			pSaveFrame=cvCreateImage(cvSize(frame->width,frame->height),frame->depth,frame->nChannels); 
			sprintf_s(filename,"%d.jpg",i);
			i++;
			cvResize(frame,pSaveFrame,CV_INTER_LINEAR);  
           cvSaveImage(filename,pSaveFrame,p);  
           cvReleaseImage(&pSaveFrame); 

			if(cvWaitKey(1)>0) break; //有其他键盘响应，则退出
		}
		cvReleaseVideoWriter(&video);
		cvReleaseCapture(&capture);
		cvDestroyWindow("Camera Video");
	}
	return 0;
}