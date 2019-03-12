/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 09:57:26 by mvolkov           #+#    #+#             */
/*   Updated: 2018/11/13 22:53:14 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	render_init_pair(void)
{
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_WHITE);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_YELLOW);
	init_pair(10, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_WHITE, COLOR_RED);
	init_pair(13, COLOR_WHITE, COLOR_BLUE);
	init_pair(14, COLOR_WHITE, COLOR_YELLOW);
	init_pair(15, COLOR_WHITE, COLOR_GREEN);
}

void	init_window(t_prog *p)
{
	initscr();
	start_color();
	render_init_pair();
	cbreak();
	noecho();
	p->window = newwin(WIN_HEIGHT, WIN_WIDTH, 0, 0);
	wbkgd(p->window, COLOR_PAIR(0));
	nodelay(stdscr, true);
	curs_set(0);
	werase(p->window);
	p->time_sleep = 5000;
}
