#include "supportalgorithm.h"

std::vector<std::wstring> splitStringByLength(std::wstring str, int lengthLimit)
{
	std::vector<std::wstring> result;
	for (int i = 0; (unsigned int)i < str.length() - (str.length() % lengthLimit); i += lengthLimit)
	{
		result.push_back(str.substr(i, lengthLimit));
	}
	if (str.length() % lengthLimit)
	{
		result.push_back(str.substr(str.length() - (str.length() % lengthLimit), str.length() % lengthLimit));
	}
	return result;
}
