/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_st_sti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:13:19 by gdanylov          #+#    #+#             */
/*   Updated: 2018/11/14 22:10:03 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visual.h"

void				add_to_st1(t_prog *g, t_proc *proc, t_arg *args, t_arg r)
{
	if (g->verbose & 4)
		g->printed += ft_printf("P%5d | st r%d %d\n",
	proc->pid, r.obts[0], args[1].tbts[0]);
}

void				add_to_st2(t_proc *proc, t_arg *args, t_prog *g, t_arg r)
{
	proc->reg[args[1].obts[0] - 1] = args[0].qbt;
	if (g->verbose & 4)
		g->printed += ft_printf("P%5d | st r%d %d\n",
	proc->pid, r.obts[0], args[1].obts[0]);
}

size_t				add_to_sti2(t_proc *proc, t_arg r, int arg1, int arg2)
{
	size_t			printed;

	printed = 0;
	printed += ft_printf("P%5d | sti r%d %d %d\n", proc->pid,\
		r.obts[0], arg1, arg2);
	printed +=\
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
	arg1, arg2, arg1 + arg2, proc->pos + ((arg1 + arg2) % IDX_MOD));
	return (printed);
}

void				add_to_sti1(t_arg_type *type, int *arg1,
int *arg2, t_arg *args)
{
	if (type[1] == T_DIR)
		(*arg1) = args[1].tbts[0];
	else
		(*arg1) = args[1].qbt;
	if (type[2] == T_DIR)
		(*arg2) = args[2].tbts[0];
	else
		(*arg2) = args[2].qbt;
}
