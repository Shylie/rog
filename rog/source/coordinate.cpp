#include "coordinate.h"

#include <cmath>

namespace rog
{
	Coordinate::Coordinate(int x, int y) :
		x(x),
		y(y)
	{ }

	Coordinate Coordinate::operator-() const
	{
		return { -x, -y };
	}

	Coordinate& Coordinate::operator+=(Coordinate c)
	{
		x += c.x;
		y += c.y;

		return *this;
	}

	Coordinate& Coordinate::operator-=(Coordinate c)
	{
		x -= c.x;
		y -= c.y;

		return *this;
	}

	float Coordinate::Angle(Coordinate other) const
	{
		Coordinate d = other - *this;

		return std::atan2(
			static_cast<float>(d.y),
			static_cast<float>(d.x)
		);
	}

	float Coordinate::Distance(Coordinate other) const
	{
		Coordinate d = other - *this;

		return std::sqrt(
			static_cast<float>(d.x * d.x + d.y * d.y)
		);
	}

	Coordinate operator+(Coordinate a, Coordinate b)
	{
		a += b;
		return a;
	}

	Coordinate operator-(Coordinate a, Coordinate b)
	{
		a -= b;
		return a;
	}

	bool operator==(Coordinate a, Coordinate b)
	{
		return a.x == b.x && a.y == b.y;
	}

	bool operator!=(Coordinate a, Coordinate b)
	{
		return a.x != b.x && a.y != b.y;
	}
}