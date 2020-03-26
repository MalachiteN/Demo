#include "std.h"
#include "cli.h"

int main()
{
	std::locale chs = std::locale("", LC_CTYPE);
	std::wcout.imbue(chs);
	baseUI testBaseUI = baseUI();
	structUI testStructUI = structUI(3, 3, 10, 10, '#');
	testBaseUI.drawOnBase(testStructUI.draw());
	stringUI teststringUI = stringUI(0, 0, L"Hello, World!");
	testBaseUI.drawOnBase(teststringUI.draw());
	multiStringUI testmultiStringUI = multiStringUI(10, 30, 4,  stringUI(0, 0, L"多行中文字符串UI测试 "),
																stringUI(0, 0, L"这是第一行 "), 
																stringUI(0, 0, L"English string test"), 
																stringUI(0, 0, L"This is Line 4"));
	testBaseUI.drawOnBase(testmultiStringUI.draw());
	testBaseUI.drawToScreen();
	return 0;
}
/*
 *	TODO LIST
 *
 *	class multiStringUI
 *		为 multiStringUI 类增添使用 stringUI 和宽度限定构造的构造函数
 *			函数签名
 *			multiStringUI(stringUI source, int len) -> multiStringUI
 *
 *	class structUI
 *		为 structUI 类增添实心功能, 使用 protected bool isSolid 标记
 *		并在 draw() 中判断以提供实心的 drawable
 */