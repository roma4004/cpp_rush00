/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NPC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:05:10 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 16:59:03 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPC_HPP
#define NPC_HPP

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <string>
#include <ncurses.h>
#include <unistd.h>

#include <ctime>

#include "Observer.hpp"

class NPC
{
protected:
	typedef struct	s_vector_integer {
		int x;
		int y;
	}				t_vec_int;

	typedef struct	s_vector_float {
		int x;
		int y;
	}				t_vec_fl;


public:
	NPC(unsigned hp, unsigned armor, unsigned ammo,
		float speed_b, float speed_npc, char fract, int x, int y);
	~NPC();

	t_vec_fl	pos;
	char		fraction;

	void tik(char a);
	protected:

	unsigned			hp;
	unsigned			armor;
	unsigned			ammunition;

	float				speed_bullet;
	float				speed;


	char				_direction;

	bool				is_obstacle;
	bool				invinsible;
	bool				speed_boost;
	bool				autopilote;

	char				randomDir();
	virtual void		move() = 0;
	void				shot();
	void				die();
	void				takeDamage(unsigned int damage);
	void				display();
};


#endif //NPC_HPP