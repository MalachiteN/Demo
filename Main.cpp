#include "std.h"
#include "cli.h"

int main()
{
	std::wcout.imbue(std::locale("chs"));
	baseUI testBaseUI = baseUI();
	structUI testStructUI = structUI(3, 3, 10, 10, '*');
	testBaseUI.drawOnBase(testStructUI.draw());
	stringUI teststringUI = stringUI(0, 0, L"Hello, World!");
	testBaseUI.drawOnBase(teststringUI.draw());
	multistringUI testMultistringUI = multistringUI(10, 30, 4,  stringUI(0, 0, L"多行中文字符串UI测试 "),
																stringUI(0, 0, L"这是第一行 "), 
																stringUI(0, 0, L"English string is also OK"), 
																stringUI(0, 0, L"This is Line 4"));
	testBaseUI.drawOnBase(testMultistringUI.draw());
	testBaseUI.drawToScreen();
	return 0;
}
