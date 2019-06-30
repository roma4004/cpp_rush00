/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NPC.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:05:06 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 12:11:35 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NPC.hpp"

NPC::NPC(unsigned hp, unsigned armor, unsigned ammo,
			float speed_b, float speed_npc, char fract, int x, int y)
{
	this->hp = hp;
	this->armor = armor;

	this->ammunition = ammo;
	this->speed_bulet = speed_b;
	this->speed = speed_npc;
	this->fraction = fract;

	this->pos = (t_vec_int){ x, y };


	std::cout << "NPC created!" << std::endl;
}

NPC::~NPC()
{
	std::cout << "NPC deleted!" << std::endl;
}

void NPC::move(float b_x, float b_y)
{

}

void NPC::rotate(char dir)
{

	
}

void NPC::tik(char dir)
{
	rotate(dir);
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
