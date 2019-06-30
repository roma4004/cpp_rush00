/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:40:56 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 16:53:53 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

void		Player::clear_events()
{
	_is_pressed_up		= false;
	_is_pressed_left	= false;
	_is_pressed_right	= false;
	_is_pressed_down	= false;
}

void Player::move()
{
	t_vec_fl offset = (t_vec_fl){ 0, 0 };

	if (_is_pressed_up)		offset.y -= speed;
	if (_is_pressed_left)	offset.x -= speed;
	if (_is_pressed_right)	offset.y += speed;
	if (_is_pressed_down)	offset.x += speed;

	pos = (t_vec_fl){	.x = pos.x + offset.x,
						.y = pos.y + offset.y };
}