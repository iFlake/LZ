#include "lztoken.h"

namespace LZ
{
	LZtoken::LZtoken(unsigned short type, std::vector<char> value)
	{
		lz_type = type;
		lz_value = value;
	}
}
