#include <iostream>  
#include <opencv2/opencv.hpp>  

using namespace std;
using namespace cv;

int main()
{

	//����ͼƬ  
	Mat src = imread("0.jpg"), dst = imread("0.jpg");
	if (!src.data)
	{
		cout << "��ͼ�����" << endl;
		return -1;
	}
	//��ȡͼ����Ϣ  
	int height = src.rows;
	int width = src.cols* src.channels();   // ����Ҫ��ͨ����  

	//ͼ��ת  
	for (int i = 0; i< height; i++)
	{
		for (int j = 0; j< width; j++)
		{
			dst.at<uchar>(i, j) = 255 - src.at<uchar>(i, j);   // ÿһ�����ط�ת  
		}
	}

	//��ʾͼƬ  
	namedWindow("ԭͼ��", WINDOW_NORMAL);
	namedWindow("��ת���ͼ��", WINDOW_NORMAL);
	imshow("��ת���ͼ��", dst);
	imshow("ԭͼ��", src);

	waitKey(0);
	return 0;
}