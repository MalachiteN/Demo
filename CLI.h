#pragma once

#ifndef _CLI_
#define _CLI_

#include "std.h"

namespace CLI {
	// ���ַ����и�ɶ����Ӵ�
	std::vector<std::string> splitStringByLength(std::string, int);

	// ����ָ������ͱ���ľ����ı���
	void drawTextBox(int, int, char, std::string);
}

#endif // !_CLI_
