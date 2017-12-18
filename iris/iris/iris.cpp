#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main()
{
	//����ԭͼ
	Mat srcImage = imread("7.jpg"); 
	Mat midImage, dstImage;

	//��ʾԭʼͼ
	imshow("ԭʼͼ", srcImage);

	cvtColor(srcImage, midImage, COLOR_BGR2GRAY);//תΪ�Ҷ�ͼ
	GaussianBlur(midImage, midImage, Size(9, 9), 2, 2);  //��˹�˲���ͼ��ƽ��

	//����Բ�任
	vector<Vec3f> circles;
	HoughCircles(midImage, circles, HOUGH_GRADIENT, 1, 0.001, 90, 30, 0, 80);

	//ͼ�л��Ƴ�Բ
	for (size_t i = 0; i < circles.size(); i++)
	{
		//��������
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		//����Բ��
		circle(srcImage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		//����Բ����
		circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
	}

	//��ʾЧ��ͼ  
	imshow("Ч��ͼ", srcImage);

	waitKey(0);

	return 0;
}