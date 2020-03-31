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

void UI::modifyPositionTo(int new_x, int new_y)
{
	this->x = new_x;
	this->y = new_y;
}

void UI::modifyPositionBy(int delta_x, int delta_y)
{
	this->x += delta_x;
	this->y += delta_y;
}

// structUI

structUI::structUI(int outer_x, int outer_y, int outer_line, int outer_column, std::wstring outer_pixel, bool outer_isSoild)
{
	this->x = outer_x;
	this->y = outer_y;
	this->line = outer_line;
	this->column = outer_column;
	this->pixel = outer_pixel;
	this->isSoild = outer_isSoild;
}

drawable structUI::draw()
{
	std::wstring tmp = this->pixel; // 3.31 update
	std::vector<std::wstring> body;
	std::wstring lineStr = L"";
	for (int i = 0; i < this->column; i++)
	{
		lineStr += tmp;
	}
	body.push_back(lineStr);
	if (isSoild)
	{
		for (int i = 0; i < line - 1; i++)
		{
			body.push_back(lineStr);
		}
		return drawable(this->x, this->y, body);
	}
	lineStr = tmp;
	for (int i = 0; i < this->column - 2; i++)
	{
		lineStr += L"　";
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

// library function putcharOnScreen

drawable putcharOnScreen(int x, int y, char c)
{
	std::wstring tmp = L" ";
	tmp[0] = c;
	return stringUI(x, y, tmp).draw();
}

// multiStringUI

multiStringUI::multiStringUI(int outer_x, int outer_y, int count, ...)
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

multiStringUI::multiStringUI(stringUI source, int lengthLimit)
{
	std::vector<std::wstring> targetContainer;
	targetContainer = splitStringByLength(source.str, lengthLimit);
	this->container = targetContainer;
	this->x = source.x;
	this->y = source.y;
}

drawable multiStringUI::draw() 
{
	return drawable(this->x, this->y, this->container);
}

// baseUI

baseUI::baseUI(int line, int column)
{
#ifdef DEBUG
	std::cerr << "lines: " << line << ", columns: " << column << std::endl;
	system("pause");
#endif // DEBUG

	std::wstring lineStr = L"";
	for (int i = 0; i < column; i++)
	{
		lineStr += L"　";
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
	std::vector<std::wstring> backup;
	for (int i = 0; (unsigned int)i < uiToDraw.body.size(); i++)
	{
		std::wstring line = L"";
		for (int j = 0; (unsigned int)j < uiToDraw[i].length(); j++)
		{
			line.insert(line.end(), scratch[uiToDraw.x + i][uiToDraw.y + j]);
			this->scratch[uiToDraw.x + i][uiToDraw.y + j] = uiToDraw[i][j];
		}
		backup.push_back(line);
	}
	this->rollbackStack.push(drawable(uiToDraw.x, uiToDraw.y, backup));
}

void baseUI::rollback()
{
	if (this->rollbackStack.empty() == false)
	{
		drawable backup = this->rollbackStack.top();
		this->drawOnBase(backup);
		this->rollbackStack.pop();
	}
}

void baseUI::drawToScreen()
{
	system("cls");
	for (unsigned int i = 0; i < this->scratch.size(); i++)
	{
		std::wcout << this->scratch[i].substr(0, this->scratch[i].length()) << std::endl;
	}
}

// // // // // 以上全部都是基础UI // // // //

// stringBoxUIMixed
/*
stringBoxUIMixed::stringBoxUIMixed(int outer_x, int outer_y, int line, int column, std::wstring outer_title, std::wstring outer_text)
{
}

stringBoxUIMixed::stringBoxUIMixed(structUI outer_structure, stringUI outer_title, multiStringUI outer_text)
{
}

drawable stringBoxUIMixed::draw()
{
	return drawable();
}
*/