#include "cvui/cvui.h"

using namespace cvui;


void inputField(cv::Mat &theWhere, int theX, int theY, int millisecondDelay = 10, double theFontScale = DEFAULT_FONT_SCALE, unsigned int textColor = 0xCECECE) {

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

void inputBox(cv::Mat& theWhere, int theX, int theY, int theWidth, int theHeight, int millisecondDelay = 10, unsigned int theBorderColor = 0xc9c9c9, unsigned int theFillingColor = 0x676054, unsigned int textColor = 0xCECECE, double theFontScale = DEFAULT_FONT_SCALE) {

	char keyChar;
	std::string keyString;
	static std::string totalString;
	static bool allowInput = false;

	keyChar = cv::waitKey(millisecondDelay);

	rect(theWhere, theX, theY, theWidth, theHeight, theBorderColor, theFillingColor);

	int status = iarea(theX, theY, theWidth, theHeight);

	if (status == OUT && mouse(DOWN))
		allowInput = false;

	else if (status == CLICK)
		allowInput = true;

	if (allowInput == true) {

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
	}
	cvui::text(theWhere, theX, (theY + (theHeight / 2)), totalString, theFontScale);
}