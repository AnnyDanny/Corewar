/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_ld_ldi_lld_lldi.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:38:09 by gdanylov          #+#    #+#             */
/*   Updated: 2018/11/14 18:24:09 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			check_arg_ldi(t_arg_type *type, int *arg1,\
				int *arg2, t_arg *args)
{
	if (type[0] == T_DIR)
		(*arg1) = args[0].tbts[0];
	else
		(*arg1) = args[0].qbt;
	if (type[1] == T_DIR)
		(*arg2) = args[1].tbts[0];
	else
		(*arg2) = args[1].qbt;
}

void			check_arg_lldi(t_arg_type *type, int *arg1,\
				int *arg2, t_arg *args)
{
	if (type[0] == T_DIR)
		(*arg1) = args[0].tbts[0];
	else
		(*arg1) = args[0].qbt;
	if (type[1] == T_DIR)
		(*arg2) = args[1].tbts[0];
	else
		(*arg2) = args[1].qbt;
}

size_t			verbose_ldi(int arg1, int arg2,\
				t_arg *args, t_proc *proc)
{
	size_t		printed;

	printed = 0;
	printed += ft_printf("P%5d | ldi %d %d r%d\n",
	proc->pid, arg1, arg2, args[2].obts[0]);
	printed +=\
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
	arg1, arg2, arg1 + arg2, proc->pos + ((arg1 + arg2) % IDX_MOD));
	return (printed);
}

size_t			verbose_lldi(int arg1, int arg2,\
				t_arg *args, t_proc *proc)
{
	size_t		printed;

	printed = 0;
	printed += ft_printf("P%5d | lldi %d %d r%d\n",
	proc->pid, arg1, arg2, args[2].obts[0]);
	printed += ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
	arg1, arg2, arg1 + arg2, proc->pos + (arg1 + arg2));
	return (printed);
}
