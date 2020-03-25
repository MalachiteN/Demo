#include "std.h"
#include "cli.h"

int main()
{
	baseUI testBaseUI = baseUI();
	check("OK "<<1);
	structUI testStructUI = structUI(3, 3, 10, 10, '*');
	check("OK "<<2);
	testBaseUI.drawOnBase(testStructUI.draw());
	check("OK "<<3);
	testBaseUI.drawToScreen();
	check("OK "<<4);
	return 0;
}
