#include "std.h"
#include "CLI.h"

int main() {
	std::string test = "���Բ��Բ��Բ��ԣ��������Ĳ��ԣ�!";
	CLI::drawTextBox(20, 21, '#', "���Բ��Բ���");
	return 0;
}