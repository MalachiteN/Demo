#include "std.h"
#include "cli.h"

int main()
{
	std::locale chs = std::locale("", LC_CTYPE);
	std::wcout.imbue(chs);
	baseUI testBaseUI = baseUI();
	structUI testStructUI = structUI(3, 3, 10, 10, '#');
	testBaseUI.drawOnBase(testStructUI.draw());
	structUI testSoildStructUI = structUI(20, 20, 5, 5, '*', true);
	testBaseUI.drawOnBase(testSoildStructUI.draw());
	stringUI teststringUI = stringUI(0, 0, L"Hello, World!");
	testBaseUI.drawOnBase(teststringUI.draw());
	multiStringUI testmultiStringUI = multiStringUI(10, 30, 4,  stringUI(0, 0, L"多行中文字符串UI测试 "),
																stringUI(0, 0, L"这是第2行 "), 
																stringUI(0, 0, L"English string test"), 
																stringUI(0, 0, L"This is Line 4"));
	testBaseUI.drawOnBase(testmultiStringUI.draw());
	teststringUI.modifyPositionTo(10, 20);
	multiStringUI testConstructFromStringUI = multiStringUI(teststringUI, 7);
	testBaseUI.drawOnBase(testConstructFromStringUI.draw());
	testConstructFromStringUI.modifyPositionBy(10, 0);
	testBaseUI.drawOnBase(testConstructFromStringUI.draw());
	testBaseUI.drawToScreen();
	return 0;
}
/*
 *	TODO LIST
 *	class UI
 *		设计一个成员函数，用来改变(modify)一个UI在屏幕上的位置。
 *		"不会动的UI还能叫UI吗?"
 */