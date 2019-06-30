/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:54:25 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 16:59:03 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

void Enemy::move()
{
	t_vec_fl offset = (t_vec_fl){ 0, 0 };

	switch (randomDir())
	{
		case 'w': offset.y -= speed; break;
		case 'a': offset.x -= speed; break;
		case 's': offset.y += speed; break;
		case 'd': offset.x += speed; break;
	}
	pos = (t_vec_fl){	.x = pos.x + offset.x,
						.y = pos.y + offset.y };

	//random chose direct
}