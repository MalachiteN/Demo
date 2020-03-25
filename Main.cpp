#include "std.h"
#include "CLI.h"

int main() {
	std::string test = "≤‚ ‘≤‚ ‘≤‚ ‘≤‚ ‘£°’‚ «÷–Œƒ≤‚ ‘£°!";
	CLI::drawTextBox(20, 21, '#', "≤‚ ‘≤‚ ‘≤‚ ‘");
	return 0;
}