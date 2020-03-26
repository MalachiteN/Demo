#include "uiresource.h"

// drawable

drawable::drawable(int outer_x, int outer_y, std::vector<std::wstring> outer_body)
{
	this->x = outer_x;
	this->y = outer_y;
	this->body = outer_body;
}

std::wstring drawable::operator[] (int pos)
{
	return this->body[pos];
}

// UI

UI::UI(int outer_x, int outer_y)
{
	this->x = outer_x;
	this->y = outer_y;
}

// baseUI

baseUI::baseUI(int line, int column)
{
	std::wstring lineStr = L"";
	for (int i = 0; i < column; i++)
	{
		lineStr += L" ";
	}
	for (int i = 0; i < line; i++)
	{
		this->scratch.push_back(lineStr);
	}
}

std::wstring baseUI::operator[](int pos)
{
	return this->scratch[pos];
}

void baseUI::drawOnBase(drawable uiToDraw)
{
	for (int i = 0; (unsigned int)i < uiToDraw.body.size(); i++)
	{
		for (int j = 0; (unsigned int)j < uiToDraw[i].length(); j++)
		{
			this->scratch[uiToDraw.x + i][uiToDraw.y + j] = uiToDraw[i][j];
		}
	}
}

void baseUI::drawToScreen()
{
	for (unsigned int i = 0; i < this->scratch.size(); i++)
	{
		std::wcout << this->scratch[i] << std::endl;
	}
}

// structUI

structUI::structUI(int outer_x, int outer_y, int outer_line, int outer_column, char outer_pixel)
{
	this->x = outer_x;
	this->y = outer_y;
	this->line = outer_line;
	this->column = outer_column;
	this->pixel = outer_pixel;
}

drawable structUI::draw()
{
	std::wstring tmp = L" "; // 3.26 fixed
	tmp[0] = this->pixel;
	std::vector<std::wstring> body;
	std::wstring lineStr = L"";
	for (int i = 0; i < this->column; i++)
	{
		lineStr += tmp;
	}
	body.push_back(lineStr);
	lineStr = tmp;
	for (int i = 0; i < this->column - 2; i++)
	{
		lineStr += L" ";
	}
	lineStr += tmp;
	for (int i = 0; i < this->line - 2; i++) {
		body.push_back(lineStr);
	}
	lineStr = L"";
	for (int i = 0; i < this->column; i++)
	{
		lineStr += tmp;
	}
	body.push_back(lineStr);
	return drawable(this->x, this->y, body);
}

// stringUI

stringUI::stringUI(int outer_x, int outer_y, std::wstring outer_str)
{
	this->x = outer_x;
	this->y = outer_y;
	this->str = outer_str;
}

drawable stringUI::draw()
{
	std::vector<std::wstring> body = { this->str };
	return drawable(this->x, this->y, body);
}

// multistringUI

multistringUI::multistringUI(int outer_x, int outer_y, int count, ...)
{
	this->x = outer_x;
	this->y = outer_y;
	va_list arg_ptr;
	va_start(arg_ptr, count);
	for (int i = 0; i < count; i++)
	{
		this->container.push_back(va_arg(arg_ptr, stringUI).draw()[0]);
	}
}

drawable multistringUI::draw() 
{
	return drawable(this->x, this->y, this->container);
}