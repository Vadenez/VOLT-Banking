
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
#include "cvui/cvui.h"



//for cvui and OpenCV functionality ease of access
using namespace cv;
using namespace cvui;


//then one of my header files
#include "headers/config.h"


//put before "functions" header, so i don't have to restate it
Configs cfg;
UserPassChecker passCk;


//my other header file
#include "headers/functions.h"



//global variables, so they dont get restated
int win = 1;
bool debug;


//Window is named
#define WINDOW_NAME "VOLT Banking"


// Get the horizontal and vertical screen sizes in pixel
void GetDesktopResolution(int& horizontal, int& vertical){

	RECT desktop;

	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();

	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);

	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
}


//Creates a spash screen, for the start of application
void splashScreen(){

	//Variables needed for creating the spash screen location
	int horizontal, vertical;

	//names window
	#define SPLASHSCREEN_NAME "Starting"

	//gets the image that will be used
	Mat voltSplashScreen = imread("cfg/image/VOLTSplashScreen.jpg");

	//loads image
	Mat frame = voltSplashScreen.clone();
	Mat doubleBuffer = frame.clone();

	//initalizes splash screen window
	init(SPLASHSCREEN_NAME, 20);

	//gets the Desktops resolution
	GetDesktopResolution(horizontal, vertical);

	//gets the location thats needed to center the splash screen
	horizontal = (horizontal / 2) - 150;
	vertical = (vertical / 2) - 150;

	//creates loop for displaying the spash screen
	for (int second = 0; second < 6; second++) {

		doubleBuffer.copyTo(frame);

		cvui::imshow(SPLASHSCREEN_NAME, frame);

		//moves splash screen to the middle of screen
		cvMoveWindow("Starting", horizontal, vertical);

		//allows for exit of application via Escape button (may not work)
		if (waitKey(20) == 27)
			exit(0);

		//stops code for 1 second
		sleep_for(milliseconds(750));

	}

	//deletes the splash screen window
	destroyWindow("Starting");
	
}


void begin(Mat& theWhere, Mat& dualBuff) {

	//creates background
	dualBuff.copyTo(theWhere);

	//loads current Debug mode
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

	//Shows a clickable link to my github page in the bottom left corner
	textRect(theWhere, 10, 690, 694, "By Vadenez, or Joseph Lavoie", 201, 20, 0xFFFFFF, 0x000000);
	int vad = iarea(0, 690, 201, 50);
	if (vad == OVER)
		text(theWhere, 16, 670, "https://github.com/Vadenez");
	if (vad == CLICK)
		ShellExecute(0, 0, L"https://github.com/Vadenez", 0, 0, SW_SHOW);

}


void end(Mat& theWhere) {

	//updates the mouse clicks every "frame"
	cvui::imshow(WINDOW_NAME, theWhere);

	//allows for exit durring sign up and sign in screen, by pressing ESC 
	if (waitKey(20) == 27) {
		exit(0);
	}
}