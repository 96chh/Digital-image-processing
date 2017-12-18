#include <iostream>
#include <stdio.h>

//ͼ�����
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace ::std;
using namespace ::cv;

int main()
{
	//ͼ���ȡ
	Mat image = imread("0.jpg");

	//�ж�ͼ���ȡ�Ƿ�������
	if (!image.data)
	{
		cout << "ͼ���ȡ����!" << endl;
		return 0;
	}

	//ԭʼͼ����ʾ
	namedWindow("ԭͼ��", WINDOW_NORMAL);
	imshow("ԭͼ��", image);


	//����ͼ��
	int data_max = 0, data_min = 255;
	int nl = image.rows;
	int nc = image.cols * image.channels();

	int i, j;
	uchar *data;
	//���ͼ��ĻҶ������Сֵ
	for (j = 0; j < nl; j++)
	{
		data = image.ptr<uchar>(j);
		for (i = 0; i < nc; i++)
		{
			if (data[i] > data_max)        data_max = data[i];
			if (data[i] < data_min)        data_min = data[i];
		}
	}
	//�Աȶ�����
	int temp = data_max - data_min;
	for (j = 0; j < nl; j++)
	{
		data = image.ptr<uchar>(j);
		for (i = 0; i < nc; i++)
		{
			data[i] = (data[i] - data_min) * 255 / temp;
		}
	}

	//��ʾͼ��
	namedWindow("�Աȶ������ͼ��", WINDOW_NORMAL);
	imshow("�Աȶ������ͼ��", image);

	waitKey(0);
	return 0;
}
