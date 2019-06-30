/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:27 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 15:43:28 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Observer.hpp"

Observer::Observer()
{
	this->_Score = 0;
	this->_HP = 10;
	this->_Bullets = 200;
	s_seconds = time (NULL);
}

Observer::~Observer()
{

}

void Observer::set_time(bool zero) {
	if (zero == 1)
	{
		s_seconds = time(NULL);
		return;
	}
	n_seconds =  time(NULL) - s_seconds;
}