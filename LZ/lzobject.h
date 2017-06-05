#pragma once

#include <vector>

#include "lztable.h"

namespace LZ
{
	class LZobject;

	enum LZobjecttype
	{
		lz_integer    = 0x00,
		lz_float      = 0x01,
		lz_boolean    = 0x02,
		lz_array      = 0x03,
		lz_table      = 0x04
	};

	union LZobjectvalue
	{
	public:
		LZobjectvalue() { };
		~LZobjectvalue() { };

		unsigned long long lz_integer;
		float lz_float;
		bool lz_boolean;
		std::vector<LZobject*> lz_array;
		LZtable* lz_table;
	};

	class LZobject
	{
	public:
		LZobject() { };
		~LZobject() { };

		LZobjecttype lz_type;
		LZobjectvalue lz_value;
	};
}
