#include "NPC.hpp"

#define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )

void print_map()
{
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;	
	}
	std::cout << std::endl;	
}

void init_map()
{
	for(int i= 0; i < 50 ; i++)
	{
		map[0][i] = 1;
	}
	for(int i= 0; i < 50 ; i++)
	{
		map[i][0] = 1;
		map[i][WIDTH - 1] = 1;
	}
	for(int i= 0; i < 50 ; i++)
	{
		map[HEIGHT - 1][i] = 1;
	}
}

int main()
{

	init_map();
	print_map();
	NPC player(10, 0, 10, 2, 1, 'P', 25, 25);
	print_map();
	return (0);

	int ch;
	//initscr();			
	//raw();				
	//keypad(stdscr, TRUE);		
	//nodelay(stdscr,TRUE);
	while (1)
	{
		SLEEP( 100 );
		//printw("Exit: q\n");
		ch = getch();
		ch = 'w';
		if(ch == 'w' || ch == 'a' || ch == 's' || ch == 'd')
			player.tik(ch);
		else if(ch == 'q') { endwin(); exit(0); }
		system("clear");
		print_map();
		//refresh();			
		//getch();			
	}

	endwin();
	exit(1);
	//return 0;
}
