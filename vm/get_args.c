/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 05:24:24 by gdanylov          #+#    #+#             */
/*   Updated: 2018/11/14 21:55:02 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				check_carry(unsigned int arg, t_proc *proc)
{
	proc->carry = arg == 0 ? 1 : 0;
}

unsigned int		get_args(t_proc *proc, t_arg *arg, t_arg_type *type,
								unsigned char *map)
{
	int				i;
	unsigned int	ret;

	i = 0;
	ret = proc->pos + 2;
	while (i < g_op_tab[proc->cmnd].arg_qnt)
	{
		if (type[i] == T_REG)
		{
			ret += get(&arg[i], map, T_REG_SIZE, ret);
			if (add_to_get_args1(arg, &i, proc) == 0)
				return (0xff);
		}
		if (type[i] == T_DIR)
			ret += get(&arg[i], map, 4 -\
				(2 * g_op_tab[proc->cmnd].label), ret);
		if (type[i] == T_IND)
		{
			ret += get(&arg[i], map, T_IND_SIZE, ret);
			if (proc->cmnd != 12 && proc->cmnd != 2)
				add_to_get_args2(arg, &i, map, proc);
		}
		i++;
	}
	return (ret - proc->pos);
}

void				ft_read_mem(t_arg *arg, unsigned char *mem,
								unsigned int size, int start)
{
	unsigned int	i;

	i = 0;
	while (i < size && i < 4)
	{
		(*arg).obts[i] = mem[ft_check_pos(start)];
		i++;
		start++;
	}
}

unsigned int		ft_check_pos(int i)
{
	while (i < 0)
		i += MEM_SIZE;
	while (i >= MEM_SIZE)
		i -= MEM_SIZE;
	return (i);
}

void				ft_write_mem(t_arg *arg, unsigned char *mem,
									unsigned int size, int start)
{
	unsigned int	i;

	i = 0;
	while (i < size && i < 4)
	{
		mem[ft_check_pos(start)] = arg->obts[i];
		i++;
		start++;
	}
}
