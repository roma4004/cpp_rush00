/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NPC.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:05:06 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/29 22:29:34 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NPC.hpp"
#include "test.cpp"

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

	map[y][x] = 2;
	print_map();

	std::cout << "NPC created!" << std::endl;
}

NPC::~NPC()
{
	std::cout << "NPC deleted!" << std::endl;
}

void NPC::move(float b_x, float b_y)
{
	map[pos.x][pos.y] = 0;
	pos = (t_vec_int) { (int)b_x, (int)b_y };
	map[pos.x][pos.y] = 2;
}

void NPC::rotate(char dir)
{
	if (this->direction != dir) {
		this->direction = dir;
	}
	else{
		switch (dir){
		case 'w': if (!map[pos.y - 1][pos.x]) move(pos.y - 1, pos.x); break;
		case 'a': if (!map[pos.y][pos.x - 1]) move(pos.y, pos.x - 1); break;
		case 's': if (!map[pos.y + 1][pos.x]) move(pos.y + 1, pos.x); break;
		case 'd': if (!map[pos.y][pos.x + 1]) move(pos.y, pos.x + 1); break;
		default: std::cout << "invalid dirrection" << std::endl;
		}
	}
	
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