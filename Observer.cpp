/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:27 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 15:43:28 by dromanic         ###   ########.fr       */
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
	_is_pressed_space   = false;
}

void		Observer::game_cycle()
{
	event_handler();

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
	if (_is_pressed_q)
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
		case ' ': _is_pressed_space	= true; break;
	}
	event_resolver();
}

bool Observer::isPressedUp() const {
    return _is_pressed_up;
}

bool Observer::isPressedLeft() const {
    return _is_pressed_left;
}

bool Observer::isPressedRight() const {
    return _is_pressed_right;
}

bool Observer::isPressedDown() const {
    return _is_pressed_down;
}

bool Observer::isPressedQ() const
{
	return _is_pressed_q;
}

bool Observer::isPressedSpace() const
{
	return _is_pressed_space;
}

