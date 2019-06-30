/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NPC.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:05:06 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 21:38:19 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NPC.hpp"
#include "Observer.hpp"

NPC::NPC(unsigned hp, unsigned armor, unsigned ammo,
			float speed_b, float speed_npc, char fract, int x, int y,char dir)
{
	this->hp = hp;
	this->armor = armor;

	this->ammunition = ammo;
	this->speed_bullet = speed_b;
	this->speed = speed_npc;
	this->fraction = fract;
	this->_direction = dir;

	this->pos = (t_vec_fl){ x, y };
}

NPC::~NPC()
{
	std::cout << "NPC deleted!" << std::endl;
}

char	NPC::randomDir()
{
	char variants[4] = { 'w', 'a', 's', 'd' };
	return (variants[rand() % 4]);
}

void NPC::move(std::list<NPC*> objects, int y, int x)
{
	t_vec_fl offset = (t_vec_fl){ 0, 0 };

	switch (randomDir())
	{
		case 'w': offset.y -= speed; break;
		case 'a': offset.x -= speed; break;
		case 's': offset.y += speed; break;
		case 'd': offset.x += speed; break;
	}
	for (std::list<NPC *>::iterator second_npc = objects.begin();
		 second_npc != objects.end(); second_npc++)
	{
		if ( this->pos.y + offset.y == (*second_npc)->pos.y
		&&   this->pos.x + offset.x == (*second_npc)->pos.x
		&&   this                   !=  *second_npc)
			 return ;
	}
	if ((this->pos.y + offset.y >= y - 2 || this->pos.x + offset.x >= x - 2)
		|| (this->pos.y + offset.y < 1 || this->pos.x + offset.x < 1))
		return ;

	pos = (t_vec_fl){	.x = pos.x + offset.x,
						.y = pos.y + offset.y };
}

void NPC::takeDamage(unsigned int damage)
{
	if (damage > 0)
	{
		if ((long int)armor - (long int)damage >= 0)
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

void NPC::shot()
{
	//create new instance of bullet(speed_bullet)
}

void NPC::die()
{
	//self destruction
}
