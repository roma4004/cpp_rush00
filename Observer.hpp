/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:09 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 15:43:26 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <list>
#include <iterator>
#include "NPC.hpp"
#include <ctime>


class Observer
{
	bool		_is_pressed_up;
	bool		_is_pressed_left;
	bool		_is_pressed_right;
	bool		_is_pressed_down;
	bool		_is_pressed_q;
	bool		_is_pressed_space;

public:
	Observer();
	~Observer();

	bool		is_game_over;
	int _HP;
	int _Bullets;
	int _Score;
	time_t s_seconds;
	time_t n_seconds;




	void	set_time(bool zero);

};


#endif //OBSERVER_HPP
