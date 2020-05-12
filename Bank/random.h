using namespace cv;
using namespace cvui;

using namespace std;

string numpad(Mat &theWhere, int theX, int theY, std::string name = "Numpad", unsigned int nameColor = 0xFFFFFF, unsigned int color = DEFAULT_BUTTON_COLOR) {
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

	if (std::size(num) <= 0 && del == 1)
		num = num;

	else if (del == 1) {
		num.erase(std::prev(num.end()));
	}
	else
		num += value;

	return num;

}
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
void textRect(cv::Mat& theWhere, int theX, int theY, int textY, string theText, int theWidth, int theHeight, unsigned int theBorderColor = 0xc9c9c9, unsigned int theFillingColor = 0x676054, double theFontScale = DEFAULT_FONT_SCALE, unsigned int textColor = 0xCECECE) {
	

	rect(theWhere, theX, theY, theWidth, theHeight, theBorderColor, theFillingColor);

	cvui::text(theWhere, (theX + 5), textY, theText, theFontScale);

}