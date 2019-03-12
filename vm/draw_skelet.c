/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skelet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 09:57:26 by mvolkov           #+#    #+#             */
/*   Updated: 2018/11/13 22:53:21 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		draw_bare(t_prog *p)
{
	int i;
	int pair;

	i = -1;
	pair = 0;
	mvwprintw(p->window, 28, 200, "[");
	while (++i < 51)
	{
		if (i < p->lives_procent[0])
			pair = 1;
		else if (i < p->lives_procent[1])
			pair = 2;
		else if (i < p->lives_procent[2])
			pair = 3;
		else if (i < p->lives_procent[3])
			pair = 4;
		else
			pair = 0;
		wattron(p->window, COLOR_PAIR(pair) | A_BOLD);
		mvwprintw(p->window, 28, 201 + i, "-");
		wattroff(p->window, COLOR_PAIR(pair) | A_BOLD);
	}
	mvwprintw(p->window, 28, 251, "]");
}

void		draw_bare_last(t_prog *p)
{
	int i;
	int pair;

	i = -1;
	pair = 0;
	mvwprintw(p->window, 31, 200, "[");
	while (++i < 51)
	{
		if (i < p->lives_procent_last[0])
			pair = 1;
		else if (i < p->lives_procent_last[1])
			pair = 2;
		else if (i < p->lives_procent_last[2])
			pair = 3;
		else if (i < p->lives_procent_last[3])
			pair = 4;
		else
			pair = 0;
		wattron(p->window, COLOR_PAIR(pair) | A_BOLD);
		mvwprintw(p->window, 31, 201 + i, "-");
		wattroff(p->window, COLOR_PAIR(pair) | A_BOLD);
	}
	mvwprintw(p->window, 31, 251, "]");
}

void		draw_info_tab(t_prog *p)
{
	if (!p->pause)
		mvwprintw(p->window, 2, 200, RUN);
	else
		mvwprintw(p->window, 2, 200, PAUSE);
	mvwprintw(p->window, 4, 200, CYCLES_SECONDS);
	mvwprintw(p->window, 7, 200, CYCLE);
	mvwprintw(p->window, 9, 200, PROCESSES);
	mvwprintw(p->window, 27, 200, CURRENT);
	mvwprintw(p->window, 30, 200, LAST);
	mvwprintw(p->window, 33, 200, TO_DIE);
	mvwprintw(p->window, 35, 200, DELTA);
	mvwprintw(p->window, 37, 200, LIVE);
	mvwprintw(p->window, 39, 200, MAX_CHECKS_VIS);
}

void		draw_skelet(t_prog *p)
{
	int i;

	wattron(p->window, COLOR_PAIR(5));
	wborder(p->window, '|', '|', '-', '-', '+', '+', '+', '+');
	i = 0;
	while (++i < WIN_HEIGHT - 1)
		mvwprintw(p->window, i, 196, "|");
	wattroff(p->window, COLOR_PAIR(5));
}
