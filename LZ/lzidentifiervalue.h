#pragma once

#include "lzref.h"

namespace LZ
{
	class LZobject;

	class LZidentifiervalue
	{
	public:
		LZref identifier;
		LZref value;
	};

	class LZextidentifiervalue
	{
	public:
		LZref identifier;
		LZobject* value;
	};
}
