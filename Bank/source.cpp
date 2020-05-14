#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <windows.h>
#include <shellapi.h>
#pragma comment (lib, "winmm.lib")

#define CVUI_IMPLEMENTATION
#include "inputText.h"
#include "cvui/EnhancedWindow.h"
#include "random.h"
#include "saveStruct.h"
#include <thread>
#include <chrono>

using namespace cv;
using namespace cvui;

using namespace std;
using namespace this_thread;
using namespace chrono;

//Window is named
#define WINDOW_NAME "VOLT Banking"

int win = 0;
bool debug = 0;

int main()
{
	
	Account acc;

	//create nesesary bools, and strings
	bool signUp = 0, signIn = 0, ck = 0, check = 0;
	string user, pin;

	//create nesesary background
	Mat bg1plus = imread("cfg/image/bg1plus.jpg");
	Mat voltstart = imread("cfg/image/voltstart.jpg");
	Mat bg1 = imread("cfg/image/bg1.jpg");
	Mat bg2 = imread("cfg/image/bg2.jpg");

	//load volt startup background
	Mat frame = voltstart.clone();
	Mat doubleBuffer = frame.clone();

	//initialize the window
	init(WINDOW_NAME);

	//creates startup screen
	while (win < 3) {

		//creates background
		doubleBuffer.copyTo(frame);
		
		//displays loading in 3 stages
		if (win == 0)
			text(frame, 500, 640, "Loading.", 2);

		if (win == 1)
			text(frame, 500, 640, "Loading..", 2);

		if (win == 2)
			text(frame, 500, 640, "Loading...", 2);


		cv::imshow(WINDOW_NAME, frame);

		//adds 1 to x, makeing the loading stage change
		win++;

		//allows for exit durring startup screen, by pressing ESC
		if (waitKey(50) == 27) {
			return 1;
		}

		//waits 1 second between stages of loading
		sleep_for(seconds(1));

	}

	//load login/signup background
	frame = bg1plus.clone();
	doubleBuffer = frame.clone();

	while (win == 3) {

		//creates background
		doubleBuffer.copyTo(frame);

		//allows for clickable image of OpenCV
		int opencv = iarea(825, 130, 125, 140);
		if (opencv == OVER)
			text(frame, 820, 295, "https://opencv.org/");
		if (opencv == CLICK)
			ShellExecute(0, 0, L"https://opencv.org/", 0, 0, SW_SHOW);

		//allows for clickable image of cvui
		int cvui = iarea(1025, 130, 125, 140);
		if (cvui == OVER)
			text(frame, 985, 295, "https://github.com/Dovyski/cvui");
		if (cvui == CLICK)
			ShellExecute(0, 0, L"https://github.com/Dovyski/cvui", 0, 0, SW_SHOW);

		//checkbox for "debug mode"
		checkbox(frame, 40, 10, "Debug Mode:", &debug, 0xFFFFFF);

		//preforms debug mode
		if (debug == 1) {

			//shows mouse location
			printf(frame, 1070, 10, "Your mouse is at (%d,%d)", cvui::mouse().x, cvui::mouse().y);

			//shows green "On" beside debug mode
			text(frame, 145, 12, "On", DEFAULT_FONT_SCALE, 0x22FF00);

		}

		//shows red "Off" beside debug mode
		else
			text(frame, 145, 12, "Off", DEFAULT_FONT_SCALE, 0xF90000);

		//shows question
		textRect(frame, 20, 50, 60, "What would you like to do?", 530, 52, 0x000000, DEFAULT_BUTTON_COLOR, 1.2, 0xFFFFFF);
		
		//creates Exit button in bottom left, and allows it to end program
		if (button(frame, 1210, 680, "Exit"))
			return 0;

		//Sign up checkbox
		checkbox(frame, 40, 110, "Sign up", &signUp, 0xFFFFFF, 2 * DEFAULT_FONT_SCALE);

		//Sign in checkbox
		checkbox(frame, 40, 400, "Sign in", &signIn, 0xFFFFFF, 2 * DEFAULT_FONT_SCALE);

		//creates numpad in bottom left when sign up and/or sign in checkboxes are checked
		if (signUp == 1 || signIn == 1)
			pin = (numpad(frame, 1025, 509, 0));

		//creates window when Sign up is checked
		if (signUp == 1) {

			//creates window
			window(frame, 45, 140, 315, 240, "Create your account", 1.5 * DEFAULT_FONT_SCALE);

			//creates "New Username" text
			text(frame, 50, 185, "New Username", 1.1 * DEFAULT_FONT_SCALE);

			//creates an input box
			user = (inputBox(frame, 50, 200, 206, 300, 25, 10, 0x000000, 0x676054, 1.3 * DEFAULT_FONT_SCALE, 0xFFFFFF));

			//creates "new pin" text
			text(frame, 50, 255, "New Pin", 1.1 * DEFAULT_FONT_SCALE);

			//creates an input for the numpad on line: 130
			textRect(frame, 50, 270, 276, pin, 300, 25, 0x000000, 0x676054, 1.3 * DEFAULT_FONT_SCALE, 0xFFFFFF);

			//adds "warning: type slowly"
			text(frame, 210, 360, "Warning: Type slowly", 1.1 * DEFAULT_FONT_SCALE);

			//creates "Create" button
			if (button(frame, 70, 330, 113, 40, "Create", 1.5 * DEFAULT_FONT_SCALE)) {

				//Save login id stuff into file thats named std::string user;
				acc.save = 1;
				acc.username = user;
				acc.pin = pin;
				acc.balance = 0;
				if (debug == 1)
					acc.debug = "On";
				acc.iffy();

				win = 4;

			}

		}

		//creates window when Sign in is checked
		if (signIn == 1) {

			//creates window
			window(frame, 45, 430, 315, 240, "Sign in to your account", 1.5 * DEFAULT_FONT_SCALE);

			//creates "Username" text
			text(frame, 50, 475, "Username", 1.1 * DEFAULT_FONT_SCALE);

			//creates an input box
			user = (inputBox(frame, 50, 490, 496, 300, 25, 10, 0x000000, 0x676054, 1.3 * DEFAULT_FONT_SCALE, 0xFFFFFF));

			//creates "pin" text
			text(frame, 50, 545, "Pin", 1.1 * DEFAULT_FONT_SCALE);

			//creates an input for the numpad on line: 130
			textRect(frame, 50, 560, 566, pin, 300, 25, 0x000000, 0x676054, 1.3 * DEFAULT_FONT_SCALE, 0xFFFFFF);

			//adds "warning: type slowly"
			text(frame, 210, 650, "Warning: Type slowly", 1.1 * DEFAULT_FONT_SCALE);

			//creates "Login" button
			if (button(frame, 70, 620, 113, 40, "Login", 1.5 * DEFAULT_FONT_SCALE)) {
				//Login
				//Change of background and/or the Ad

			}

		}

		
		//updates the mouse clicks every "frame"
		update();

		cv::imshow(WINDOW_NAME, frame);

		//allows for exit durring sign up and sign in screen, by pressing ESC 
		if (waitKey(20) == 27) {
			return 1;
		}

	}

	frame = bg1.clone();
	doubleBuffer = frame.clone();

	while (win < 7) {

		//creates background
		doubleBuffer.copyTo(frame);

		//displays loading in 3 stages
		if (win == 4)
			text(frame, 500, 640, "Creating.", 2);

		if (win == 5)
			text(frame, 500, 640, "Creating..", 2);

		if (win == 6)
			text(frame, 500, 640, "Creating...", 2);


		cv::imshow(WINDOW_NAME, frame);

		//adds 1 to x, makeing the loading stage change
		win++;

		//allows for exit durring startup screen, by pressing ESC
		if (waitKey(50) == 27) {
			return 1;
		}

		//waits 1 second between stages of loading
		sleep_for(seconds(1));

	}

	frame = bg2.clone();
	doubleBuffer = frame.clone();
	signIn = 0;
	while (win == 7) {

		//creates background
		doubleBuffer.copyTo(frame);

		//checkbox for "debug mode"
		checkbox(frame, 40, 10, "Debug Mode:", &debug, 0xFFFFFF);

		//preforms debug mode
		if (debug == 1) {

			//shows mouse location
			printf(frame, 1070, 10, "Your mouse is at (%d,%d)", cvui::mouse().x, cvui::mouse().y);

			//shows green "On" beside debug mode
			text(frame, 145, 12, "On", DEFAULT_FONT_SCALE, 0x22FF00);

		}

		//creates Exit button in bottom left, and allows it to end program
		if (button(frame, 1210, 680, "Exit"))
			return 0;

		//creates numpad in bottom left when sign up and/or sign in checkboxes are checked
		if (signIn == 1)
			pin = (numpad(frame, 1025, 509, 0));

		if (button(frame, 450, 600, 300, 50, "Login to New Account", 1.5 * DEFAULT_FONT_SCALE))
			signIn = 1;

		//creates window when Sign in is checked
		if (signIn == 1) {

			//creates window
			window(frame, 50, 50, 600, 400, "Sign in to your account", 2 * DEFAULT_FONT_SCALE);

			//creates "Username" text
			text(frame, 80, 135, "Username", 1.3 * DEFAULT_FONT_SCALE);

			//creates an input box
			user = (inputBox(frame, 70, 160, 167, 400, 30, 10, 0x000000, 0x676054, 1.5 * DEFAULT_FONT_SCALE, 0xFFFFFF));

			//creates "pin" text
			text(frame, 80, 255, "Pin", 1.3 * DEFAULT_FONT_SCALE);

			//creates an input for the numpad on line: 130
			textRect(frame, 70, 280, 287, pin, 400, 30, 0x000000, 0x676054, 1.5 * DEFAULT_FONT_SCALE, 0xFFFFFF);

			//adds "warning: type slowly"
			text(frame, 460, 420, "Warning: Type slowly", 1.3 * DEFAULT_FONT_SCALE);

			//creates "Login" button
			if (button(frame, 100, 380, 150, 50, "Login", 2 * DEFAULT_FONT_SCALE)) {

				
				acc.username = user;
				acc.pin = pin;
				acc.save = 0;
				acc.iffy();

				if (acc.pin == pin && acc.username == user)
					win++;
				else {
					check = 1;
					rect(frame, 770, 270, 350, 150, DEFAULT_BUTTON_COLOR, 0x00A49400);
					textRect(frame, 770, 270, 276, "Error", 350, 22, DEFAULT_BUTTON_COLOR, 0x007F7300);

					text(frame, 775, 300, "Unfortunatly,");
					text(frame, 775, 320, "you had the wrong pin and/or username.");

					if (button(frame, 810, 380, "Try Again"))
						check = 0;

					else if (button(frame, 910, 380, "Sign Up")) {
						win = 3;
						main();
					}

					else if (button(frame, 1000, 380, "Contact Us")) {
						ck = 1;
					}

					if (ck == 1) {
						rect(frame, 670, 70, 350, 150, DEFAULT_BUTTON_COLOR, 0x003f0000);
						textRect(frame, 670, 70, 76, "Error", 350, 22, DEFAULT_BUTTON_COLOR, 0x00190000);

						text(frame, 675, 100, "Welp that's the thing,");
						text(frame, 675, 120, "their are no employees to help you.");

						if (button(frame, 900, 180, "OK")) {
							ck = 0;
							check = 0;
						}
					}
				
				
				}
			}
			

		}

		//updates the mouse clicks every "frame"
		update();

		cv::imshow(WINDOW_NAME, frame);

		//allows for exit durring startup screen, by pressing ESC
		if (waitKey(50) == 27) {
			return 1;
		}
	}

	while (win < 10) {

		//creates background
		doubleBuffer.copyTo(frame);

		//displays text
		if (win == 8)
			text(frame, 500, 640, "Loging in..", 2);
		
		if (win == 8)
			text(frame, 500, 640, "Initializing...", 2);

		cv::imshow(WINDOW_NAME, frame);

		//adds 1 to x, makeing the loading stage change
		win++;

		//allows for exit durring startup screen, by pressing ESC
		if (waitKey(50) == 27) {
			return 1;
		}

		//waits 1 second between stages of loading
		sleep_for(milliseconds(500));

	}
	while (win == 9) {
		//your into the account
	}
	return 0;
}