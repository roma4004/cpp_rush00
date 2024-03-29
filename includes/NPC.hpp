/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NPC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:05:10 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 23:09:05 by dromanic         ###   ########.fr       */
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

#include "Observer.hpp"

class NPC
{
private:
	typedef struct	s_vector_integer {
		int x;
		int y;
	}				t_vec_int;

	typedef struct	s_vector_float {
		float x;
		float y;
	}				t_vec_fl;


public:
	NPC(unsigned hp, unsigned armor, unsigned ammo,
		float speed_b, float speed_npc, char fract, int x, int y, char);
	NPC(const NPC& other);
	~NPC();

	NPC& operator=(const NPC& other);


	t_vec_fl	pos;
	char		randomDir();
	char		fraction;
	void 		move(std::list<NPC*> objects, int y, int x);
	char		_direction;
	float		speed_bullet;
	float		speed;
	unsigned	hp;
protected:

	unsigned	armor;
	unsigned	ammunition;

	void		shot();
	void		die();
	void		takeDamage(unsigned int damage);
};




#endif //NPC_HPP