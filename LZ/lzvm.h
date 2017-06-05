#pragma once

#include <stack>

#include "lzref.h"
#include "lzobject.h"

namespace LZ
{
	class LZvm
	{
	public:
		//stack
		void Push(LZref item);
		LZref Pop();

		//void Call();

		//memory management
		LZobject* Dereference(LZref reference);
		LZref Allocate(LZobject* object);
		void Deallocate(LZref reference);

	protected:
		std::stack<LZref> lz_stack;
		std::vector<LZobject*> lz_heap;

		std::vector<LZref> lz_freeindexes;
	};
}
