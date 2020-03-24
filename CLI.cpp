#include "CLI.h"
#include "std.h"

namespace CLI {
	std::vector<std::string> splitStringByLength(std::string str, int len) {
		std::vector<std::string> result;
		int numOfSection = str.length() / len + 1;
		int sttPos = 0;
		for (int i = 0; i < numOfSection; i++) {
			std::string tmp = str.substr(sttPos, len);
			result.push_back(tmp);
			sttPos += len;
		}
		return result;
	}
	void drawTextBox(int line, int column, char pixel, std::string title = ""/*, std::string message = ""*/) {
		if (title == "") {
			title = pixel;
		}
		for (int i = 1; i <= line; i++) {
			if (i == 1) {
				int tmp = title.length() / 2;
				for (int k = 1; k <= column / 2 - tmp; k++) {
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
				for (int j = 1; j <= column - 2; j++) {
					putchar(' ');
				}
				putchar(pixel);
				putchar('\n');
			}
		}
	}
}