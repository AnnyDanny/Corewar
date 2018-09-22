/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_sec_third.c                            :+:      :+:    :+:   */
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


unsigned int add(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	c->codage = map[g->pos + 1];
	check_codage(c);
	check_first_arg(c);
	check_second_arg(c);
	check_third_arg(c);
	g->reg[] = c->arg1 + c->arg2;
	check_carry(c);
}


void check_first_arg(t_check *c)
{
	c->pos_first_arg = g->reg[map[pos + 2]];

	if (c->check_arg1 == 1)
	{
		ft_memcpy((void*)c->arg1, (const void*)g->reg[c->pos_first_arg], 1);
		c->pos_second_arg = map[c->pos_first_arg + 1];
	}
	if (c->check_arg1 == 2)
	{
		ft_memcpy((void*)c->arg1, (const void*)map[c->pos_first_arg], 4);
		c->pos_second_arg = map[c->pos_first_arg + 4];
	}
	if (c->check_arg1 == 3)
	{
		ft_memcpy((void*)c->arg1, (const void*)map[c->pos_first_arg], 2);
		c->pos_second_arg = map[c->pos_first_arg + 2];
	}
}

void check_second_arg(t_check *c)
{
	if (c->check_arg2 == 1)
	{
		ft_memcpy((void*)c->arg2, (const void*)map[c->pos_second_arg], 1);
		c->pos_third_arg = map[c->pos_second_arg + 1];
	}
	if (c->check_arg2 == 2)
	{
		ft_memcpy((void*)c->arg2, (const void*)map[c->pos_second_arg], 4);
		c->pos_third_arg = map[c->pos_second_arg + 4];
	}
	if (c->check_arg2 == 3)
	{
		ft_memcpy((void*)c->arg2, (const void*)map[c->pos_second_arg], 2);
		c->pos_third_arg = map[c->pos_second_arg + 2];
	}
}

void check_third_arg(t_check *c)
{
	if (c->check_arg3 == 1)
		ft_memcpy((void*)c->reg, (const void*)map[c->pos_third_arg], 1);
}
