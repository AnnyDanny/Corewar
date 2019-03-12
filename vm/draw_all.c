/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 09:57:26 by mvolkov           #+#    #+#             */
/*   Updated: 2018/11/13 22:53:29 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		draw_map(t_prog *p, unsigned char *mem)
{
	int x;
	int y;
	int i;

	y = 2;
	i = 0;
	while (y < 66)
	{
		x = 2;
		while (x < 194)
		{
			color_on(p, i);
			mvwprintw(p->window, y, x, "%.2x", (unsigned int)mem[i]);
			color_off(p, i);
			if (p->color_map[i] > 5 && p->color_map[i] < 11)
				p->color_map[i] -= 6;
			if (p->color_map[i] > 11 && p->color_cycles[i] <= 0)
				p->color_map[i] -= 11;
			mvwprintw(p->window, y, x + 2, " ");
			x += 3;
			i++;
		}
		y++;
	}
}

void		change_color(t_prog *p)
{
	t_proc *pr;

	pr = p->prcs;
	while (pr)
	{
		if (p->color_map[pr->pos] < 5)
			p->color_map[pr->pos] = p->color_map[pr->pos] + 6;
		if (p->color_map[pr->pos] > 11)
			p->color_map[pr->pos] = p->color_map[pr->pos] - 5;
		pr = pr->next;
	}
}

void		draw_all(t_prog *p, int cycles, int counter, unsigned char *mem)
{
	usleep(p->time_sleep);
	werase(p->window);
	draw_skelet(p);
	draw_info_tab(p);
	draw_bare(p);
	draw_bare_last(p);
	draw_players(p);
	fill_info_tab(p, cycles, counter);
	change_color(p);
	draw_map(p, mem);
}

void		draw_champ(int i, short champ_num, t_prog *p, unsigned char *mem)
{
	int x;
	int y;
	int j;

	y = 2;
	j = 0;
	while (y < 66)
	{
		x = 2;
		while (x < 194)
		{
			if (j == i)
			{
				wattron(p->window, COLOR_PAIR(champ_num + 1));
				mvwprintw(p->window, y, x, "%.2x ", (unsigned int)mem[i]);
				p->color_map[i] = champ_num + 1;
				wattroff(p->window, COLOR_PAIR(champ_num + 1));
				return ;
			}
			x += 3;
			j++;
		}
		y++;
	}
	champ_num = 0;
}
