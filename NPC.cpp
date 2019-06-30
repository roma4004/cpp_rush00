/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NPC.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:05:06 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 16:57:30 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NPC.hpp"
#include "Observer.hpp"

NPC::NPC(unsigned hp, unsigned armor, unsigned ammo,
			float speed_b, float speed_npc, char fract, int x, int y)
{
	this->hp = hp;
	this->armor = armor;

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

char	NPC::randomDir()
{
	char variants[4] = { 'w', 'a', 's', 'd' };
	return (variants[rand() % 4]);

}
void NPC::move()
{

}

void NPC::tik(char dir)
{
	//move();
	//shot();
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

void NPC::shot()
{
	//create new instance of bullet(speed_bullet)
}

void NPC::die()
{
	//self destruction
}
