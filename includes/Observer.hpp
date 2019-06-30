/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:09 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 23:04:14 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <list>
#include <iterator>
#include <ctime>

#include "NPC.hpp"


class Observer
{

public:
	Observer();
	Observer(const Observer& other);
	~Observer();

	Observer& operator=(const Observer& other);

	bool		is_game_over;
	int			_HP;
	int			_Bullets;
	int			_Score;
	time_t		s_seconds;
	time_t		n_seconds;
	void		set_time(bool zero);

};

void	stage_two(WINDOW *win, int y_max, int x_max, class Observer obs);
void	move_player(char ch, class NPC& player, int y_max, int x_max,
						std::list<class NPC*>& objects, Observer &obs);
void stage_three(WINDOW *win, int y_max, int x_max, class Observer obs);
#endif //OBSERVER_HPP
