#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>  
using namespace cv;
using namespace std;

void main() {
	Mat src = imread("0.jpg", 1);
	Mat dst = Mat::zeros(src.size(), src.type());
	if (!src.data) {
		cout <<"��ͼ�����" << endl;
	}
	/*���ĸ�������ʾx����Ŵ����������������ʾy����Ŵ���
	����������Ϊ���շŴ���ȡ0,��ʾ�ɵ��ġ����������������
	������������ʾ��������ڲ�ֵ��*/
	resize(src, dst, src.size()*0, 3.0, 3.0, INTER_LANCZOS4);
	imshow("ԭͼ��", src);
	imshow("3*3���Ŵ�˫���Σ�", dst);
	waitKey(0);
}