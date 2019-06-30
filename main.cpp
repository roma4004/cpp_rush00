#include "NPC.hpp"
#include "Observer.hpp"
#include "Screen.hpp"

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
	keypad(stdscr, TRUE); //f[n]   F1-F12
	nodelay(stdscr,TRUE);
}

int main()
{
//	_is_pressed_q		= false;
//	_is_pressed_space   = false;
	srand(static_cast<unsigned int>(time(nullptr)));
    Observer obs;
    NPC player(10, 0, 10, 2, 1, 'P', 25, 25);
    std::list<NPC*> objects;

    objects.push_back(&player);
    for (int j = 0; j < 10; ++j) {
        objects.push_back(new NPC(10, 0, 10, 2, 1, 'E', j + 1, j + 1));
    }
    bool shouldQuit = false;
    char ch;
    int i = -1;
	//raw();	//put on screen all input include control keys like [ctrl]+[c]
    init_all();
    int y, x;
	getmaxyx(stdscr, y, x);
    WINDOW *win = newwin(0,0,0,0);
    refresh();
    while (!shouldQuit)
    {

		box(win,0, 0);
		for (std::list<NPC *>::iterator ptr = objects.begin();
			ptr != objects.end(); ptr++) {
			if ((*ptr)->fraction == 'P')
				mvwprintw(win, (*ptr)->pos.y, (*ptr)->pos.x, "@ X: %d | Y: %d", (*ptr)->pos.x, (*ptr)->pos.y);
			if ((*ptr)->fraction == 'E')
				mvwprintw(win, (*ptr)->pos.y, (*ptr)->pos.x, "# %c");
		}


		if ((ch = getch()) != ERR)
		{
			if (ch == 'q') {endwin(); return 0;}
			if (ch == 'd')
			{
				wclear(win);
				if (player.pos.x + 1 < x )
				{
					if (player.pos.x + 1 > 0)
						player.pos.x++;
				}


			}
			else if (ch == 'a')
			{
				wclear(win);
				if (player.pos.x - 1 > 0)
					player.pos.x--;


			}
			else if (ch == 's')
			{
				wclear(win);
				if (player.pos.y + 1 < y )
					player.pos.y++;

			}
			else if (ch == 'w')
			{
				wclear(win);
				if (player.pos.y - 1 > 0 )
					player.pos.y--;

			}

		}
		wrefresh(win);
	}

}

