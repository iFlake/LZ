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
		for (int iterator = 0; iterator < lz_heap.size(); ++iterator)
		{
			LZextidentifiervalue iv = lz_heap.at(iterator);
			
			if (iv.identifier == reference) return iv.value;
		}

		return nullptr;
	}

	void LZvm::Allocate(LZobject* object)
	{
		LZref address = AllocateAddress();

		LZextidentifiervalue iv;
		iv.identifier = address;
		iv.value = object;

		lz_heap.push_back(iv);
	}

	LZref LZvm::AllocateAddress()
	{
		LZref address = 1;

		while (true)
		{
			if (Dereference(address) == nullptr) return address;
			++address;
		}

		return address;
	}
}
