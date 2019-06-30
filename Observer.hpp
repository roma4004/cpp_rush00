/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:09 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 16:53:53 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <list>
#include <iterator>
#include "NPC.hpp"
#include "Enemy.hpp"
#include "Player.hpp"


class Observer
{

public:

	bool			is_game_over;

	void			event_handler();
	void			game_cycle();

};


#endif //OBSERVER_HPP
