#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main()
{

	Mat src, src_gray, dst, abs_dst;

	//����ԭʼͼ  
	src = imread("0021m.bmp");  

	//��ʾԭʼͼ 
	imshow("ԭʼͼ", src);

	//ʹ�ø�˹�˲�����������ģ���СΪ9*9
	GaussianBlur(src, src, Size(9, 9), 0, 0, BORDER_DEFAULT);

	//ת��Ϊ�Ҷ�ͼ
	cvtColor(src, src_gray, COLOR_RGB2GRAY);

	//ʹ��Laplace���������ĸ������׾��ߴ�Ϊ5����ģ���СΪ9*9
	Laplacian(src_gray, dst, CV_16S, 5,1, 0, BORDER_DEFAULT);

	//�������ֵ���������ת����8λ
	convertScaleAbs(dst, abs_dst);

	//��ʾЧ��ͼ
	imshow("Ч��ͼ", abs_dst);

	waitKey(0);

	return 0;
}