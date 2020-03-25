#pragma once

#ifndef _CLI_
#define _CLI_

#include "std.h"

namespace CLI {
	// 将字符串切割成定长子串
	std::vector<std::string> splitStringByLength(std::string, int);

	// 绘制指定长宽和标题的矩形文本框 Caution: 第三个参数不能包含中文
	void drawTextBox(int line, int column, char pixel, std::string title = "", std::string message = "                ");
}

#endif // !_CLI_
