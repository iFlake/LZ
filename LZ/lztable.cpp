#include "lztable.h"

namespace LZ
{
	LZtable::LZtable(LZvm* vm)
	{
		lz_lzvm = vm;
	}

	void LZtable::Set(LZref index, LZref value)
	{

	}

	bool LZtable::Exists(LZref index)
	{

		return true;
	}

	unsigned int LZtable::RawFind(LZref index)
	{
		for (unsigned int iterator = 0; iterator < lz_indexes.size(); ++iterator)
		{
			LZidentifiervalue idv = lz_indexes.at(iterator);
			
		}

		return 1;
	}
}
