//---------------------------------��ͷ�ļ��������ռ�������֡�---------------------------
//          ����������������ʹ�õ�ͷ�ļ��������ռ�
//-----------------------------------------------------------------------------------------------
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "stdio.h"
using namespace cv;

int main()
{
	// ����Դͼ��
	Mat srcImage, dstImage;
	srcImage = imread("1111.jpg", 1);
	if (!srcImage.data) { printf("��ȡͼƬ���� \n"); return false; }

	// תΪ�Ҷ�ͼ
	cvtColor(srcImage, srcImage, COLOR_BGR2GRAY);

	// ֱ��ͼ���⻯
	equalizeHist(srcImage, dstImage);

	// ��ʾ���
	namedWindow("ԭʼͼ", WINDOW_NORMAL);
	namedWindow("ֱ��ͼ�����", WINDOW_NORMAL);
	imshow("ԭʼͼ", srcImage);
	imshow("ֱ��ͼ�����", dstImage);

	// �ȴ��û������˳�����
	waitKey(0);
	return 0;

}