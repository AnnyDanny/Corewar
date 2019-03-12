/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 09:57:26 by mvolkov           #+#    #+#             */
/*   Updated: 2018/11/13 22:53:39 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	draw_end(t_prog *p, short winner)
{
	wattron(p->window, COLOR_PAIR(winner + 1) | A_BOLD);
	mvwprintw(p->window, 41, 200, "The winner is : %s !",\
	p->champs[winner].name);
	wattroff(p->window, COLOR_PAIR(winner + 1) | A_BOLD);
	mvwprintw(p->window, 43, 200, "Press any key to finish");
	refresh_map(p);
	while (1)
		render_keyboard_end(p);
}

void	set_live(t_prog *p, short champ_num, unsigned int pos)
{
	p->color_map[pos] = champ_num + 12;
	p->color_cycles[pos] = 49;
}

void	new_colors(short champ_num, int start, t_prog *p)
{
	unsigned int	i;

	i = 0;
	while (i < 4)
	{
		if ((p->color_map[ft_check_pos(start)] < 5\
		|| p->color_map[ft_check_pos(start)] > 11))
		{
			p->color_map[ft_check_pos(start)] = champ_num + 1;
			p->color_cycles[ft_check_pos(start)] = 49;
		}
		i++;
		start++;
	}
}

void	render_keyboard(t_prog *p)
{
	int				key_input;

	key_input = getch();
	if (key_input == 32 && p->pause == 0)
	{
		p->pause = 1;
		mvwprintw(p->window, 2, 200, PAUSE);
		refresh_map(p);
	}
	else if (key_input == 32 && p->pause == 1)
		p->pause = 0;
	else if (key_input == 45 && p->time_sleep < 80000)
		p->time_sleep += 2500;
	else if (key_input == 43 && p->time_sleep > 0)
		p->time_sleep -= 2500;
	else if (key_input == 115)
	{
		p->pause_s = 1;
		p->pause = 0;
	}
}

void	render_keyboard_end(t_prog *p)
{
	int				key_input;

	key_input = getch();
	if (key_input > 0)
	{
		delwin(p->window);
		endwin();
		exit(0);
	}
}
