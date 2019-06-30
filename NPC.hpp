/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NPC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:05:10 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 12:26:03 by dromanic         ###   ########.fr       */
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
		int x;
		int y;
	}				t_vec_fl;




	t_vec_int	pos;
	unsigned	hp;
	unsigned	armor;
	unsigned	ammunition;

	float		speed_bulet;
	float		speed;

	char		fraction;
	char		direction;

	bool		is_obstacle;
	bool		invinsible;
	bool		speed_boost;
	bool		autopilote;



	void		move(float b_x,float b_y);
	void		rotate(char dir);
	void		shot(char where);
	void		die();
	void		takeDamage(unsigned int damage);
	void		display();
};
