/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:27 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 17:09:05 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Observer.hpp"

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
		case 'q': _is_pressed_q		= true; break;
		case ' ': _is_pressed_space	= true; break;
	}
	event_resolver();
}

