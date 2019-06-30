/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:27 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 23:09:05 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Observer.hpp"

Observer::Observer()
{
	this->_Score = 0;
	this->_HP = 10;
	this->_Bullets = 200;
	is_game_over = false;
	s_seconds = time(nullptr);
}

Observer::Observer(const Observer &other)
{
	*this = other;
}

Observer::~Observer()
{

}

Observer &Observer::operator=(const Observer& other)
{
	if (this != &other)
	{
		_HP			= other._HP		;
		_Bullets	= other._Bullets;
		_Score		= other._Score	;
	}
	return *this;
}

void Observer::set_time(bool zero) {

	if (zero == 1)
	{
		s_seconds = time(nullptr);
		return;
	}
	n_seconds = time(nullptr) - s_seconds;
}

