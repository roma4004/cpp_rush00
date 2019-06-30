#include <csignal>
#include "Screen.hpp"

Screen* env(Screen *c)
{
	static Screen* ptr;

	if (c)
		ptr = c;
	return ptr;
}

void	onResize(int)
{
	endwin();
	refresh();
	clear();

	int x, y;
	getmaxyx(stdscr, y, x);
	env()->setSize(y, x);
}

Screen::Screen(void) : _x(0), _y(0)
{
	initscr(); // initialize Screen
	cbreak(); // don't buffer the TTY
	noecho(); // don't echo in TTY

	curs_set(0); // hide cursor

	// main window flags
	keypad(stdscr, TRUE); // allow special keys
	nodelay(stdscr, TRUE); // dont block the main thread when querying keys
	scrollok(stdscr, FALSE); // dont allow scrolling the window

	// get dimensions
	getmaxyx(stdscr, this->_y, this->_x);

	// register handlers
	std::signal(SIGWINCH, onResize); // allow resizing
}


Screen::~Screen(void)
{
	// foreach window
	// delwin(win)

	endwin();
}

void Screen::setSize(int y, int x)
{
	this->_y = y;
	this->_x = x;
}

int Screen::getX(void)
{
	return this->_x;
}

int Screen::getY(void)
{
	return this->_y;
}

Screen::Screen(Screen const &) {}
Screen& Screen::operator=(Screen const &) { return *this; }
