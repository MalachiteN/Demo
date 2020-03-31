#include "std.h"
#include "cli.h"

void test()
{
	std::locale chs = std::locale("", LC_CTYPE);
	std::wcout.imbue(chs);
	baseUI testBaseUI = baseUI();
	structUI limitBox = structUI(0, 0, 29, 60, L"＃");
	testBaseUI.drawOnBase(limitBox.draw());
	structUI testStructUI = structUI(3, 3, 10, 10, L"＊");
	testBaseUI.drawOnBase(testStructUI.draw());
	structUI testSoildStructUI = structUI(19, 23, 5, 5, L"＃", true);
	testBaseUI.drawOnBase(testSoildStructUI.draw());
	stringUI teststringUI = stringUI(0, 0, L"Ｈｅｌｌｏ，Ｗｏｒｌｄ！");
	testBaseUI.drawOnBase(teststringUI.draw());
	multiStringUI testmultiStringUI = multiStringUI(10, 30, 2, stringUI(0, 0, L"多行中英文混合字符串ＵＩ"),
		stringUI(0, 0, L"Ｅｎｇｌｉｓｈ　Ｔｅｘｔ　Ｌｉｎｅ"));
	testBaseUI.drawOnBase(testmultiStringUI.draw());
	teststringUI.modifyPositionTo(10, 20);
	multiStringUI testConstructFromStringUI = multiStringUI(teststringUI, 6);
	testBaseUI.drawOnBase(testConstructFromStringUI.draw());
	testConstructFromStringUI.modifyPositionBy(10, 0);
	testBaseUI.drawOnBase(testConstructFromStringUI.draw());
	multiStringUI testRollBackUI = multiStringUI(stringUI(22, 4, L"如果你在输入任意命令后回车仍然看到这个多行字符串或者它的一部分，或者原来被它遮挡的部分没有重新显示出来，那么回滚失败了。"), 20);
	testBaseUI.drawOnBase(testRollBackUI.draw());
	testBaseUI.drawToScreen();
	_fgetchar();
	testBaseUI.rollback();
	testBaseUI.drawToScreen();
}

int main()
{
	
#ifdef DEBUG
	test();
#endif

	return 0;
}
/*
 *	TODO LIST
 *	baseUI对象能够支持回滚
 */