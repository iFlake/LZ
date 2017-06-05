#include "lzvm.h"

namespace LZ
{
	void LZvm::Push(LZref item)
	{
		lz_stack.push(item);
	}

	LZref LZvm::Pop()
	{
		LZref top = lz_stack.top();
		lz_stack.pop();
		return top;
	}

	LZobject* LZvm::Dereference(LZref reference)
	{
		return lz_heap.at((unsigned long long) reference);
	}

	LZref LZvm::Allocate(LZobject* object)
	{
		if (lz_freeindexes.size() > 0)
		{
			LZref address = lz_freeindexes.at(0);

			lz_heap[(unsigned long long) address] = object;
			lz_freeindexes.erase(lz_freeindexes.begin());

			return address;
		}
		else
		{
			lz_heap.push_back(object);
			
			LZref address = lz_heap.size() - 1;
			return address;
		}
	}

	void LZvm::Deallocate(LZref reference)
	{
		delete lz_heap.at((unsigned long long) reference);

		LZobject* null = new LZobject;
		null->lz_type = lz_null;
		null->lz_value = nullptr;

		lz_heap[(unsigned long long) reference] = null;
	}
}
