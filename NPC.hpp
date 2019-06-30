/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NPC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:05:10 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 14:05:55 by dromanic         ###   ########.fr       */
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

#define WIDTH 50
#define HEIGHT 50

float map[HEIGHT][WIDTH];

class NPC
{
	public: 
	NPC(unsigned hp, unsigned armor, unsigned ammo,
		float speed_b, float speed_npc, char fract, int x, int y);
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


	Observer	*obs;
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
	void		shot(char where_dir);
	void		die();
	void		takeDamage(unsigned int damage);
	void		display();
};

void print_map();