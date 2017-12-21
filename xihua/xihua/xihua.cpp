#include<opencv2\opencv.hpp>  
#include<iostream>  
using namespace std;
using namespace cv;

void main()
{
	Mat src = (Mat_<int>(6, 7) << 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	cout << "ԭͼ��" << endl << "" << src << endl << endl;
	Mat dst = src.clone();

	//��������һ
	for (int i = 1; i < src.rows - 1; i++) {
		for (int j = 1; j < src.cols - 1; j++) {
			int p1 = src.at<int>(i, j);
			int p2 = src.at<int>(i - 1, j);
			int p3 = src.at<int>(i - 1, j + 1);
			int p4 = src.at<int>(i, j + 1);
			int p5 = src.at<int>(i + 1, j + 1);
			int p6 = src.at<int>(i + 1, j);
			int p7 = src.at<int>(i + 1, j - 1);
			int p8 = src.at<int>(i, j - 1);
			int p9 = src.at<int>(i - 1, j - 1);

			if (p1 == 1) {
				int sum = p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
				//����һ������1�ĸ���������
				if (2 <= sum && sum <= 6) {
					int count = 0;
					if (p3 - p2 == 1) {
						count++;
					}
					if (p4 - p3 == 1) {
						count++;
					}
					if (p5 - p4 == 1) {
						count++;
					}
					if (p6 - p5 == 1) {
						count++;
					}
					if (p7 - p6 == 1) {
						count++;
					}
					if (p8 - p7 == 1) {
						count++;
					}
					if (p9 - p8 == 1) {
						count++;
					}
					if (p2 - p9 == 1) {
						count++;
					}
					//����������ת����һ�ĸ���Ϊ1
					if (count == 1) {
						//��������������
						if (p2*p4*p6 == 0 && p4*p6*p8 == 0) {
							dst.at<int>(i, j) = 0;
						}
					}
				}
			}
		}

	}

	Mat finally = dst.clone();
	//����������
	for (int i = 1; i < dst.rows - 1; i++) {
		for (int j = 1; j < dst.cols - 1; j++) {
			int p1 = dst.at<int>(i, j);
			int p2 = dst.at<int>(i - 1, j);
			int p3 = dst.at<int>(i - 1, j + 1);
			int p4 = dst.at<int>(i, j + 1);
			int p5 = dst.at<int>(i + 1, j + 1);
			int p6 = dst.at<int>(i + 1, j);
			int p7 = dst.at<int>(i + 1, j - 1);
			int p8 = dst.at<int>(i, j - 1);
			int p9 = dst.at<int>(i - 1, j - 1);

			if (p1 == 1) {
				int sum = p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
				if (2 <= sum && sum <= 6) {
					int count = 0;
					if (p3 - p2 == 1) {
						count++;
					}
					if (p4 - p3 == 1) {
						count++;
					}
					if (p5 - p4 == 1) {
						count++;
					}
					if (p6 - p5 == 1) {
						count++;
					}
					if (p7 - p6 == 1) {
						count++;
					}
					if (p8 - p7 == 1) {
						count++;
					}
					if (p9 - p8 == 1) {
						count++;
					}
					if (p2 - p9 == 1) {
						count++;
					}
					if (count == 1) {
						//�������������������һ��֮ͬ��
						if (p2*p4*p8 == 0 && p2*p6*p8 == 0) {
							finally.at<int>(i, j) = 0;
						}
					}
				}
			}
		}

	}
	cout << "��������һ��" << endl << "" << dst << endl << endl;
	cout << "������������" << endl << "" << finally << endl << endl;
	system("pause");
}

