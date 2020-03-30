#include "std.h"
#include "cli.h"

int main()
{
	std::locale chs = std::locale("", LC_CTYPE);
	std::wcout.imbue(chs);
	baseUI testBaseUI = baseUI();
	structUI testStructUI = structUI(3, 3, 10, 10, '#');
	testBaseUI.drawOnBase(testStructUI.draw());
	structUI testSoildStructUI = structUI(19, 23, 5, 5, '*', true);
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
	multiStringUI testRollBackUI = multiStringUI(stringUI(22, 4, L"如果你在输入任意命令后回车仍然看到这个多行字符串或者它的一部分，或者原来被它遮挡的部分没有重新显示出来，那么回滚失败了."), 20);
	testBaseUI.drawOnBase(testRollBackUI.draw());
	testBaseUI.drawToScreen();
	_fgetchar();
	testBaseUI.rollback();
	testBaseUI.drawToScreen();
	return 0;
}
/*
 *	TODO LIST
 *	baseUI对象能够支持回滚
 */