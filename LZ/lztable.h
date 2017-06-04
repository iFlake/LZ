#pragma once

#include <vector>

#include "lzref.h"
#include "lzidentifiervalue.h"

namespace LZ
{
	class LZvm;

	class LZtable
	{
	public:
		LZtable(LZvm* lzvm);
		~LZtable() { };

		void Set(LZref index, LZref value);

		bool Exists(LZref index);

	protected:
		LZvm* lz_lzvm;

		unsigned int RawFind(LZref index);
		//void RawSet(unsigned int index, LZref value);
		//LZref RawGet(unsigned int index);

		std::vector<LZidentifiervalue> lz_indexes;
	};
}
