#include "uiresource.h"

// drawable

drawable::drawable(int outer_x, int outer_y, std::vector<std::string> outer_body)
{
	this->x = outer_x;
	this->y = outer_y;
	this->body = outer_body;
}

std::string drawable::operator[] (int pos)
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
	std::string lineStr = "";
	for (int i = 0; i < column; i++)
	{
		lineStr += " ";
	}
	for (int i = 0; i < line; i++)
	{
		this->scratch.push_back(lineStr);
	}
}

std::string baseUI::operator[](int pos)
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
			check("i="<<i<<" j="<<j);
		}
	}
}

void baseUI::drawToScreen()
{
	for (unsigned int i = 0; i < this->scratch.size(); i++)
	{
		std::cout << this->scratch[i] << std::endl;
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
	char tmp[1] = { this->pixel }; // TODO: 这个东西烫烫烫了
	std::vector<std::string> body;
	std::string lineStr = "";
	for (int i = 0; i < this->column; i++)
	{
		lineStr += tmp;
	}
	body.push_back(lineStr);
	lineStr = tmp;
	for (int i = 0; i < this->column - 2; i++)
	{
		lineStr += " ";
	}
	lineStr += tmp;
	for (int i = 0; i < this->line - 2; i++) {
		body.push_back(lineStr);
	}
	lineStr = "";
	for (int i = 0; i < this->column; i++)
	{
		lineStr += tmp;
	}
	body.push_back(lineStr);
	return drawable(this->x, this->y, body);
}

stringUI::stringUI(int outer_x, int outer_y, std::string outer_str)
{
	this->x = outer_x;
	this->y = outer_y;
	this->str = outer_str;
}

drawable stringUI::draw()
{
	std::vector<std::string> body = { this->str };
	return drawable(this->x, this->y, body);
}