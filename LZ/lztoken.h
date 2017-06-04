#pragma once

#include <vector>

namespace LZ
{
	enum lz_tokens
	{
		lz_eos = 0x0000,
		lz_if = 0x0001,
		lz_else = 0x0002,
		lz_declare = 0x0003,
		lz_new = 0x0004,
		lz_assign = 0x0005,
		lz_openbrace = 0x0006,
		lz_closebrace = 0x0007,
		lz_openarray = 0x0008,
		lz_closearray = 0x0009
	};

	class LZtoken
	{
	public:
		//constructor/destructor
		LZtoken(unsigned short type, std::vector<char> value);
		~LZtoken() { };

		//type
		unsigned short lz_type;
		//value
		std::vector<char> lz_value;
	};
}
