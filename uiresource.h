#pragma once

#ifndef __UIRESOURCE__
#define __UIRESOURCE__

#include "std.h"

struct drawable
{
	bool isPackage; // 该值仅供调试使用
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

class structUI:public UI
{
public:
	int line, column;
	std::wstring pixel;

	structUI(int outer_x = 0, int outer_y = 0, int outer_line = 2, int outer_column = 2, std::wstring outer_pixel = L"#", bool outer_isSoild = false);
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

drawable putcharOnScreen(int x = 0, int y = 0, wchar_t c = '＊');

class multiStringUI:public stringUI
{
public:
	multiStringUI(int outer_x, int outer_y, int count, ...);
	multiStringUI(stringUI source = stringUI(), int lengthLimit = 1);
	drawable draw();
	std::vector<std::wstring> container;
};

#endif // !__UIRESOURCE__

class baseUI
{
public:
	baseUI(int line = 29, int column = 60); // 3.31 update
	std::wstring operator[] (int pos);
	void drawToScreen();
	void drawOnBase(drawable);
	drawable pack(int x = 0, int y = 0);
	void rollback();

private:
	std::vector<std::wstring> scratch;
	std::stack<drawable> rollbackStack;
};

// // // // // 以上全部都是基础UI // // // //

// 接下来就可以*定义*混合复杂UI了☆~！

class stringBoxUIMixed: public UI
{
public:
	stringBoxUIMixed(int outer_x = 0, int outer_y = 0, std::wstring outer_pixel = L"＃", std::wstring outer_title = L"", std::wstring outer_text = L"", int outer_column = 1);
	drawable draw();

private:
	structUI structure;
	stringUI title;
	multiStringUI text;
	int column;
	int line;
};