/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 05:24:24 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/14 05:24:25 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <op.c>
#include <cor.h>

void from_map_load(t_check *c)
{
	c->first_arg = map[g->pos + 2];
	if (c->arg1 == 2)
	{
		ft_memcpy((void*)c->dir, (const void*)map[c->first_arg], 4);
		c->second_arg = map[c->first_arg + 4];
	}
	else if (c->arg1 == 3)
	{
		ft_memcpy((void*)c->ind, (const void*)map[c->first_arg], 3);
		c->second_arg = map[c->first_arg + 3];
	else if (c->arg2 == 1)
		ft_memcpy((void*)c->reg, (const void*)map[c->second_arg], 1);
}

int check_valid_reg(t_check *c)
{
	if (c->reg >= 1 && c->reg <= 16)
		return (1);
	return (0);
}

unsigned int				load(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	int tmp;
	unsigned char pos_ind;

	tmp = 0;
	c->codage = map[g->pos + 1];
	check_codage(c);
	from_map_load(c);
	if (c->arg1 == 2)
		g->reg[reg] = c->dir;
	else if (c->arg1 == 3)
	{
		tmp = c->ind % IDX_MOD;
		pos_ind = map[c->first_arg + tmp];
		ft_memcpy((void*)c->reg, (const void*)map[pos_ind], 4);
	}
	check_valid_reg(c);
	check_carry(c);
}
