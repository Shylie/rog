#include "camera.h"

namespace rog
{
	Camera::Camera(unsigned int vw, unsigned vh) :
		Camera(vw, vh, { 0, 0 })
	{ }

	Camera::Camera(unsigned int vw, unsigned int vh, Coordinate tl) :
		tl(tl),
		viewWidth(vw),
		viewHeight(vw)
	{ }

	Camera& Camera::operator+=(Coordinate c)
	{
		tl += c;

		return *this;
	}

	Coordinate Camera::operator[](unsigned index) const
	{
		return tl + Coordinate(index % viewWidth, index / viewWidth);
	}
}