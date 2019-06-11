#include "opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/highgui.hpp"
#include <stdio.h>
#include<stdint.h>
#include <iostream>

using namespace cv;
using namespace std;

const int fps = 20;
int main(int argc, char** argv) {

	Mat frame;

	VideoCapture vid(0);

	if (!vid.isOpened()) {
		return -1;
	}

	while (true) {
		vid >> frame;
		imshow("Camera", frame);

		Mat gray, edge, draw;
		cvtColor(frame, gray, COLOR_BGR2GRAY);

		Canny(gray, edge, 20, 300, 3);

		edge.convertTo(draw, CV_8U);
		namedWindow("EdgeDetected", WINDOW_AUTOSIZE);
		imshow("EdgeDetected", draw);

		if (waitKey(1000 / fps) >= 0)
			break;
	}
	return 1;
}

