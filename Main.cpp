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
	multiStringUI testmultiStringUI = multiStringUI(10, 30, 4,  stringUI(0, 0, L"���������ַ���UI���� "),
																stringUI(0, 0, L"���ǵ�2�� "), 
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
 *		���һ����Ա�����������ı�(modify)һ��UI����Ļ�ϵ�λ�á�
 *		"���ᶯ��UI���ܽ�UI��?"
 */