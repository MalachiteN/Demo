#pragma once

#ifndef _STD_
#define _STD_

#include <list>
#include <stack>
#include <vector>
#include <string>
#include <locale>
#include <cstdarg>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "supportalgorithm.h"

// comment this marco when release
#define DEBUG

#ifdef DEBUG

#define check(str) std::cerr<<str<<std::endl

#endif // DEBUG

#endif // _STD_
