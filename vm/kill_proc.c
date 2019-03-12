/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:10:55 by gdanylov          #+#    #+#             */
/*   Updated: 2018/11/16 14:03:52 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_kill_proc(t_proc **prcs, bool mode, int ctd, t_prog *p)
{
	t_proc *buf;
	t_proc *prev;

	buf = *prcs;
	prev = NULL;
	while (buf)
	{
		if (!buf->live || buf->live == mode)
		{
			p->proc_cnt--;
			if (p->verbose & 8)
				p->printed += add_to_kill_proc1(buf, ctd);
			if (prev)
				add_to_kill_proc2(&buf, &prev);
			else
				add_to_kill_proc3(prcs, &buf);
		}
		else
		{
			prev = buf;
			buf = buf->next;
		}
	}
}
