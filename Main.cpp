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

		Mat frame_gray, edge_det, dst;
		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);

		Canny(frame_gray, edge_det, 20, 300, 3);

		edge.convertTo(dst, CV_8U);
		namedWindow("Output", WINDOW_AUTOSIZE);
		imshow("Output", draw);

		if (waitKey(1000 / fps) >= 0)
			break;
	}
	return 1;
}

