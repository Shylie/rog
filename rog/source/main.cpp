#include <BearLibTerminal.h>

#include "coordinate.h"
#include "cell.h"
#include "camera.h"

using namespace rog;

int main(int argc, char** argv)
{
	if (!terminal_open())
	{
		return -1;
	}

	terminal_set("terminal.encoding=437; window.cellsize=16x16;");

	Cell cells[80*25];
	Coordinate pc(40, 12);
	Camera cam(80, 25);

	for (int i = 0; i < 80 * 25; i++)
	{
		if (i % 7 == 0)
		{
			cells[i].glyph = 0xB2;
			cells[i].height = rand() % 256;
		}
	}

	const auto& put = [&](Coordinate c) -> void
	{
		cells[c.x + c.y * 25].Put(c, pc);
	};

	const auto& draw = [&]() -> void
	{
		terminal_clear();

		for (Coordinate c : cam)
		{
			put(c);
		}

		terminal_refresh();
	};

	draw();

	for (int e = terminal_read(); e != TK_CLOSE && e != TK_ESCAPE; e = terminal_read())
	{
		switch (e)
		{
		case TK_W:
			if (pc.y > 0)
			{
				pc += { 0, -1 };
				draw();
			}
			break;

		case TK_S:
			if (pc.y < 24)
			{
				pc += { 0, 1 };
				draw();
			}
			break;

		case TK_A:
			if (pc.x > 0)
			{
				pc += { -1, 0 };
				draw();
			}
			break;

		case TK_D:
			if (pc.x < 79)
			{
				pc += { 1, 0 };
				draw();
			}
			break;
		}
	}

	terminal_close();

	return 0;
}