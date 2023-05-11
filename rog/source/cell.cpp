#include "cell.h"

#include <cmath>

#include <BearLibTerminal.h>

namespace rog
{
	Cell::Cell(int glyph, uint8_t height) :
		glyph(glyph),
		height(height)
	{ }

	void Cell::Put(Coordinate me, Coordinate vanish) const
	{
		constexpr float distanceScale = 5.0f;

		const float angle = me.Angle(vanish);
		const float distance = me.Distance(vanish);

		const float dx = -std::cos(angle) * distance / distanceScale;
		const float dy = -std::sin(angle) * distance / distanceScale;

		for (int i = 0; i <= height; i++)
		{
			constexpr uint8_t MIN_C = 96;
			const uint8_t component = MIN_C + static_cast<uint8_t>((255 - MIN_C) * i / 255.0f);
			const color_t color = color_from_argb(0xFF, component, component, component);
			color_t corners[4] = { color, color, color, color };

			terminal_layer(i);
			terminal_put_ext(me.x, me.y, dx * i, dy * i, glyph, corners);
		}
	}
}