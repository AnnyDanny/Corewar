/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_live.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:01:33 by gdanylov          #+#    #+#             */
/*   Updated: 2018/11/16 15:18:22 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visual.h"

void						add_to_live(t_arg *dir, int *num,
t_prog *g, t_proc *proc)
{
	(*dir).qbt = ft_swapuint((*dir).qbt);
	(*num) = ft_get_champ_num(g, proc->player_nbr);
	g->lives_tot++;
}

void						ft_check_print_bytes(t_prog *p)
{
	if (p->verbose && p->printed > MAX_PRINT_SIZE)
		p->verbose = 0;
}
