#include "std.h"
#include "CLI.h"

int main() {
	CLI::drawTextBox(20, 21, '#', "TEST1");
	std::string test = "≤‚ ‘≤‚ ‘≤‚ ‘≤‚ ‘£°’‚ «÷–Œƒ≤‚ ‘£°";
	std::vector<std::string> testres = CLI::splitStringByLength(test, 16);
	for (int i = 0; i < testres.size(); i++) {
		std::cout << testres[i] << std::endl;
	}
	return 0;
}