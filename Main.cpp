#include "std.h"
#include "cli.h"

int main()
{
	baseUI testBaseUI = baseUI();
	structUI testStructUI = structUI(3, 3, 10, 10, '*');
	testBaseUI.drawOnBase(testStructUI.draw());
	stringUI testStringUI = stringUI(0, 0, "Hello, World!");
	testBaseUI.drawOnBase(testStringUI.draw());
	multiStringUI testMultiStringUI = multiStringUI(10, 50, 4,  stringUI(0, 0, "This is a multi-line stringUI"),
																stringUI(0, 0, "This is Line 1"), 
																stringUI(0, 0, "This is Line 2"), 
																stringUI(0, 0, "This is Line 3"));
	testBaseUI.drawOnBase(testMultiStringUI.draw());
	testBaseUI.drawToScreen();
	return 0;
}
