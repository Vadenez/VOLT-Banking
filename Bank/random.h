using namespace cv;
using namespace cvui;

using namespace std;

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
string numpad(Mat &theWhere, int theX, int theY, int type = 1, std::string name = "Numpad", unsigned int nameColor = 0xFFFFFF, unsigned int color = DEFAULT_BUTTON_COLOR) {

	static string num;
	string value;
	bool del = 0;
	rect(theWhere, theX, theY, 168, 40, 0xb8b8b8, color);

	text(theWhere, theX + 5, theY + 10, name, 1.5 * DEFAULT_FONT_SCALE, nameColor);

	if (button(theWhere, theX, theY + 40, "7", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "7";
	}
	if (button(theWhere, theX + 55, theY + 40, "8", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "8";
	}
	if (button(theWhere, theX + 110, theY + 40, "9", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "9";
	}
	if (button(theWhere, theX, theY + 80, "4", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "4";
	}
	if (button(theWhere, theX + 55, theY + 80, "5", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "5";
	}
	if (button(theWhere, theX + 110, theY + 80, "6", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "6";
	}
	if (button(theWhere, theX, theY + 120, "1", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "1";
	}
	if (button(theWhere, theX + 55, theY + 120, "2", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "2";
	}
	if (button(theWhere, theX + 110, theY + 120, "3", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "3";
	}
	if (button(theWhere, theX, theY + 160, "0", 1.5 * DEFAULT_FONT_SCALE, color)) {
		value = "0";
	}
	if (button(theWhere, theX + 55, theY + 160, 113, 40, "Del", 1.5 * DEFAULT_FONT_SCALE, color)) {
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

		return num;
	}
	if (type == 1) {
		if (del == 1)
			num = " ";
		else
			num = value;
	}
	

}
/**
Not developed yet...
*/
string keyBoard(Mat& theWhere, int theX, int theY, std::string name = "Numpad", unsigned int nameColor = 0xFFFFFF, unsigned int color = DEFAULT_BUTTON_COLOR) {
	static string out;
	string key;
	bool del = 0;

	rect(theWhere, theX, theY, 168, 40, 0xb8b8b8, color);

	text(theWhere, theX + 5, theY + 10, name, 1.5 * DEFAULT_FONT_SCALE, nameColor);

	if (button(theWhere, theX, theY + 40, 113, 40, "Del", 1.5 * DEFAULT_FONT_SCALE, color)) {
		key = "    ";
	}



	if (std::size(out) <= 0 && del == 1)
		out = out;

	else if (del == 1) {
		out.erase(std::prev(out.end()));
	}
	else
		out += key;

	return key;
}

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
void textRect(cv::Mat& theWhere, int theX, int theY, int textY, string theText, int theWidth, int theHeight, unsigned int theBorderColor = 0xc9c9c9, unsigned int theFillingColor = 0x676054, double theFontScale = DEFAULT_FONT_SCALE, unsigned int textColor = 0xCECECE) {
	

	rect(theWhere, theX, theY, theWidth, theHeight, theBorderColor, theFillingColor);

	cvui::text(theWhere, (theX + 5), textY, theText, theFontScale);

}