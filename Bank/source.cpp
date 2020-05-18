
#include "other.h"

int main() {

	//create nesesary bools, and strings
	bool signUp = 0, signIn = 0, ck = 0, check = 0;
	string user, pin;

	//create nesesary background images into the right format
	Mat bg1plus = imread("cfg/image/bg1plus.jpg");
	Mat voltstart = imread("cfg/image/voltstart.jpg");
	Mat bg1 = imread("cfg/image/bg1.jpg");
	Mat bg2 = imread("cfg/image/bg2.jpg");

	//load volt startup background
	Mat frame = voltstart.clone();
	Mat doubleBuffer = frame.clone();

	//initialize the window
	init(WINDOW_NAME, 20);

	//creates startup/loading screen
	while (win == 1 || win == 2) {

		//creates background (I think)
		doubleBuffer.copyTo(frame);
		
		//displays loading in 2 stages
		if (win == 1)
			text(frame, 500, 640, "Loading.", 2);

		if (win == 2)
			text(frame, 500, 640, "Loading..", 2);

		//adds 1 to x, makeing the loading stage change
		win++;

		end(frame);

		//waits 1 second between stages of loading
		sleep_for(seconds(1));

	}

	//load login/signup background
	frame = bg1plus.clone();
	doubleBuffer = frame.clone();

	//for login or signup
	while (win == 3) {

		begin(frame, doubleBuffer);

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

		

		//shows question
		textRect(frame, 20, 50, 60, "What would you like to do?", 530, 52, 0x000000, DEFAULT_BUTTON_COLOR, 1.2, 0xFFFFFF);
		
		

		//Sign up checkbox
		checkbox(frame, 40, 110, "Sign up", &signUp, 0xFFFFFF, 2 * DEFAULT_FONT_SCALE);

		//Sign in checkbox
		checkbox(frame, 40, 400, "Sign in", &signIn, 0xFFFFFF, 2 * DEFAULT_FONT_SCALE);

		//creates numpad in bottom left when sign up and/or sign in checkboxes are checked
		if (signUp == 1 || signIn == 1) {

			//creates keyboard
			user = keyboard(frame, 450, 509);

			//creates numpad
			pin = (numpad(frame, 1025, 509, 0));
		}
			

		//creates window when Sign up is checked
		if (signUp == 1) {

			//creates window
			window(frame, 45, 140, 315, 240, "Create your account", 1.5 * DEFAULT_FONT_SCALE);

			//creates "New Username" text
			text(frame, 50, 185, "New Username", 1.1 * DEFAULT_FONT_SCALE);

			//creates an input for the keyboard
			textRect(frame, 50, 200, 206, user, 300, 25, 0x000000, 0x676054, 1.3 * DEFAULT_FONT_SCALE, 0xFFFFFF);

			//creates "new pin" text
			text(frame, 50, 255, "New Pin", 1.1 * DEFAULT_FONT_SCALE);

			//creates an input for the numpad
			textRect(frame, 50, 270, 276, pin, 300, 25, 0x000000, 0x676054, 1.3 * DEFAULT_FONT_SCALE, 0xFFFFFF);

			//adds "warning: type slowly"
			text(frame, 210, 360, "Warning: Type slowly", 1.1 * DEFAULT_FONT_SCALE);

			//creates "Create" button
			if (button(frame, 70, 330, 113, 40, "Create", 1.5 * DEFAULT_FONT_SCALE) || check == 1) {

				//validation check
				passCk.username = user;
				passCk.pin = pin;
				if ((passCk.check()) == "Check" && check == 0) {

					//Saves created account to cfg/acc/ 
					cfg.save = 1;
					cfg.username = user;
					cfg.pincode = pin;
					cfg.balance = 0;
					cfg.accfile();

					//advances to signup screen
					win = 4;

				}

				//creates error window
				else {
					check = 1;
					rect(frame, 770, 270, 350, 150, DEFAULT_BUTTON_COLOR, 0x00A49400);
					textRect(frame, 770, 270, 276, "Error", 350, 22, DEFAULT_BUTTON_COLOR, 0x007F7300);

					text(frame, 775, 300, "Unfortunatly,");
					text(frame, 775, 320, (passCk.check()));

					if (button(frame, 810, 380, "Try Again"))
						check = 0;

				}

			}

		}

		//creates window when Sign in is checked
		if (signIn == 1) {

			//creates window
			window(frame, 45, 430, 315, 240, "Sign in to your account", 1.5 * DEFAULT_FONT_SCALE);

			//creates "Username" text
			text(frame, 50, 475, "Username", 1.1 * DEFAULT_FONT_SCALE);

			//creates an input for the keyboard
			textRect(frame, 50, 490, 496, user, 300, 25, 0x000000, 0x676054, 1.3 * DEFAULT_FONT_SCALE, 0xFFFFFF);

			//creates "pin" text
			text(frame, 50, 545, "Pin", 1.1 * DEFAULT_FONT_SCALE);

			//creates an input for the numpad
			textRect(frame, 50, 560, 566, pin, 300, 25, 0x000000, 0x676054, 1.3 * DEFAULT_FONT_SCALE, 0xFFFFFF);

			//adds "warning: type slowly"
			text(frame, 210, 650, "Warning: Type slowly", 1.1 * DEFAULT_FONT_SCALE);

			//creates "Login" button
			if (button(frame, 70, 620, 113, 40, "Login", 1.5 * DEFAULT_FONT_SCALE)) {
				//Login
				//Change of background and/or the Ad

			}

		}

		end(frame);

	}

	//load next background
	frame = bg1.clone();
	doubleBuffer = frame.clone();

	//the switching from signup to login
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
		sleep_for(milliseconds(500));

	}

	//load next background
	frame = bg2.clone();
	doubleBuffer = frame.clone();

	signIn = 0;

	//for loging in, without a signup window
	while (win == 7) {

		begin(frame, doubleBuffer);

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
			//user = (inputBox(frame, 70, 160, 167, 400, 30, 10, 0x000000, 0x676054, 1.5 * DEFAULT_FONT_SCALE, 0xFFFFFF));

			//creates "pin" text
			text(frame, 80, 255, "Pin", 1.3 * DEFAULT_FONT_SCALE);

			//creates an input for the numpad on line: 130
			textRect(frame, 70, 280, 287, pin, 400, 30, 0x000000, 0x676054, 1.5 * DEFAULT_FONT_SCALE, 0xFFFFFF);

			//adds "warning: type slowly"
			text(frame, 460, 420, "Warning: Type slowly", 1.3 * DEFAULT_FONT_SCALE);

			//creates "Login" button
			if (button(frame, 100, 380, 150, 50, "Login", 2 * DEFAULT_FONT_SCALE) || check == 1) {
				
				
				//checks if username and pincode are correct
				cfg.username = user;
				cfg.pincode = pin;
				cfg.save = 0;
				cfg.accfile();

				//advances if they are correct
				if (cfg.pincode == pin && cfg.username == user && check == 0)
					win++;
				
				//shows error if they are not correct
				else  {
					check = 1;
					rect(frame, 770, 270, 350, 150, DEFAULT_BUTTON_COLOR, 0x00A49400);
					textRect(frame, 770, 270, 276, "Error", 350, 22, DEFAULT_BUTTON_COLOR, 0x007F7300);

					text(frame, 775, 300, "Unfortunatly,");
					text(frame, 775, 320, "you had the wrong pin and/or username.");

					//self explainitory
					if (button(frame, 810, 380, "Try Again"))
						check = 0;

					//goes back to signup and login screen
					else if (button(frame, 910, 380, "Sign Up")) {
						win = 3;
						main();
					}

					//shows another error, that has only a small entertainment value
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

		end(frame);

	}

	//inbetween of logingin and being into the account
	while (win < 10) {

		//creates background
		doubleBuffer.copyTo(frame);

		//displays text
		if (win == 8)
			text(frame, 500, 640, "Loging in..", 2);
		
		if (win == 9)
			text(frame, 500, 640, "Initializing...", 2);

		//adds 1 to x, makeing the loading stage change
		win++;

		end(frame);

		//waits 1 second between stages of loading
		sleep_for(milliseconds(500));

	}

	//when into the account
	while (win == 9) {
	}

	return 0;
}