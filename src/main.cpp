#include <iostream>
#include <opencv/cxcore.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;

int main(int argc, char *argv[])
{
	const string green("../data/green.jpg");
	const string red("../data/red.jpg");
	string current = green;
	cvNamedWindow("display", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("display", 100, 100);
	IplImage* img = cvLoadImage(current.c_str(), 1);
	cvShowImage("display", img);
	unsigned int delay = 5;
	for (int key = cvWaitKey(delay);; key = cvWaitKey(delay)) {
		if (key > 0)
			cout << key << endl;
		if (key == 32) {
			//cout << endl << "Spacebar pressed" << endl;
			if (current == green)
				current = red;
			else
				current = green;
			img = cvLoadImage(current.c_str(), 1);
			cvShowImage("display", img);
		} else if (key == 27) {
			break;
		}
	}
	cvReleaseImage(&img);
	return 0;
}
