#include <iostream>
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace ::std;
using namespace ::cv;

int main()
{
	//ͼ���ȡ
	Mat src = imread("0.bmp", 0);

	//�ж�ͼ���ȡ�Ƿ�������
	if (!src.data)
	{
		cout << "ͼ���ȡ����!" << endl;
		return 0;
	}

	//ԭʼͼ����ʾ
	namedWindow("ԭͼ��");
	imshow("ԭͼ��", src);
	//Ŀ��ͼ����ԭͼ��ߴ硢����һ��
	Mat dst = Mat::zeros(src.size(), src.type());
	//����Ӧ��ֵ����
	adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, 5);

	imshow("Ч��ͼ", dst);
	waitKey(0);
}

