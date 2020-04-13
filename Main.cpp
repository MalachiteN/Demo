#include "std.h"
#include "cli.h"

#ifdef DEBUG
	#include "test.h"
#endif

int main()
{

	std::locale chs = std::locale("chs", LC_CTYPE);
	std::wcout.imbue(chs);
	
#ifdef DEBUG
	test();
#endif

	return 0;
}