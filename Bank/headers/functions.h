using namespace cv;
using namespace cvui;

/**
creates a number pad (like the one on your keyboard), it will be placed at the X and Y cords.

WARNING: All numbers are outputed in string format, not int or float.


\param theWhere frame where its rendered.
\param theX the X cordinate.
\param theY the Y cordinate.
\param type, type 1 will rewrite your string, but type 0 will add to your string.
\param name The name of the numpad.
\param nameColor the color of the text.
\param color Is the color of the whole Number pad.

\sa rect()
\sa text()
\sa button()
*/
std::string numpad(Mat &theWhere, int theX, int theY, int type = 1, std::string name = "Numpad", unsigned int nameColor = 0xFFFFFF, unsigned int color = DEFAULT_BUTTON_COLOR) {

	static string num;
	string value;
	bool del = 0;
	rect(theWhere, theX, theY, 120, 40, 0xb8b8b8, color);

	text(theWhere, theX + 5, theY + 10, name, 1.5 * DEFAULT_FONT_SCALE, nameColor);

	if (button(theWhere, theX, theY + 40, 40, 40, "7", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "7";
	}
	if (button(theWhere, theX + 40, theY + 40, 40, 40, "8", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "8";
	}
	if (button(theWhere, theX + 80, theY + 40, 40, 40, "9", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "9";
	}
	if (button(theWhere, theX, theY + 80, 40, 40, "4", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "4";
	}
	if (button(theWhere, theX + 40, theY + 80, 40, 40, "5", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "5";
	}
	if (button(theWhere, theX + 80, theY + 80, 40, 40, "6", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "6";
	}
	if (button(theWhere, theX, theY + 120, 40, 40, "1", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "1";
	}
	if (button(theWhere, theX + 40, theY + 120, 40, 40, "2", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "2";
	}
	if (button(theWhere, theX + 80, theY + 120, 40, 40, "3", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "3";
	}
	if (button(theWhere, theX, theY + 160, 40, 40, "0", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "0";
	}
	if (button(theWhere, theX + 40, theY + 160, 80, 40, "Del", 1.5 * DEFAULT_FONT_SCALE, color)) {
		del = 1;
	}

	if (type == 0) {
		if (std::size(num) <= 0 && del == 1)
			num = num;

		else if (del == 1) {
			num.erase(std::prev(num.end()));
		}
		else
			num += value;

	}
	if (type == 1) {
		if (del == 1)
			num = " ";
		else
			num = value;
	}
	
	return num;
}
/**
Not developed yet...
*/
std::string keyboard(Mat& theWhere, int theX, int theY, std::string name = "Keyboard", unsigned int nameColor = 0xFFFFFF, unsigned int color = DEFAULT_BUTTON_COLOR) {
	static string out;
	string key;
	bool del = 0, caps = 0;

	rect(theWhere, theX, theY, 320, 40, 0xb8b8b8, color);

	text(theWhere, theX + 5, theY + 10, name, 1.5 * DEFAULT_FONT_SCALE, nameColor);

	if (button(theWhere, theX + 320, theY, 79, 41, "      <--", DEFAULT_FONT_SCALE, color)) {
		del = 1;
	}
	if (caps == 0) {
		if (button(theWhere, theX, theY + 40, 40, 40, "q", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "q";
		}
		if (button(theWhere, theX + 40, theY + 40, 40, 40, "w", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "w";
		}
		if (button(theWhere, theX + 80, theY + 40, 40, 40, "e", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "e";
		}
		if (button(theWhere, theX + 120, theY + 40, 40, 40, "r", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "r";
		}
		if (button(theWhere, theX + 160, theY + 40, 40, 40, "t", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "t";
		}
		if (button(theWhere, theX + 200, theY + 40, 40, 40, "y", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "y";
		}
		if (button(theWhere, theX + 240, theY + 40, 40, 40, "u", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "u";
		}
		if (button(theWhere, theX + 280, theY + 40, 40, 40, "i", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "i";
		}
		if (button(theWhere, theX + 320, theY + 40, 40, 40, "o", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "o";
		}
		if (button(theWhere, theX + 360, theY + 40, 40, 40, "p", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "p";
		}
		if (button(theWhere, theX + 10, theY + 80, 40, 40, "a", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "a";
		}
		if (button(theWhere, theX + 50, theY + 80, 40, 40, "s", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "s";
		}
		if (button(theWhere, theX + 90, theY + 80, 40, 40, "d", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "d";
		}
		if (button(theWhere, theX + 130, theY + 80, 40, 40, "f", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "f";
		}
		if (button(theWhere, theX + 170, theY + 80, 40, 40, "g", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "g";
		}
		if (button(theWhere, theX + 210, theY + 80, 40, 40, "h", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "h";
		}
		if (button(theWhere, theX + 250, theY + 80, 40, 40, "j", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "j";
		}
		if (button(theWhere, theX + 290, theY + 80, 40, 40, "k", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "k";
		}
		if (button(theWhere, theX + 330, theY + 80, 40, 40, "l", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "l";
		}
		if (button(theWhere, theX + 30, theY + 120, 40, 40, "z", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "z";
		}
		if (button(theWhere, theX + 70, theY + 120, 40, 40, "x", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "x";
		}
		if (button(theWhere, theX + 110, theY + 120, 40, 40, "c", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "c";
		}
		if (button(theWhere, theX + 150, theY + 120, 40, 40, "v", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "v";
		}
		if (button(theWhere, theX + 190, theY + 120, 40, 40, "b", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "b";
		}
		if (button(theWhere, theX + 230, theY + 120, 40, 40, "n", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "n";
		}
		if (button(theWhere, theX + 270, theY + 120, 40, 40, "m", 1.5 * DEFAULT_FONT_SCALE, color)) {
			key = "m";
		}

	}
	



	if (std::size(out) <= 0 && del == 1)
		out = out;

	else if (del == 1) {
		out.erase(std::prev(out.end()));
	}
	else
		out += key;

	return out;
}

//string keyboardAndNumpad ()

/**
Creates text(), but with a box around it, for contrast from background.

\param theWhere frame where its rendered.
\param theX the X cordinate.
\param theY the Y cordinate.
\param textY helps align text into the box.
\param theWidth width of the box.
\param theHeight height of the box.
\param theBorderColor color of text box's border in the format `0xRRGGBB`, e.g. `0xff0000` for red.
\param theFillingColor color of rectangle's filling in the format `0xAARRGGBB`, e.g. `0x00ff0000` for red, `0xff000000` for transparent filling.
\param theFontScale the size of text, not the box.
\param textColor the color of the text.

\sa rect()
\sa text()
*/
void textRect(cv::Mat& theWhere, int theX, int theY, int textY, std::string theText, int theWidth, int theHeight, unsigned int theBorderColor = 0xc9c9c9, unsigned int theFillingColor = 0x676054, double theFontScale = DEFAULT_FONT_SCALE, unsigned int textColor = 0xCECECE) {
	

	rect(theWhere, theX, theY, theWidth, theHeight, theBorderColor, theFillingColor);

	cvui::text(theWhere, (theX + 5), textY, theText, theFontScale);

}