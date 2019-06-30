/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NPC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:05:10 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 15:48:29 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Observer.hpp"

class NPC
{
	public: 
	NPC(unsigned hp, unsigned armor, unsigned ammo,
		float speed_b, float speed_npc, char fract, int x, int y, Observer);
	~NPC();


	void tik(char a);
	protected:

	typedef struct	s_vector_integer {
		int x;
		int y;
	}				t_vec_int;

	typedef struct	s_vector_float {
		float x;
		float y;
	}				t_vec_fl;


	Observer*	_obs;
	t_vec_fl	pos;
	unsigned	hp;
	unsigned	armor;
	unsigned	ammunition;

	float		speed_bullet;
	float		speed;

	char		fraction;
	char		_direction;

	bool		is_obstacle;
	bool		invinsible;
	bool		speed_boost;
	bool		autopilote;

	void		move();
	void		moveAI();
	void shot();
	void		die();
	void		takeDamage(unsigned int damage);
	void		display();
};
