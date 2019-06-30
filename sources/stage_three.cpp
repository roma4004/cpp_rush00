#include "NPC.hpp"

#define SLEEP(milliseconds) usleep( (unsigned long)(milliseconds * 1000.0) );

void stage_three(WINDOW *win, int y_max, int x_max, class Observer obs)
{

	char ch;
	std::list<NPC*> objects;

	NPC player(obs._HP,0,obs._Bullets,1,1,'P', x_max / 2, y_max - 10, 'w');
	objects.push_back(&player);

	for (int j = 0; j < 5; ++j) {
		objects.push_back(new NPC(1, 0, 10, 2, 1, 'E',
								  rand() % x_max - 3 + 1,
								  rand() % (y_max / 5) + 1, 's'));
		obs.set_time(true);
	}
	objects.push_back(new NPC(10, 0, 10, 2, 1, 'B',
							  rand() % x_max - 3 + 1,
							  rand() % (y_max / 5) + 1, 'v'));
	while (1)
	{
		SLEEP(30)
		wclear(win);
		box(win,0, 0);
		for (std::list<NPC *>::iterator ptr = objects.begin();
			 ptr != objects.end(); ptr++)
		{
			wattroff(win, 1);
			if ( (*ptr)->fraction == 'P')
				mvwprintw(win, (*ptr)->pos.y, (*ptr)->pos.x, "@");
			if ( (*ptr)->fraction == 'E')
				mvwprintw(win, (*ptr)->pos.y, (*ptr)->pos.x, "#");
			if ( (*ptr)->fraction == 'p')
				mvwprintw(win, (*ptr)->pos.y, (*ptr)->pos.x, "^");
			if ( (*ptr)->fraction == 'e')
				mvwprintw(win, (*ptr)->pos.y, (*ptr)->pos.x, "v");
			if ( (*ptr)->fraction == 'B')
				mvwprintw(win, (*ptr)->pos.y, (*ptr)->pos.x, "$");
			mvwprintw(win, y_max - 1, 5, "SCORE %d\tHP : %d\tBullets: %d\tTime: %d",
					  obs._Score, obs._HP, obs._Bullets, obs.n_seconds);
		}
		if ((ch = getch()) != ERR)
		{
			if (ch == 'q')
			{
				endwin();
//				int i = -1;
//				for (std::list<NPC *>::iterator clear_npc = objects.begin();
//					 clear_npc != objects.end(); clear_npc++) {
//					std::cout << ++i << std::endl;
//					delete (*clear_npc);
//				}
//				objects.clear();
				 exit(0);
			}
			move_player(ch, player, y_max, x_max, objects, obs);
		}
		for (std::list<NPC *>::iterator first_npc = objects.begin();
			 first_npc != objects.end(); first_npc++)
		{
			if ((*first_npc)->pos.x    == player.pos.x
				&&  (*first_npc)->pos.y    == player.pos.y
				&&  (*first_npc)->fraction != player.fraction)
			{
				delete *first_npc; objects.erase(first_npc);
				if (--obs._HP == 0)
				{
					endwin();
					exit(0);
				}
			}
		}
		for (std::list<NPC *>::iterator first_npc = objects.begin();
			 first_npc != objects.end(); first_npc++)
		{

			if ((*first_npc)->fraction == 'E' || (*first_npc)->fraction == 'B')
			{
				if (rand() % 100)
				{
					(*first_npc)->move(objects,y_max ,x_max);
					if ((*first_npc)->pos.x == player.pos.x
						&& (*first_npc)->pos.y == player.pos.y)
					{
						delete *first_npc; objects.erase(first_npc);
						if (--obs._HP == 0)
						{
							endwin();
							exit(0);
						}
					}
				}

				else
					objects.push_back(new NPC(1, 0, 0,
											  (*first_npc)->speed, (*first_npc)->speed_bullet, 'e',
											  (*first_npc)->pos.x, (*first_npc)->pos.y, (*first_npc)->_direction));
			}
			if ((*first_npc)->fraction == 'e')
			{
				(*first_npc)->pos.y += (*first_npc)->speed;
				if ( (*first_npc)->pos.y > y_max - 2)
				{
					delete *first_npc;	objects.erase(first_npc);
					break ;
				}
				for (std::list<NPC *>::iterator second_npc = objects.begin();
					 second_npc != objects.end(); second_npc++)
				{
					if ( (*first_npc)->pos.y    == (*second_npc)->pos.y
						 &&   (*first_npc)->pos.x    == (*second_npc)->pos.x
						 &&    *first_npc            !=  *second_npc
						 &&   (*first_npc)->fraction != (*second_npc)->fraction)
					{
						delete *first_npc;	objects.erase(first_npc);
						if ((*second_npc)->fraction == 'P' || (*second_npc)->fraction == 'B')
						{
							if (--obs._HP == 0)
							{
								delete *second_npc;	objects.erase(second_npc);
								endwin();
								exit(0);
							}
						}
						break;
					}
				}
			}
			if ( (*first_npc)->fraction == 'p')
			{
				(*first_npc)->pos.y -= (*first_npc)->speed;
				if ( (*first_npc)->pos.y < 1)
				{
					delete *first_npc;	objects.erase(first_npc);
					break ;
				}
				for (std::list<NPC *>::iterator second_npc = objects.begin();
					 second_npc != objects.end(); second_npc++)
					if ((*first_npc)->pos.y    == (*second_npc)->pos.y
						&&  (*first_npc)->pos.x    == (*second_npc)->pos.x
						&&   *first_npc            !=  *second_npc
						&&  (*first_npc)->fraction != (*second_npc)->fraction)
					{
						(*second_npc)->hp--;
						delete *first_npc;	objects.erase(first_npc);
						if ((*second_npc)->hp == 0) {
							delete *second_npc;
							objects.erase(second_npc);
							obs._Score++;
						}




						break;
					}
			}
		}
		obs.set_time(false);
		wrefresh(win);
	}
	exit(0);
}