/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:27 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 14:16:26 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Observer.hpp"

void		Observer::clear_events()
{
	_is_pressed_up		= false;
	_is_pressed_left	= false;
	_is_pressed_right	= false;
	_is_pressed_down	= false;
	_is_pressed_q		= false;
}

void		Observer::game_cycle()
{
	//run trough list an call tick to each

	//list type
	//cur = head
	while(cur)
	{
		cur.tick();
		//cur = next
	}
	//cur = head
	while(cur)
	{
		cur.display();
		//cur = next
	}



	wrefresh(win);
}

void		Observer::event_resolver()
{
	if (is_pressed_q)
	{
		endwin();
		exit(0);
	}
}

void		Observer::event_handler()
{
	clear_events();
	switch (getch())
	{
		case 'w': _is_pressed_up	= true; break;
		case 'a': _is_pressed_left	= true; break;
		case 's': _is_pressed_right	= true; break;
		case 'd': _is_pressed_down	= true; break;
		case 'q': _is_pressed_q		= true; break;
		default : std::cout << "warning: unknown key " << ch << std::endl;
	}
	event_resolver();
}
