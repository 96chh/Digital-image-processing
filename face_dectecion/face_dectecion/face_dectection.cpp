#include <opencv2/core/core.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/opencv.hpp>  

#include <vector>  
#include <cstdio>  

using namespace std;
using namespace cv;

int main()
{

	// ���ط�����  
	CascadeClassifier cascade;
	cascade.load("haarcascade_frontalface_alt2.xml");

	Mat srcImage, grayImage, dstImage;
	// ��ȡͼƬ  
	srcImage = imread("1.jpg");
	dstImage = srcImage.clone();
	imshow("ԭͼ", srcImage);

	grayImage.create(srcImage.size(), srcImage.type());
	// ת��Ϊ�Ҷ�ͼ����߼��Ч��  
	cvtColor(srcImage, grayImage, CV_BGR2GRAY); 

	// ����7����ɫ�����ڱ������  
	Scalar colors[] =
	{
		// ��Ȼ���������  
		CV_RGB(255, 0, 0),
		CV_RGB(255, 97, 0),
		CV_RGB(255, 255, 0),
		CV_RGB(0, 255, 0),
		CV_RGB(0, 255, 255),
		CV_RGB(0, 0, 255),
		CV_RGB(160, 32, 240)
	};

	// ���  
	vector<Rect> rect;
	cascade.detectMultiScale(grayImage, rect, 1.1, 3, 0);  // ���÷���������  

	// ���--��������Բ  
	for (int i = 0; i < rect.size(); i++)
	{
		Point  center;
		int radius;
		center.x = cvRound((rect[i].x + rect[i].width * 0.5));
		center.y = cvRound((rect[i].y + rect[i].height * 0.5));

		radius = cvRound((rect[i].width + rect[i].height) * 0.25);
		circle(dstImage, center, radius, colors[i % 7], 2);
	}

	// ��ʾ  
	namedWindow("Ч��ͼ", WINDOW_NORMAL);
	imshow("Ч��ͼ", dstImage);

	waitKey(0);
	return 0;
}
