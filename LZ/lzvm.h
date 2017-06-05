#pragma once

#include <stack>

#include "lzref.h"
#include "lzobject.h"

namespace LZ
{
	class LZvm
	{
	public:
		void Push(LZref item);
		LZref Pop();
		//void Call();
		LZobject* Dereference(LZref reference);
		void Allocate(LZobject* object);

	protected:
		std::stack<LZref> lz_stack;
		std::vector<LZextidentifiervalue> lz_heap;

		LZref AllocateAddress();
	};
}
