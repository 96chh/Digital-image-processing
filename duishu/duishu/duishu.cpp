#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>  
using namespace cv;
using namespace std;

void main()
{   // ����ͼƬ
	Mat srcImage = imread("0.jpg", 1);
		if (!srcImage.data)
			cout << "����ͼ�����" << endl;
	// �����ԭʼͼ���С����һ�µ�Ŀ��ͼ��
	Mat resultImage = Mat::zeros(srcImage.size(), srcImage.type());

	// �����任
	double gray = 0;
	for (int i = 0; i < srcImage.rows; i++)
	{
		for (int j = 0; j < srcImage.cols*srcImage.channels(); j++)
		{
			gray = (double)srcImage.at<uchar>(i, j);
			// �����任
			gray = 30*log((double)(1 + gray));
			// saturate_cast ���ã�����255,���Ϊ255��С��0�����Ϊ0
			resultImage.at<uchar>(i, j) = saturate_cast<uchar>(gray);
		}
	}
	//��һ������  
	normalize(resultImage, resultImage, 0, 255, NORM_MINMAX);
	//ת����8bitͼ����ʾ  
	convertScaleAbs(resultImage, resultImage);
	namedWindow("ԭʼͼ");
	namedWindow("�����任���ͼ");

	imshow("�����任���ͼ",resultImage);
	imshow("ԭʼͼ", srcImage);
	waitKey(0);
}