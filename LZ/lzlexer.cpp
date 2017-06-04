#include "lzlexer.h"

namespace LZ
{
	void LZlexer::Lex()
	{
		lz_length = lz_code.size();

		while (true)
		{
			LZtoken nexttoken = Next();
			if (nexttoken.lz_type == lz_eos) return;

			lz_output.push_back(nexttoken);
		}
	}

	LZtoken LZlexer::Next()
	{
		if (lz_position >= lz_length) return LZtoken(lz_eos, std::vector<char>{ });

		std::vector<char> feed;

		while (!IsInterrupt())
		{
			feed.push_back(lz_code[lz_position]);
			++lz_position;
		}

		if (feed == std::vector<char> {'i', 'f'}) return LZtoken(lz_if, std::vector<char> { });
		if (feed == std::vector<char> {'e', 'l', 's', 'e'}) return LZtoken(lz_else, std::vector<char> { });
		if (feed == std::vector<char> {'d', 'e', 'c', 'l', 'a', 'r', 'e'}) return LZtoken(lz_declare, std::vector<char> { });
		if (feed == std::vector<char> {'n', 'e', 'w'}) return LZtoken(lz_new, std::vector<char> { });
		if (feed == std::vector<char> {'='}) return LZtoken(lz_assign, std::vector<char> { });
		if (feed == std::vector<char> {'{'}) return LZtoken(lz_openbrace, std::vector<char> { });
		if (feed == std::vector<char> {'}'}) return LZtoken(lz_closebrace, std::vector<char> { });
		if (feed == std::vector<char> {'['}) return LZtoken(lz_openarray, std::vector<char> { });
		if (feed == std::vector<char> {']'}) return LZtoken(lz_closearray, std::vector<char> { });


		return LZtoken(lz_eos, std::vector<char> { });
	}

	bool LZlexer::IsInterrupt()
	{
		if (lz_position >= lz_length) return true;

		switch (lz_code[lz_position])
		{
		case '(':
		case ')':
		case '{':
		case '}':
		case '.':
		case ':':
		case ' ':
		case '\t':
		case '\r':
		case '\n':
		case '\0':
			return true;
		
		default:
			return false;
		}
	}
}