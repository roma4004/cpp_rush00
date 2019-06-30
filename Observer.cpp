/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:27 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 13:16:02 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Observer.hpp"

void		clear_events()
{
	_is_pressed_up		= false;
	_is_pressed_left	= false;
	_is_pressed_right	= false;
	_is_pressed_down	= false;
	_is_pressed_space   = false;
}

void		game_cycle()
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
}


void		event_()
{
	endwin();
	exit(0);
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
		case ' ': _is_pressed_space	= true; break;
		case 'q': _is_pressed_q		= true; break;
		default:
			std::cout << "warning: unknown key " << ch << std::endl;
	}
}
