
//for config.h's functionality with files
#include <windows.h>
#include <fstream>


//#include <shellapi.h>
#pragma comment (lib, "winmm.lib")


using namespace std;


//for use of "sleep_for()" function
#include <thread>
#include <chrono>
using namespace this_thread;
using namespace chrono;


//for help with cvui
#define CVUI_IMPLEMENTATION


//incluing all used header files, from cvui
#include "cvui/input.h"
#include "cvui/EnhancedWindow.h"


//for cvui and OpenCV functionality ease of access
using namespace cv;
using namespace cvui;


//then one of my header files
#include "headers/config.h"


//put before "functions" header, so i don't have to restate it
Configs cfg;


//my other header file
#include "headers/functions.h"



//global int and bool, so that on line (currently) 311  on "source.cpp" doesnt restate them
int win = 1;
bool debug;

//Window is named
#define WINDOW_NAME "VOLT Banking"

void begin(Mat& theWhere, Mat& dualBuff) {

	//creates background
	dualBuff.copyTo(theWhere);

	cfg.save = 0;
	cfg.settingfile();
	debug = cfg.debug;

	//checkbox for "debug mode"
	checkbox(theWhere, 40, 10, "Debug Mode:", &debug, 0xFFFFFF);

	//preforms debug mode
	if (debug == 1) {

		//shows mouse location
		printf(theWhere, 1070, 10, "Your mouse is at (%d,%d)", cvui::mouse().x, cvui::mouse().y);

		//shows green "On" beside debug mode
		text(theWhere, 145, 12, "On", DEFAULT_FONT_SCALE, 0x22FF00);
		
		cfg.debug = 1;
		cfg.save = 1;
		cfg.settingfile();
	}

	//shows red "Off" beside debug mode
	else {

		text(theWhere, 145, 12, "Off", DEFAULT_FONT_SCALE, 0xF90000);

		cfg.debug = 0;
		cfg.save = 1;
		cfg.settingfile();
	}

	//creates Exit button in bottom left, and allows it to end program
	if (button(theWhere, 1210, 680, "Exit"))
		exit(0);
}

void end(Mat& theWhere) {

	//updates the mouse clicks every "frame"
	cvui::update();

	cv::imshow(WINDOW_NAME, theWhere);

	//allows for exit durring sign up and sign in screen, by pressing ESC 
	if (waitKey(20) == 27) {
		exit(0);
	}
}