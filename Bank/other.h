
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
Account acc;


//my other header file
#include "headers/functions.h"



//global int and bool, so that on line (currently) 311  on "source.cpp" doesnt restate them
int win = 0;
bool debug = 0;


//Window is named
#define WINDOW_NAME "VOLT Banking"

