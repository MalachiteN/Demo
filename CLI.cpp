#include "CLI.h"
#include "std.h"

namespace CLI {
	std::vector<std::string> splitStringByLength(std::string str, int len) {
		std::vector<std::string> result;
		if(len % 2 == 1){
			len -= 1;
		}
		int numOfSection = str.length() / len + 1;
		int sttPos = 0;
		for (int i = 0; i < numOfSection; i++) {
			std::string tmp = str.substr(sttPos, len);
			result.push_back(tmp);
			sttPos += len;
		}
		return result;
	}
	void drawTextBox(int line, int column, char pixel, std::string title, std::string message) {
		if (title == "") {
			title = pixel;
		}
		std::vector<std::string> splitedMessage = splitStringByLength(message, column - 4);
		const int maxLine = message.length() / ((((column - 4) % 2) == 1) ? column - 5 : column - 4);
		const int lengthPerLine = splitedMessage[0].length();
		const int difference = lengthPerLine - splitedMessage[maxLine].length();
		for (int i = 1; i <= line; i++) {
			if (i == 1) {
				int tmp = title.length() / 2;
				for (int k = 1; k <= column / 2 - tmp; k++) {
					putchar(pixel);
				}
				auto tmpfun = [=]() {
					bool flag = false;
					for (int j = 0; j < title.length(); j++) {
						if (title[j] < 0 || title[j] > 127) {
							flag = true;
						}
					}
					return flag;
				};
				if (tmpfun() == true) {
					putchar(pixel);
				}
				std::cout << title;
				for (int k = 1; k <= column / 2 - tmp; k++) {
					putchar(pixel);
				}
				if (column % 2 + title.length() == 1) {
					putchar(pixel);
				}
				putchar('\n');
			}
			else if (i == line) {
				for (int j = 1; j <= column; j++) {
					putchar(pixel);
				}
				putchar('\n');
			}
			else {
				putchar(pixel);
				putchar(' ');
				if ((unsigned int)i < (splitedMessage.size() + 2)) {
					std::cout << splitedMessage[i - 2];
					if ((unsigned int) i == (splitedMessage.size() + 1)) {
						for (int j = 0; j < difference; j++) {
							putchar(' ');
						}
					}
					putchar(' ');
				}
				else {
					for (int j = 1; j <= column - 4; j++) {
						putchar(' ');
					}
				}
				putchar(' ');
				putchar(pixel);
				putchar('\n');
			}
		}
	}
}