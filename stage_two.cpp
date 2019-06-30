#include "NPC.hpp"

#define SLEEP(milliseconds) usleep( (unsigned long)(milliseconds * 1000.0) );

void stage_two(WINDOW *win, class NPC player1, int y_max, int x_max, class Observer obs)
{
	char ch;
	std::list<NPC*> objects;

	NPC player(obs._HP,0,obs._Bullets,1,1,'P', x_max / 2, y_max - 10, 'w');
	objects.push_back(&player);

	for (int j = 0; j < 100; ++j) {
		objects.push_back(new NPC(10, 0, 10, 2, 1, 'E',
								  rand() % x_max - 3 + 1,
								  rand() % (y_max / 5) + 1, 's'));
		obs.set_time(true);
	}
	while (1)
	{
		SLEEP(30);
		wclear(win);
		box(win,0, 0);
		for (std::list<NPC *>::iterator ptr = objects.begin();
			 ptr != objects.end(); ptr++) {
			wattroff(win, 1);
			if ((*ptr)->fraction == 'P')
				mvwprintw(win, (*ptr)->pos.y, (*ptr)->pos.x, "@");
			if ((*ptr)->fraction == 'E')
				mvwprintw(win, (*ptr)->pos.y, (*ptr)->pos.x, "#");
			if ((*ptr)->fraction == 'p')
				mvwprintw(win, (*ptr)->pos.y, (*ptr)->pos.x, "^");
			if ((*ptr)->fraction == 'e')
				mvwprintw(win, (*ptr)->pos.y, (*ptr)->pos.x, "v");
			mvwprintw(win, y_max - 1, 5, "SCORE %d\tHP : %d\tBullets: %d\tTime: %d",
					  obs._Score, obs._HP, obs._Bullets, obs.n_seconds);
		}
		if ((ch = getch()) != ERR)
		{
			if (ch == 'q') {
				endwin();
//				int i = -1;
//				for (std::list<NPC *>::iterator clear_npc = objects.begin();
//					 clear_npc != objects.end(); clear_npc++) {
//					std::cout << ++i << std::endl;
//					delete (*clear_npc);
//				}
//				objects.clear();
				system("leaks a.out"); exit (0);
			}
			if (ch == 'd')
			{
				if (player.pos.x + 1 < x_max - 1)
					player.pos.x += player.speed;
			}
			else if (ch == 'a')
			{
				if (player.pos.x - 1 > 0)
					player.pos.x -= player.speed;
			}
			else if (ch == 's')
			{
				if (player.pos.y + 1 < y_max - 1)
					player.pos.y += player.speed;

			}
			else if (ch == 'w')
			{

				if (player.pos.y - 1 > 0 )
					player.pos.y -= player.speed;
			}
			else if (ch == ' ')
			{
				if (obs._Bullets >= 0)
				{
					objects.push_back(new NPC(1, 0, 0, player.speed, player.speed_bullet, 'p',
											  player.pos.x, player.pos.y - 1, player._direction));
					obs._Bullets--;
				}
			}

		}
		for (std::list<NPC *>::iterator first_npc = objects.begin();
			 first_npc != objects.end(); first_npc++)
		{
			if ((*first_npc)->pos.x == player.pos.x && (*first_npc)->pos.y == player.pos.y
				&& (*first_npc)->fraction != player.fraction)
			{
				obs._HP--;
				if (obs._HP == 0)
				{
					endwin();
					exit (0);
				}
				objects.erase(first_npc);
			}
		}
		for (std::list<NPC *>::iterator first_npc = objects.begin();
			 first_npc != objects.end(); first_npc++)
		{

			if ((*first_npc)->fraction == 'E')
			{
				if (rand() % 100)
				{
					(*first_npc)->move(objects,y_max ,x_max);
					if ((*first_npc)->pos.x == player.pos.x && (*first_npc)->pos.y == player.pos.y)
					{
						obs._HP--;
						if (obs._HP == 0)
						{
							endwin();
							exit (0);
						}
					}
				}

				else
				{
					objects.push_back(new NPC(1, 0, 0, (*first_npc)->speed, (*first_npc)->speed_bullet, 'e',
											  (*first_npc)->pos.x, (*first_npc)->pos.y, (*first_npc)->_direction));
				}
			}
			if ((*first_npc)->fraction == 'e')
			{
				(*first_npc)->pos.y += (*first_npc)->speed;
				if ((*first_npc)->pos.y > y_max - 2)
				{
					NPC *tmp = *first_npc;
					delete *first_npc;	objects.erase(first_npc);
					continue ;

				}
				for (std::list<NPC *>::iterator second_npc = objects.begin();
					 second_npc != objects.end(); second_npc++)
				{
					if ((*first_npc)->pos.y    == (*second_npc)->pos.y
						&&  (*first_npc)->pos.x    == (*second_npc)->pos.x
						&&   *first_npc            !=  *second_npc
						&&  (*first_npc)->fraction != (*second_npc)->fraction)
					{
						if ((*second_npc)->fraction == 'P')
						{
							obs._HP--;
							if (obs._HP == 0)
							{
								endwin();
								exit (0);
							}

						}
						else
						{
							delete *second_npc;	objects.erase(second_npc);
							delete *first_npc;	objects.erase(first_npc);
						}

						break;
					}

				}
			}
			if ((*first_npc)->fraction == 'p')
			{
				(*first_npc)->pos.y -= (*first_npc)->speed;
				if ((*first_npc)->pos.y < 1)
				{
					NPC *tmp = *first_npc;
					delete *first_npc;	objects.erase(first_npc);
					continue ;
				}
				for (std::list<NPC *>::iterator second_npc = objects.begin();
					 second_npc != objects.end(); second_npc++)
				{
					if ((*first_npc)->pos.y    == (*second_npc)->pos.y
						&&  (*first_npc)->pos.x    == (*second_npc)->pos.x
						&&   *first_npc            !=  *second_npc
						&&  (*first_npc)->fraction != (*second_npc)->fraction)
					{
						obs._Score++;
						delete *second_npc;	objects.erase(second_npc);
						delete *first_npc;	objects.erase(first_npc);
						break;
					}

				}
			}
		}
		obs.set_time(false);
		if(obs.n_seconds == 60)
			exit (0);
		wrefresh(win);
	}
	exit(0);
}