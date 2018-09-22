/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
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

/*
T_REG    T_REG | T_IND
4

значение T_REG (первый аргумент) записывается:
- если второй аргумент T_IND, то в ячейку по адресу (текущая позиция PC плюс (T_IND % IDX_MOD))
- если второй аргумент T_REG, то в регистр по этому номеру
*/

void from_map_st(t_check *c, unsigned char *map)
{
	unsigned char pos_ind;
	unsigned char t_reg;

	c->first_arg = map[g->pos + 2];
	if (c->arg1 == 1)
	{
		ft_memcpy((void*)c->reg, (const void*)map[c->first_arg], 1)
		c->second_arg = map[c->first_arg + 1];
	}
	if (c->arg2 == 3)
	{
		ft_memcpy((void*)c->ind, (const void*)map[c->second_arg], 2);
		ft_memcpy((void*)map[g->pos + (c->ind % IDX_MOD)], (const void*)arg1, 1);
		// pos_ind = map[c->first_arg + (c->ind % IDX_MOD)];
	}
	else if (c->arg2 == 1)
	{
		ft_memcpy((void*)t_reg, (const void*)map[c->second_arg], 1);
		ft_memcpy((void*)map[t_reg], (const void*)t_reg, 1);
		// g->reg[t_reg] = c->reg;
	}
}

unsigned int st(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	c->codage = map[g->pos + 1];
	check_codage(c);
	from_map_st(c, map);
}