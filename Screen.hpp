#ifndef Screen_CLASS_H
# define Screen_CLASS_H

# include <cstddef>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <string>
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>

class Screen
{
	public:
		Screen(void);
		Screen(Screen const &);
		~Screen(void);

		Screen& operator=(Screen const &);

		void setSize(int y, int x);
		int getX(void);
		int getY(void);
	private:
		int _x;
		int _y;
};

Screen* env(Screen *c = NULL);

#endif
