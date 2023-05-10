#ifndef ROG_COORDINATE_H
#define ROG_COORDINATE_H

namespace rog
{
	class Coordinate
	{
	public:
		int x;
		int y;

		Coordinate();
		Coordinate(int x, int y);

		Coordinate operator-() const;
		Coordinate& operator-();

		Coordinate& operator+=(Coordinate);
		Coordinate& operator-=(Coordinate);

		float Angle(Coordinate) const;
		float Distance(Coordinate) const;

		friend Coordinate operator+(Coordinate, Coordinate);
		friend Coordinate operator-(Coordinate, Coordinate);

		friend bool operator==(Coordinate, Coordinate);
		friend bool operator!=(Coordinate, Coordinate);
	};
}

#endif//ROG_COORDINATE_H