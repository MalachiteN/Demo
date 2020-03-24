#pragma once

#ifndef _CLI_
#define _CLI_

#include "std.h"

namespace CLI {
	// 将字符串切割成定长子串
	std::vector<std::string> splitStringByLength(std::string, int);

	// 绘制指定长宽和标题的矩形文本框
	void drawTextBox(int, int, char, std::string);
}

#endif // !_CLI_
