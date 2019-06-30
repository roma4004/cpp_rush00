/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:09 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 15:43:26 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <list>
#include <iterator>
#include "NPC.hpp"


class Observer
{
	bool		_is_pressed_up;
	bool		_is_pressed_left;
	bool		_is_pressed_right;
	bool		_is_pressed_down;
	bool		_is_pressed_q;
	bool		_is_pressed_space;

public:

	bool		is_game_over;

	bool		isPressedUp		() const;
	bool		isPressedLeft	() const;
	bool		isPressedRight	() const;
	bool		isPressedDown	() const;
	bool		isPressedQ		() const;
	bool		isPressedSpace	() const;

	void		event_handler();
	void		clear_events();
	void		event_resolver();
	void		game_cycle();

};


#endif //OBSERVER_HPP
