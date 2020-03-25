#pragma once

#ifndef _CLI_
#define _CLI_

#include "std.h"

namespace CLI {
	// ���ַ����и�ɶ����Ӵ�
	std::vector<std::string> splitStringByLength(std::string, int);

	// ����ָ������ͱ���ľ����ı��� Caution: �������������ܰ�������
	void drawTextBox(int line, int column, char pixel, std::string title = "", std::string message = "                ");
}

#endif // !_CLI_
