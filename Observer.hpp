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

	bool		s_pressed_up;
	bool		s_pressed_left;
	bool		s_pressed_right;
	bool		s_pressed_down;
	bool		s_pressed_q;
	bool        s_pressed_space;


	void		event_handler();
	void		game_cycle();
};


#endif //OBSERVER_HPP
