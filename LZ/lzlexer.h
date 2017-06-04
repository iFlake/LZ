#pragma once

#include <vector>

#include "lztoken.h"

namespace LZ
{
	class LZlexer
	{
	public:
		//constructor
		LZlexer() { };

		//io
		std::vector<char> lz_code;
		std::vector<LZtoken> lz_output;

		//startup
		void Lex();

	protected:
		//position
		unsigned int lz_position;

		//efficiency
		unsigned int lz_length;

		//internal lexing
		LZtoken Next();
		bool IsInterrupt();
	};
}
