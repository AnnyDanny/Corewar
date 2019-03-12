/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <gdanylov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 18:37:15 by vmorguno          #+#    #+#             */
/*   Updated: 2018/11/16 15:23:23 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visual.h"

void		vmachine_small_circle(t_prog *p, unsigned char *mem,
int *cycles_to_die, int *curr_round)
{
	if (p->vis)
	{
		draw_all(p, *cycles_to_die, p->counter, mem);
		render_keyboard(p);
		refresh_map(p);
	}
	if (!p->pause || !p->vis)
	{
		if (p->verbose & 2)
			p->printed += ft_printf("It is now cycle %d\n", p->counter);
		ft_proc_control(p->prcs, mem, p);
		p->counter++;
		*curr_round -= 1;
		if (p->vis)
			refresh_map(p);
	}
	if (p->pause_s)
	{
		p->pause = 1;
		p->pause_s = 0;
	}
}

void		big_circle_helper(t_prog *p, int cycles_to_die)
{
	int i;

	i = -1;
	while (++i < p->players)
		p->lives_procent_last[i] = p->lives_procent[i];
	if (cycles_to_die == -14 || p->counter > p->nbr_cycles)
	{
		if (p->counter > p->nbr_cycles)
			p->verbose = 0;
		ft_kill_proc(&p->prcs, ALL, cycles_to_die, p);
	}
}

int			ft_vmachine(t_prog *p, unsigned char *mem)
{
	int	cycles_to_die;
	int	curr_round;

	p->counter = 1;
	cycles_to_die = CYCLE_TO_DIE;
	while ((cycles_to_die > 0 || cycles_to_die == -14)
	&& p->counter <= p->nbr_cycles)
	{
		curr_round = cycles_to_die;
		while ((curr_round > 0 || curr_round == -14)
		&& p->counter <= p->nbr_cycles)
			vmachine_small_circle(p, mem, &cycles_to_die, &curr_round);
		big_circle_helper(p, cycles_to_die);
		ft_kill_proc(&p->prcs, DEAD, cycles_to_die, p);
		if (ft_live_proc(p->prcs))
			cycles_to_die = ft_change_cycles(p, cycles_to_die);
		else
			break ;
	}
	if (p->counter == p->nbr_cycles + 1)
		ft_memdumper(mem);
	return (p->last_live_nbr);
}

int			ft_change_cycles(t_prog *p, int cycles_to_die)
{
	int i;
	int	flag;

	i = 0;
	flag = 0;
	p->checks_nbr++;
	while (i < p->players)
	{
		if ((p->lives_tot >= NBR_LIVE ||
		p->checks_nbr == MAX_CHECKS) && !flag)
		{
			flag = 1;
			cycles_to_die -= CYCLE_DELTA;
			p->checks_nbr = 0;
			if (p->verbose & 2)
				p->printed += ft_printf("Cycle to die is now %d\n",\
					cycles_to_die);
		}
		p->lives[i] = 0;
		p->lives_tot = 0;
		i++;
	}
	return (cycles_to_die);
}
