/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Observer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <dromanic@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:26:09 by dromanic          #+#    #+#             */
/*   Updated: 2019/06/30 12:29:27 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP


class Observer
{

	bool		_is_game_over;

	bool		_is_pressed_up;
	bool		_is_pressed_left;
	bool		_is_pressed_right;
	bool		_is_pressed_down;
	bool		_is_pressed_q;

	void		event_handler();
	void		game_cycle();
};


#endif //OBSERVER_HPP
