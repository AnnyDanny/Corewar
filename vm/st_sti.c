/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:07:17 by gdanylov          #+#    #+#             */
/*   Updated: 2018/11/14 17:56:34 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visual.h"

unsigned int		st(t_proc *proc, t_prog *g, t_arg_type *type,
unsigned char *map)
{
	unsigned int	ret;
	t_arg			*args;
	t_arg			r;

	args = ft_memalloc(sizeof(t_arg) * 2);
	if ((ret = get_args(proc, args, type, map)) == 0xff)
	{
		free(args);
		return (ft_calc_move(type, proc));
	}
	ft_read_mem(&r, map, 1, proc->pos + 2);
	if (type[1] == T_IND)
	{
		args[0].qbt = ft_swapuint(args[0].qbt);
		ft_write_mem(&args[0], map, T_IND,
		proc->pos + (args[1].tbts[0] % IDX_MOD));
		if (g->vis)
			new_colors(ft_get_champ_num(g, proc->player_nbr),
			proc->pos + (args[1].tbts[0] % IDX_MOD), g);
		add_to_st1(g, proc, args, r);
	}
	if (type[1] == T_REG)
		add_to_st2(proc, args, g, r);
	free(args);
	return (ret);
}

unsigned int		sti(t_proc *proc, t_prog *g, t_arg_type *type,
unsigned char *map)
{
	int				arg1;
	int				arg2;
	unsigned int	ret;
	t_arg			*args;
	t_arg			r;

	ft_read_mem(&r, map, 1, proc->pos + 2);
	args = ft_memalloc(sizeof(unsigned int) * 2);
	if ((ret = get_args(proc, args, type, map)) == 0xff)
	{
		free(args);
		return (ft_calc_move(type, proc));
	}
	args[0].qbt = ft_swapuint(args[0].qbt);
	add_to_sti1(type, &arg1, &arg2, args);
	ft_write_mem(&args[0], map, 4, proc->pos + ((arg1 + arg2) % IDX_MOD));
	if (g->vis)
		new_colors(ft_get_champ_num(g, proc->player_nbr),
		proc->pos + ((arg1 + arg2) % IDX_MOD), g);
	if (g->verbose & 4)
		g->printed += add_to_sti2(proc, r, arg1, arg2);
	free(args);
	return (ret);
}
