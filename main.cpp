#include "NPC.hpp"
#include "Observer.hpp"
#include <list>
#include <iterator>
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
	init_all();
    Screen e;
    env(&e);
    NPC player(10, 0, 10, 2, 1, 'P', 25, 25);
    std::list<NPC> objects;
    objects.push_back(player);

    bool shouldQuit = false;
    int ch;

    WINDOW * win = newwin(3, 10, LINES / 2 - 2, COLS / 2 - 5);

	//raw();	//put on screen all input include control keys like [ctrl]+[c]

    while (!shouldQuit) {


		system("clear");
		print_map();
		//refresh();			//one time per tick
		//getch();			
	}

    }


}
