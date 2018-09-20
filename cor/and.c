/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
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
применяем & для первых друх аргументов и записываем результат в третий
меняем carry на 1, если результат операции был 0
или меняем carry на 0, если результат операции был не ноль
для каких именно аргументов применяется & ??
*/

void from_map_and(t_check *c)
{
	c->first_arg = map[g.pos + 2];

	if (c->arg1 == 1)
	{
		ft_memcpy((void*)c->t_reg1, (const void*)map[c->first_arg], 1);
		c->second_arg = map[c->first_arg + 1];
	}
	if (c->arg2 == 1)
	{
		ft_memcpy((void*)c->t_reg2, (const void*)map[c->second_arg], 1);
		c->third_arg = map[c->second_arg + 1];
	}
	if (c->arg3 == 1)
		ft_memcpy((void*)c->t_reg3, (const void*)map[c->third_arg], 1);
}


unsigned int and(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	c->codage = map[g->pos + 1];
	check_codage(c);
	from_map_and(c);
	c->t_reg3 = c->reg1 & c->reg2;
	check_carry(c);	
}
