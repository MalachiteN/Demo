#include "std.h"
#include "cli.h"

void test()
{
	std::locale chs = std::locale("", LC_CTYPE);
	std::wcout.imbue(chs);
	baseUI testBaseUI = baseUI();
	structUI limitBox = structUI(0, 0, 29, 60, L"��");
	testBaseUI.drawOnBase(limitBox.draw());
	structUI testStructUI = structUI(3, 3, 10, 10, L"��");
	testBaseUI.drawOnBase(testStructUI.draw());
	structUI testSoildStructUI = structUI(19, 23, 5, 5, L"��", true);
	testBaseUI.drawOnBase(testSoildStructUI.draw());
	stringUI teststringUI = stringUI(0, 0, L"�ȣ����ף���䣡");
	testBaseUI.drawOnBase(teststringUI.draw());
	multiStringUI testmultiStringUI = multiStringUI(10, 30, 2, stringUI(0, 0, L"������Ӣ�Ļ���ַ����գ�"),
		stringUI(0, 0, L"�ţ�����衡�ԣ�������̣���"));
	testBaseUI.drawOnBase(testmultiStringUI.draw());
	teststringUI.modifyPositionTo(10, 20);
	multiStringUI testConstructFromStringUI = multiStringUI(teststringUI, 6);
	testBaseUI.drawOnBase(testConstructFromStringUI.draw());
	testConstructFromStringUI.modifyPositionBy(10, 0);
	testBaseUI.drawOnBase(testConstructFromStringUI.draw());
	multiStringUI testRollBackUI = multiStringUI(stringUI(22, 4, L"��������������������س���Ȼ������������ַ�����������һ���֣�����ԭ�������ڵ��Ĳ���û��������ʾ��������ô�ع�ʧ���ˡ�"), 20);
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
 *	baseUI�����ܹ�֧�ֻع�
 */