#pragma once

#ifndef __UIRESOURCE__
#define __UIRESOURCE__

#include "std.h"

struct drawable
{
	int x, y;
	std::vector<std::wstring> body;

	drawable(int outer_x = 0, int outer_y = 0, std::vector<std::wstring> outer_body = {});
	std::wstring operator[] (int pos);
};

class UI
{
public:
	int x, y;

	UI(int outer_x = 0, int outer_y = 0);
	virtual drawable draw() { return drawable(); };
	void modifyPositionTo(int new_x, int new_y);
	void modifyPositionBy(int delta_x, int delta_y);
};

class baseUI
{
public:
	baseUI(int line = 30, int column = 120);
	std::wstring operator[] (int pos);
	void drawToScreen();
	void drawOnBase(drawable);

private:
	std::vector<std::wstring> scratch;
};

class structUI:public UI
{
public:
	int line, column;
	char pixel;

	structUI(int outer_x = 0, int outer_y = 0, int outer_line = 2, int outer_column = 2, char outer_pixel = '#', bool outer_isSoild = false);
	drawable draw();

private:
	bool isSoild;
};

class stringUI:public UI
{
public:
	std::wstring str;

	stringUI(int outer_x = 0, int outer_y = 0, std::wstring outer_str = L"");
	drawable draw();
};

drawable putcharOnScreen(int x = 0, int y = 0, char c = '*');

class multiStringUI:public stringUI
{
public:
	multiStringUI(int outer_x, int outer_y, int count, ...);
	multiStringUI(stringUI source, int lengthLimit);
	drawable draw();

private:
	std::vector<std::wstring> container;
};

#endif // !__UIRESOURCE__
