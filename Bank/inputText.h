#include "cvui/cvui.h"

using namespace cvui;


void inputField(cv::Mat &theWhere, int theX, int theY, int millisecondDelay = 10, double theFontScale = DEFAULT_FONT_SCALE) {

	char keyChar;
	std::string keyString;
	static std::string totalString;
	keyChar = cv::waitKey(millisecondDelay);
	if (std::size(totalString) <= 0 && keyChar == 8 || keyChar == 127)
		totalString = totalString;

	else if (keyChar == 8 || keyChar == 127)
		totalString.erase(std::prev(totalString.end()));

	else if ((keyChar < 8 || keyChar > 9) && keyChar != 27 && keyChar < 32 && keyChar > 127)
		totalString = totalString;
	else if (keyChar != -1) {
		keyString = (1, keyChar);
		totalString += keyString;

	}
	
	cvui::text(theWhere, theX, theY, totalString, theFontScale);
}
//void inputBox(cv::Mat& theWhere, int theX, int theY, int theWidth, int theHeight, int millisecondDelay = 20, unsigned int theBorderColor, unsigned int theFillingColor = 0xff000000, double theFontScale = DEFAULT_FONT_SCALE)