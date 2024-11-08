# A Windows Keylogger
A keylogger is a type of surveillance software that records every keystroke made on a computer's keyboard. It operates in the background capturing data. This keylogger will store the keystrokes in a log file.
<div align="center">
  <img src="https://github.com/user-attachments/assets/a6a88a45-8ca2-4099-98e6-dd2a924973ad">
</div>



## Features
* Keystroke Logging: Records all keystrokes made on the keyboard.
* Stealth Mode: Runs silently in the background without alerting the user.
* Log File Creation: Saves captured keystrokes in a log file.
* Screenshot Capture: Captures screenshots at regular intervals.

## Installation
1. Clone the Repository
```
git clone https://github.com/SeccreDev/Keylogger.git
```
2. Using Visual Studio open the solution (.sln file).
3. Activate or Deactivate Stealth Mode by changing the boolean value in line 17 (true/false)
```
const bool HIDECONSOLE = false;
```
4. Change the screenshot interval in seconds by changing the integer value in line 22
```
const int SECONDS = 120;
```
5. Build the .exe (Ctrl + B)

## Disclaimer
This keylogger is designed for educational purposes only. It should be used solely for learning about cybersecurity, ethical hacking, and how to defend against keylogging attacks. Unauthorized use of this software to monitor or collect information from others without their consent is illegal and unethical. Please ensure that you have explicit permission to use this tool in any environment where it is deployed. This project is provided as-is, without any warranty. The author is not responsible for any misuse of this software. By using this software, you agree to use it responsibly and within the bounds of the law.

## License
[MIT](https://choosealicense.com/licenses/mit/)
