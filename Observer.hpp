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

	bool		pressed_up;

    bool isPressedUp() const;

    bool		pressed_left;

    bool isPressedLeft() const;

    bool		pressed_right;

    bool isPressedRight() const;

    bool		pressed_down;

    bool isPressedDown() const;

    bool		pressed_q;

    bool isPressedQ() const;

    bool        pressed_space;


	void		event_handler();
	void		game_cycle();
};


#endif //OBSERVER_HPP
