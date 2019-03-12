/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:07:07 by gdanylov          #+#    #+#             */
/*   Updated: 2018/11/14 17:59:47 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

size_t	add_to_kill_proc1(t_proc *buf, int ctd)
{
	return (ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					buf->pid, buf->live_cycle, ctd));
}

void	add_to_kill_proc2(t_proc **buf, t_proc **prev)
{
	(*prev)->next = (*buf)->next;
	free(*buf);
	(*buf) = (*prev)->next;
}

void	add_to_kill_proc3(t_proc **prcs, t_proc **buf)
{
	*prcs = (*buf)->next;
	free(*buf);
	(*buf) = *prcs;
}

void	add_to_proc_control(t_proc *prcs, unsigned char *mem)
{
	prcs->cmnd = mem[prcs->pos] - 1;
	prcs->cycles_to_do = g_op_tab[prcs->cmnd].cycles_to_do;
	prcs->cycles_to_do--;
}

t_proc	*ft_add_proc(t_proc *prcs, t_proc *newproc, t_prog *p)
{
	t_proc *buf;

	p->proc_cnt++;
	if (prcs && newproc)
	{
		buf = prcs;
		prcs = newproc;
		prcs->next = buf;
	}
	else if (newproc)
		prcs = newproc;
	return (prcs);
}
