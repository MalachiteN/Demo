#include "std.h"
#include "cli.h"
#include "test.h"


int main()
{

	std::locale chs = std::locale("chs", LC_CTYPE);
	std::wcout.imbue(chs);
	
#ifdef DEBUG
	test();
#endif

	return 0;
}