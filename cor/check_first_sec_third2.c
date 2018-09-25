/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_sec_third2.c                           :+:      :+:    :+:   */
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


int check_first_arg_2(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	c->pos_first_arg = map[proc->pos + 2];
	if (type->args[0] == 1)
	{
		ft_memcpy((void*)c->reg, (const void*)&map[c->pos_first_arg], 1);
		if (c->reg >= 0 && c->reg <= 16)
			c->arg1 = c->reg;
		else
			return (0);
		c->pos_second_arg = map[c->pos_first_arg + 1];
	}
	if (type->args[0] == 2)
	{
		ft_memcpy((void*)c->arg1, (const void*)&map[c->pos_first_arg], 2);
		c->pos_second_arg = map[c->pos_first_arg + 2];
	}
	if (type->args[0] == 4)
	{
		ft_memcpy((void*)c->arg1, (const void*)&map[c->pos_first_arg], 2);
		c->pos_second_arg = map[c->pos_first_arg + 2];
	}
	return (1);
}

int check_second_arg_2(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	if (type->args[1] == 1)
	{
		ft_memcpy((void*)c->reg, (const void*)&map[c->pos_second_arg], 1);
		if (c->reg >= 0 && c->reg <= 16)
			c->arg2 = c->reg;
		else
			return (0);
		c->pos_third_arg = map[c->pos_second_arg + 1];
	}
	if (type->args[1] == 2)
	{
		ft_memcpy((void*)c->arg2, (const void*)&map[c->pos_second_arg], 2);
		c->pos_third_arg = map[c->pos_second_arg + 2];
	}
	if (type->args[1] == 4)
	{
		ft_memcpy((void*)c->arg2, (const void*)&map[c->pos_second_arg], 2);
		c->pos_third_arg = map[c->pos_second_arg + 2];
	}
	return (1);
}

int check_third_arg_2(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	if (type->args[2] == 1)
	{
		ft_memcpy((void*)c->reg, (const void*)map[c->pos_third_arg], 1);
		if (c->reg >= 0 && c->reg <= 16)
			c->arg3 = c->reg;
		else
			return (0);
	}
	if (type->args[2] == 2)
		ft_memcpy((void*)c->arg3, (const void*)&map[c->pos_second_arg], 2);
	return (1);
}
