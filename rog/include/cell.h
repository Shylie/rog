#ifndef ROG_CELL_H
#define ROG_CELL_H

#include "coordinate.h"

namespace rog
{
	class Cell
	{
	public:
		inline Cell() : Cell(' ', 0) { }
		Cell(int, unsigned char = 0);

		void Put(Coordinate, Coordinate) const;

		int glyph;
		unsigned char height;
	};
}

#endif//ROG_CELL_H