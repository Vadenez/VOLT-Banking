#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>


#define CVUI_IMPLEMENTATION
#include "inputText.h"
#include "cvui/EnhancedWindow.h"

#include <thread>
#include <chrono>

using namespace cv;
using namespace cvui;

using namespace std;
using namespace this_thread;
using namespace chrono;

#define WINDOW_NAME "VOLT Banking"

int main(int argc, const char* argv[])
{
	int x = 0;
	bool create = 0, signIn = 0;
	

	Mat back = imread("background.jpg");
	Mat volt = imread("voltback.jpg", IMREAD_COLOR);

	Mat frame = volt.clone();
	Mat doubleBuffer = frame.clone();

	init(WINDOW_NAME);

	while (x < 3) {

		doubleBuffer.copyTo(frame);
		
		if (x == 0)
			text(frame, 500, 640, "Loading.", 2);

		if (x == 1)
			text(frame, 500, 640, "Loading..", 2);

		if (x == 2)
			text(frame, 500, 640, "Loading...", 2);

		cv::imshow(WINDOW_NAME, frame);

		x++;

		if (waitKey(50) == 27) {
			break;
		}

		sleep_for(seconds(1));

	}

	frame = back.clone();
	doubleBuffer = frame.clone();

	while (true) {
		doubleBuffer.copyTo(frame);

		printf(frame, 1000, 50, "Mouse pointer is at (%d,%d)", cvui::mouse().x, cvui::mouse().y);

		text(frame, 20, 50, "Would you like to do?", 1.2, 0xFFFFFF);

		if (button(frame, 1210, 680, "Exit", 1.3 * DEFAULT_FONT_SCALE)) {
			break;
		}
		checkbox(frame, 40, 110, "Sign up", &create, 0xFFFFFF, 2 * DEFAULT_FONT_SCALE);

		checkbox(frame, 40, 400, "Sign in", &signIn, 0xFFFFFF, 2 * DEFAULT_FONT_SCALE);
		
		if (create == 1) {
			window(frame, 45, 140, 500, 240, "Create your account", 1.5 * DEFAULT_FONT_SCALE);

			inputField(frame, 50, 200);
			
		}
		if (signIn == 1) {
			window(frame, 45, 430, 500, 240, "Sign in to your account", 1.5 * DEFAULT_FONT_SCALE);
		}

		

		update();

		cv::imshow(WINDOW_NAME, frame);

		
		if (waitKey(20) == 27) {
			break;
		}
	}

	return 0;
}