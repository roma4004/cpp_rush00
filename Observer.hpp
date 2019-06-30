/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:09 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 13:52:33 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "NPC.hpp"

class Observer
{
public:
	bool		is_game_over;

	bool		is_pressed_up;
	bool		is_pressed_left;
	bool		is_pressed_right;
	bool		is_pressed_down;
	bool		is_pressed_q;

	void		event_handler();
	void		game_cycle();

};


#endif //OBSERVER_HPP
