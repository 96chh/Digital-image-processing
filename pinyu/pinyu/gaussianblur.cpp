#include<opencv2/opencv.hpp>  
#include<iostream>  
using namespace std;
using namespace cv;
void main()
{
	Mat input = imread("11.bmp", 0);  //�˴�ʡ�Լ���ȡ�Ƿ���ȷ
	imshow("ԭʼͼ", input);

	//�����ʾ�ߴ磬FFTҪ��ߴ�Ϊ2��n�η�
	int w = getOptimalDFTSize(input.cols);
	int h = getOptimalDFTSize(input.rows);

	//����ͼ��߽�
	Mat padded;
	copyMakeBorder(input, padded, 0, h - input.rows, 0, w - input.cols, BORDER_CONSTANT, Scalar::all(0));
	padded.convertTo(padded, CV_32FC1);

	//���Ļ������������ĵ�Ƶ�����Ƶ�����
	//Ҳ����ԭͼ�����-1��x+y�η�
	for (int i = 0; i < padded.rows; i++) {
		float *ptr = padded.ptr<float>(i);
		for (int j = 0; j < padded.cols; j++)
			ptr[j] *= pow(-1, i + j);
	}

	//����ͨ��
	Mat plane[] = { padded,Mat::zeros(padded.size(),CV_32F) };
	Mat complexImg;
	//�ϲ�ͨ����plane Ϊ�հ����飬2��������plane��һ�����ʵ����һ���鲿
	merge(plane, 2, complexImg);
	//�͵���ɢ����Ҷ�任
	dft(complexImg, complexImg);

	//��˹ƽ���˲���
	Mat gaussianBlur(padded.size(), CV_32FC2);
	float D0 = 2 * 10 * 10;
	for (int i = 0; i<padded.rows; i++)
	{
		float*p = gaussianBlur.ptr<float>(i);
		for (int j = 0; j<padded.cols; j++)
		{
			//�˴�Ϊ��ʽ
			float d = pow(i - padded.rows / 2, 2) + pow(j - padded.cols / 2, 2);
			p[2 * j] = expf(-d / D0);
			p[2 * j + 1] = expf(-d / D0);

		}
	}
	//����Ԫ�ض�Ӧ��ˣ����Ǿ������  
	multiply(complexImg, gaussianBlur, gaussianBlur);

	//����ͨ��   
	split(complexImg, plane);
	//��һ������Ϊʵ�����ڶ���Ϊ�鲿�����߶�Ϊ���롣
	//����������Ϊ����ķ��ȣ���ʵ��
	magnitude(plane[0], plane[1], plane[0]);

	//������˹ƽ��Ч��ͼ����任��
	idft(gaussianBlur, gaussianBlur);
	split(gaussianBlur, plane);
	magnitude(plane[0], plane[1], plane[0]);
	normalize(plane[0], plane[0], 1, 0, CV_MINMAX);
	imshow("��˹ƽ���˲�Ч��", plane[0]);

	waitKey();
}