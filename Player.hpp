/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:40:21 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 17:14:34 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "NPC.hpp"

class Player : public NPC
{
	bool		_is_pressed_up;
	bool		_is_pressed_left;
	bool		_is_pressed_right;
	bool		_is_pressed_down;
	bool		_is_pressed_space;

	void		clear_events();
	void		move();
};


	bool		_is_pressed_q;
#endif //PLAYER_HPP
