
#include "other.h"

int main() {

	int signUpStatusUser = 0, signInStatusUser = 0;
	int signUpStatusPin = 0, signInStatusPin = 0;
	int keyboardAreaStatus = 0;

	bool signUp = 0, signIn = 0; 
	
	bool check1 = 0, check2 = 0, check3 = 0;

	bool allowKeyboard = 0, allowNumpad = 0;

	string user, pin;
	
	//create nesesary background images into the right format
	Mat bg1plus = imread("cfg/image/bg1plus.jpg");
	Mat voltstart = imread("cfg/image/voltstart.jpg");

	//Zombie Code:
	//Mat bg1 = imread("cfg/image/bg1.jpg");

	Mat bg2 = imread("cfg/image/bg2.jpg");
	//I need to changfe the name of these ^

	//load volt startup background
	Mat frame = voltstart.clone();
	Mat doubleBuffer = frame.clone();

	//initialize the window
	init(WINDOW_NAME, 20);

	//creates startup/loading screen
	while (win == 1 || win == 2) {




		//fade from voltstart to bg1plus

		

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
		sleep_for(milliseconds(500));

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

			//Dunno how to properly tell you what these if statments do, srry
			if (signUp == 1) {

				signUpStatusUser = iarea(50, 200, 300, 25);
				signUpStatusPin = iarea(50, 270, 300, 25);

			}

			if (signIn == 1) {

				signInStatusUser = iarea(50, 490, 300, 25);
				signInStatusPin = iarea(50, 560, 300, 25);

			}

			//creates the orangeish area around the keyboard or numpad, incase you miss the keyboard ;)
			keyboardAreaStatus = iarea(615, 500, 565, 220);
			rect(frame, 615, 500, 565, 220, 0xc9c9c9, 0x30676054);

			//checks if you are going to be typing in the Username field
			if (((signUpStatusUser == OUT && mouse(DOWN)) || (signInStatusUser == OUT && mouse(DOWN))) && (keyboardAreaStatus == OUT && mouse(DOWN)))
				allowKeyboard = false;

			else if ((signUpStatusUser == CLICK) || (signInStatusUser == CLICK))
				allowKeyboard = true;

			//checks if you are going to be using the Pin field
			if (((signUpStatusPin == OUT && mouse(DOWN)) || (signInStatusPin == OUT && mouse(DOWN))) && (keyboardAreaStatus == OUT && mouse(DOWN)))
				allowNumpad = false;

			else if ((signUpStatusPin == CLICK) || (signInStatusPin == CLICK))
				allowNumpad = true;

			//creates keyboard and numpad for username input
			if (allowKeyboard == true)
				user = fullKeyboard(frame, 625, 509, "For Username");

			//creates numpad for pin input
			if (allowNumpad == true)
				pin = (numpad(frame, 1025, 509, 0, "For Pin"));

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

			//creates "Create" button
			if (button(frame, 70, 330, 113, 40, "Create", 1.5 * DEFAULT_FONT_SCALE) || check1 == 1) {

				//validation check
				passCk.username = user;
				passCk.pin = pin;
				if ((passCk.check()) == "Check" && check1 == 0) {

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
					check1 = 1;
					rect(frame, 770, 270, 350, 150, DEFAULT_BUTTON_COLOR, 0x00A49400);
					textRect(frame, 770, 270, 276, "Error", 350, 22, DEFAULT_BUTTON_COLOR, 0x007F7300);

					text(frame, 775, 300, "Unfortunatly,");
					text(frame, 775, 320, (passCk.check()));

					if (button(frame, 810, 380, "Try Again"))
						check1 = 0;

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

			//creates "Login" button
			if (button(frame, 70, 620, 113, 40, "Login", 1.5 * DEFAULT_FONT_SCALE) || check2 == 1) {
				
				//checks if username and pincode are correct
				cfg.username = user;
				cfg.pincode = pin;
				cfg.save = 0;
				cfg.accfile();

				//advances if they are correct
				if (cfg.pincode == pin && cfg.username == user && check2 == 0)
					win = 8;

				//shows error if they are not correct
				else {
					check2 = 1;
					rect(frame, 400, 350, 350, 150, DEFAULT_BUTTON_COLOR, 0x00A49400);
					textRect(frame, 400, 350, 356, "Error", 350, 22, DEFAULT_BUTTON_COLOR, 0x007F7300);

					text(frame, 405, 380, "Unfortunatly,");
					text(frame, 405, 400, "you had the wrong pin and/or username.");

					//self explainitory
					if (button(frame, 440, 460, "Try Again"))
						check2 = 0;

					//unchecks sign in checkbox, then checks sign up checkbox
					else if (button(frame, 540, 460, "Sign Up")) {
						check2 = 0;
						signIn = 0;
						signUp = 1;

					}

					//shows another error, that has only a small entertainment value
					else if (button(frame, 630, 460, "Contact Us")) {
						check3 = 1;
					}

					if (check3 == 1) {
						rect(frame, 400, 150, 350, 150, DEFAULT_BUTTON_COLOR, 0x003f0000);
						textRect(frame, 400, 150, 156, "Error", 350, 22, DEFAULT_BUTTON_COLOR, 0x00190000);

						text(frame, 405, 180, "Welp that's the thing,");
						text(frame, 405, 200, "their are no employees to help you.");

						if (button(frame, 625, 260, "OK")) {
							check3 = 0;
							check2 = 0;
						}

					}

				}

			}

		}

		end(frame);

	}

	//load next background
	frame = bg2.clone();
	doubleBuffer = frame.clone();

	//defaulting many bool's, so they can be reused
	signIn = 0;
	signUp = 0;
	check1 = 0;
	check2 = 0;
	check3 = 0;

	//for loging in, without a signup window
	while (win == 4) {

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
			if (button(frame, 100, 380, 150, 50, "Login", 2 * DEFAULT_FONT_SCALE) || check1 == 1) {
				
				
				//checks if username and pincode are correct
				cfg.username = user;
				cfg.pincode = pin;
				cfg.save = 0;
				cfg.accfile();

				//advances if they are correct
				if (cfg.pincode == pin && cfg.username == user && check1 == 0)
					win++;
				
				//shows error if they are not correct
				else  {
					check1 = 1;
					rect(frame, 770, 270, 350, 150, DEFAULT_BUTTON_COLOR, 0x00A49400);
					textRect(frame, 770, 270, 276, "Error", 350, 22, DEFAULT_BUTTON_COLOR, 0x007F7300);

					text(frame, 775, 300, "Unfortunatly,");
					text(frame, 775, 320, "you had the wrong pin and/or username.");

					//self explainitory
					if (button(frame, 810, 380, "Try Again"))
						check1 = 0;

					//goes back to signup and login screen
					else if (button(frame, 910, 380, "Sign Up")) {
						win = 3;
						main();
					}

					//shows another error, that has only a small entertainment value
					else if (button(frame, 1000, 380, "Contact Us")) {
						check2 = 1;
					}

					if (check2 == 1) {
						rect(frame, 670, 70, 350, 150, DEFAULT_BUTTON_COLOR, 0x003f0000);
						textRect(frame, 670, 70, 76, "Error", 350, 22, DEFAULT_BUTTON_COLOR, 0x00190000);

						text(frame, 675, 100, "Welp that's the thing,");
						text(frame, 675, 120, "their are no employees to help you.");

						if (button(frame, 900, 180, "OK")) {
							check2 = 0;
							check1 = 0;
						}
					}
				
				
				}
			}
			

		}

		end(frame);

	}

	//inbetween of logingin and being into the account
	while (win == 5) {

		//Logged in fade

	}

	//when into the account
	while (win == 6) {
	}

	return 0;
}