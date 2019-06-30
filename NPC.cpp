/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NPC.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:05:06 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 14:05:55 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NPC.hpp"
#include "Observer.hpp"

NPC::NPC(unsigned hp, unsigned armor, unsigned ammo,
			float speed_b, float speed_npc, char fract, int x, int y, Observer obs)
{
	this->hp = hp;
	this->armor = armor;
    this->_obs = &obs;

	this->ammunition = ammo;
	this->speed_bullet = speed_b;
	this->speed = speed_npc;
	this->fraction = fract;

	this->pos = (t_vec_fl){ x, y };


	std::cout << "NPC created!" << std::endl;
}

NPC::~NPC()
{
	std::cout << "NPC deleted!" << std::endl;
}
/*
void NPC::move()
{
	t_vec_fl offset = (t_vec_fl){ 0, 0 };

	if (obs->isPressedUp()		) offset.y -= speed;
	if (obs->isPressedLeft()	) offset.x -= speed;
	if (obs->isPressedRight()	) offset.y += speed;
	if (obs->isPressedDown()	) offset.x += speed;

	pos = (t_vec_fl){ .x = pos.x + offset.x,
					  .y = pos.y + offset.y };
//	map[pos.x][pos.y] = 0;
//	pos = (t_vec_int){(int)b_x, (int)b_y};
//	map[pos.x][pos.y] = 2;
}
*/
void NPC::tik(char dir)
{
	//move();
}

void NPC::takeDamage(unsigned int damage)
{
	if (damage > 0)
	{
		if (armor - damage >= 0)
		{
			armor -= damage;
			return;
		}
		else if (armor > 0)
		{
			hp -= (damage - armor);
			armor = 0;
			return;
		}
		hp -= damage;
	}
}

void NPC::display()
{
	//output to canvas
}

void NPC::shot(char where_dir)
{
	//create new instance of bullet(speed_bullet)
}

void NPC::die()
{
	//self destruction
}
