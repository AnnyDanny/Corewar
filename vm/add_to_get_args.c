/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_get_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:52:00 by gdanylov          #+#    #+#             */
/*   Updated: 2018/11/16 14:48:49 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					check_reg(unsigned char arg)
{
	int				i;

	i = 0;
	if (arg > 0 && arg <= 16)
		return (1);
	else
		return (0);
}

unsigned int		ft_calc_move(t_arg_type *type, t_proc *proc)
{
	unsigned int	ret;
	int				i;

	i = 0;
	ret = 0;
	while (i < g_op_tab[proc->cmnd].arg_qnt)
	{
		if (type[i] == T_DIR)
			ret += 4 - (2 * g_op_tab[proc->cmnd].label);
		else if (type[i] == T_IND)
			ret += T_IND_SIZE;
		else
			ret += type[i];
		i++;
	}
	return (ret + 2);
}

unsigned int		get(t_arg *arg, unsigned char *map,
						unsigned int size, unsigned int start)
{
	ft_read_mem(arg, map, size, start);
	if (size == 2)
		arg->tbts[0] = ft_swapshrt(arg->tbts[0]);
	if (size == 4)
		arg->qbt = ft_swapuint(arg->qbt);
	return (size);
}

int					add_to_get_args1(t_arg *arg, int *i, t_proc *proc)
{
	if (!check_reg(arg[(*i)].obts[0]))
		return (0);
	if ((*i) != g_op_tab[proc->cmnd].arg_qnt - 1 || proc->cmnd == 10 || proc->cmnd == 15)
		arg[(*i)].qbt = proc->reg[arg[(*i)].obts[0] - 1];
	return (1);
}

void				add_to_get_args2(t_arg *arg, int *i,
unsigned char *map, t_proc *proc)
{
		ft_read_mem(&arg[(*i)], map, T_IND,
		proc->pos + (arg[(*i)].tbts[0] % IDX_MOD));
	arg[(*i)].qbt = ft_swapuint(arg[(*i)].qbt);
}
