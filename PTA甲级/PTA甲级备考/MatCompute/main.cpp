#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include<opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat m2;
	Mat m1 = Mat(3, 3, CV_32FC1);
	m1.at<float>(0, 0) = 1.23456;
	m1.at<float>(0, 1) = 2.23456;
	m1.at<float>(0, 2) = 3.23456;
	m1.convertTo(m2, CV_64FC1);
	cout << m2;
	return 0;
}

