/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 09:57:26 by mvolkov           #+#    #+#             */
/*   Updated: 2018/11/13 22:55:16 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		fill_info_tab(t_prog *p, int cycles, int counter)
{
	mvwprintw(p->window, 4, 233, "%i", p->time_sleep);
	mvwprintw(p->window, 7, 215, "%i", counter);
	mvwprintw(p->window, 9, 215, "%i", p->proc_cnt);
	mvwprintw(p->window, 33, 215, "%i", cycles);
	mvwprintw(p->window, 35, 215, "%i", CYCLE_DELTA);
	mvwprintw(p->window, 37, 215, "%i", NBR_LIVE);
	mvwprintw(p->window, 39, 215, "%i", MAX_CHECKS);
}

void		draw_players(t_prog *p)
{
	int i;
	int skip;
	int total;

	i = -1;
	skip = 0;
	total = 0;
	while (++i < p->players)
	{
		wattron(p->window, COLOR_PAIR(i + 1) | A_BOLD);
		mvwprintw(p->window, 11 + skip, 200, "Player %i -> %s",\
		p->player_nbr[i], p->champs[i].name);
		wattroff(p->window, COLOR_PAIR(i + 1) | A_BOLD);
		mvwprintw(p->window, 12 + skip, 200,\
		"Last live:                       %i", p->last_live_cycle[i]);
		mvwprintw(p->window, 13 + skip, 200,\
		"Lives in current period:         %i", p->lives[i]);
		total += p->lives[i];
		skip += 4;
	}
	if (total == 0)
		return ;
	i = -1;
	while (++i < p->players)
		p->lives_procent[i] = (((p->lives[i] * 100) / total) / 2) * (i + 1);
}

void		refresh_map(t_prog *p)
{
	refresh();
	wrefresh(p->window);
}

void		color_on(t_prog *p, int i)
{
	if (p->color_cycles[i] > 0)
		wattron(p->window, COLOR_PAIR(p->color_map[i]) | A_BOLD);
	else
		wattron(p->window, COLOR_PAIR(p->color_map[i]));
}

void		color_off(t_prog *p, int i)
{
	if (p->color_cycles[i] > 0)
	{
		wattroff(p->window, COLOR_PAIR(p->color_map[i]) | A_BOLD);
		p->color_cycles[i]--;
	}
	else
		wattroff(p->window, COLOR_PAIR(p->color_map[i]));
}
