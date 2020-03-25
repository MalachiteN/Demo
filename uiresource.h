#pragma once

#ifndef __UIRESOURCE__
#define __UIRESOURCE__

#include "std.h"

struct drawable {
	int x, y;
	std::vector<std::string> body;
	drawable(int outer_x = 0, int outer_y = 0, std::vector<std::string> outer_body = {});
	std::string operator[] (int pos);
};

class UI
{
public:
	UI(int outer_x = 0, int outer_y = 0);
	virtual drawable draw() { return drawable(); };

protected:
	int x, y;
};

class baseUI
{
public:
	baseUI(int line = 27, int column = 120);
	std::string operator[] (int pos);
	void drawToScreen();
	void drawOnBase(drawable);

private:
	std::vector<std::string> scratch;
};

class structUI:public UI
{
public:
	structUI(int outer_x = 0, int outer_y = 0, int outer_line = 2, int outer_column = 2, char outer_pixel = '#');
	drawable draw();

protected:
	int line, column;
	char pixel;
};

class stringUI:public UI
{
public:
	stringUI(int outer_x = 0, int outer_y = 0, std::string outer_str = "");
	drawable draw();

protected:
	int x, y;
	std::string str;
};



#endif // !__UIRESOURCE__
