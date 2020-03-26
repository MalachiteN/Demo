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
	multiStringUI testmultiStringUI = multiStringUI(10, 30, 4,  stringUI(0, 0, L"���������ַ���UI���� "),
																stringUI(0, 0, L"���ǵ�һ�� "), 
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
 *		Ϊ multiStringUI ������ʹ�� stringUI �Ϳ���޶�����Ĺ��캯��
 *			����ǩ��
 *			multiStringUI(stringUI source, int len) -> multiStringUI
 *
 *	class structUI
 *		Ϊ structUI ������ʵ�Ĺ���, ʹ�� protected bool isSolid ���
 *		���� draw() ���ж����ṩʵ�ĵ� drawable
 */