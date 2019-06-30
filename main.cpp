#include "NPC.hpp"
#include "Observer.hpp"
#include <time.h>

#define SLEEP(milliseconds) usleep( (unsigned long)(milliseconds * 1000.0) )

//todo: FPS counter
//todo: list of all object in observer

//pseudo code below (from wolf3d)
//fps counter
//static int		prepare_render(t_env *env, t_fps *fps)
//{
//	fps->pre_tick = fps->cur_tick;
//	fps->cur_tick = SDL_GetTicks();
//	fps->frame_time = (fps->cur_tick - fps->pre_tick) / 1000.0f;
//	fps->value = (u_char)(1.0 / fps->frame_time);
//	env->cam.move_speed = fps->frame_time * 3;
//	env->cam.rotate_speed = fps->frame_time * 2;
//	if ((fps->frame_limit_second) > fps->cur_tick - fps->pre_tick)
//		SDL_Delay(fps->frame_limit_second - (fps->cur_tick - fps->pre_tick));
//	event_handler(env, &env->cam, &env->flags);
//	clear_img_buff(env);
//	return (1);
//}

static void		init_all()
{
	initscr();
	cbreak(); // don't buffer the TTY
	noecho(); // don't echo in TTY

	curs_set(0); // hide cursor

	// main window flags

	scrollok(stdscr, FALSE); // dont allow scrolling the window

	keypad(stdscr, TRUE); //f[n]   F1-F12
	nodelay(stdscr,TRUE);
}

int main()
{
	srand(time(NULL));
    Observer obs;
    NPC player(10, 0, 10, 1, 1, 'P', 25, 25, 'w');
    std::list<NPC*> objects;

    objects.push_back(&player);

    init_all();
	WINDOW *win = newwin(0,0,0,0);
	int y_max, x_max;
	getmaxyx(stdscr, y_max, x_max);
    for (int j = 0; j < 1; ++j) {
        objects.push_back(new NPC(10, 0, 10, 2, 1, 'E',
        		 rand() % x_max - 3 + 1,
        		rand() % (y_max / 5) + 1, 's'));
    }
    bool shouldQuit = false;
    char ch;
    int i = -1;
	//raw();	//put on screen all input include control keys like [ctrl]+[c]

//    refresh();
    while (!shouldQuit)
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
			system("leaks a.out"); return 0;
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
					return (0);
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
							return (0);
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
								return (0);
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
		int counter = 0;
		for (std::list<NPC *>::iterator first_npc = objects.begin();
			 first_npc != objects.end(); first_npc++)
		{
			if ((*first_npc)->fraction == 'E')
			{
				counter = 137;
				break;
			}

		}
		if (counter == 0)
			stage_two(win, player, y_max, x_max, obs);
		wrefresh(win);
	}

}

