#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat src, dst;

void main()
{
	src = imread("0.jpg", 0);
	if (!src.data) {
		printf("��ȡͼƬ����! \n");
	}
	imshow("ԭʼͼ", src);
	//ʹ��otsu����
	threshold(src, dst, 100, 255, THRESH_OTSU);
	imshow("Ч��ͼ", dst);
	waitKey(0);
}
