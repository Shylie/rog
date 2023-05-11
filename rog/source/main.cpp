#include <BearLibTerminal.h>

#include "coordinate.h"
#include "cell.h"
#include "camera.h"

using namespace rog;

constexpr int WWIDTH = 25;
constexpr int WHEIGHT = 25;
constexpr int NUM_CELLS = WWIDTH * WHEIGHT;

int main(int argc, char** argv)
{
	if (!terminal_open())
	{
		return -1;
	}

	terminal_setf("terminal.encoding=437; window.cellsize=16x16; window.size=%dx%d;", WWIDTH, WHEIGHT);

	Cell cells[NUM_CELLS];
	Coordinate pc(WWIDTH / 2, WHEIGHT / 2);
	Camera cam(WWIDTH, WHEIGHT);

	for (int i = 0; i < NUM_CELLS; i++)
	{
		cells[i].glyph = 0xB2;
		cells[i].height = rand() % 256;
	}

	const auto& put = [&](Coordinate c) -> void
	{
		cells[c.x + c.y * WWIDTH].Put(c, pc);
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
			if (pc.y < WHEIGHT - 1)
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
			if (pc.x < WWIDTH - 1)
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