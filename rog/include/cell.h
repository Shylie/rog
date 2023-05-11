#ifndef ROG_CELL_H
#define ROG_CELL_H

#include "coordinate.h"

#include <cstdint>

namespace rog
{
	class Cell
	{
	public:
		inline Cell() : Cell(' ', 0) { }
		Cell(int, uint8_t = 0);

		void Put(Coordinate, Coordinate) const;

		int glyph;
		uint8_t height;
	};
}

#endif//ROG_CELL_H