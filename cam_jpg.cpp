// cam_jpg.cpp : �������̨Ӧ�ó������ڵ㡣
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
   p[1] = 10;  //����ֵ  
   p[2] = 0;  


	int n;
	if(!capture) //������ܴ�����ͷ��������
	{
		cout<<"Can not open the camera."<<endl;
		return -1;
	}
	else
	{
		frame=cvQueryFrame(capture); //����ȡ������ͷ�е�һ֡
		int frameH    = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);  
		frame1=cvQueryFrame(capture); //����ȡ������ͷ�е�һ֡
		int frameW    = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
		
		int fps       = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);  
		int numFrames = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
		frame=cvQueryFrame(capture); //����ȡ������ͷ�е�һ֡
		img = cvRetrieveFrame(capture);
		video=cvCreateVideoWriter("camera.avi",-1,15,cvSize(frame->width,frame->height)); //����CvVideoWriter���󲢷���ռ�
		//������ļ���Ϊcamera.avi������Ҫ�����г���ʱѡ�񣬴�С��������ͷ��Ƶ�Ĵ�С��֡Ƶ����32
		if(video) //����ܴ���CvVideoWriter����������ɹ�
		{
			cout<<"VideoWriter has created."<<endl;
		}
		cvNamedWindow("Camera Video",1); //�½�һ������
		while(1)
		{
			frame=cvQueryFrame(capture); //��CvCapture�л��һ֡
			 
			if(!frame)
			{
				cout<<"Can not get frame from the capture."<<endl;
				break;
			}




			n=cvWriteFrame(video,frame); //�ж��Ƿ�д��ɹ���������ص���1����ʾд��ɹ�
			cout<<n<<endl;

			cvShowImage("Camera Video",frame); //��ʾ��Ƶ���ݵ�ͼƬ

			pSaveFrame=cvCreateImage(cvSize(frame->width,frame->height),frame->depth,frame->nChannels); 
			sprintf_s(filename,"%d.jpg",i);
			i++;
			cvResize(frame,pSaveFrame,CV_INTER_LINEAR);  
           cvSaveImage(filename,pSaveFrame,p);  
           cvReleaseImage(&pSaveFrame); 

			if(cvWaitKey(1)>0) break; //������������Ӧ�����˳�
		}
		cvReleaseVideoWriter(&video);
		cvReleaseCapture(&capture);
		cvDestroyWindow("Camera Video");
	}
	return 0;
}