#include "std.h"
#include "cli.h"

int main()
{
	baseUI testBaseUI = baseUI();
	structUI testStructUI = structUI(3, 3, 10, 10, '*');
	testBaseUI.drawOnBase(testStructUI.draw());
	stringUI testStringUI = stringUI(0, 0, "Hello, World!");
	testBaseUI.drawOnBase(testStringUI.draw());
	testBaseUI.drawToScreen();
	return 0;
}
