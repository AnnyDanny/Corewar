/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                             :+:      :+:    :+:   */
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
T_REG T_REG T_REG
результат (первый плюс второй аргумент) записывается в третий.
в зависимости от того, что записали в третий меняем carry
если записали 0 меняем carry на  1, если не 0 меняем на 0

Я их переписаваю в чары так чтобы T_IND был равен дефайну в op.h
А аргументы заходят массивом как *t_arg_type
Короче чтобы ты могла в коде использовать их
Типа if args[i] = T_IND
если в аргументе хранится число:
- 1 = T_REG;
- 2 = T_DIR;
- 4 = T_IND;
*/

*a

if (args[0] == 1)
	a[0] = r;
else if (args[0] == 2)
	a[0] = d;
else if (args[0] == 4)
	a[0] = i;
else if (args[1] == 1)
	a[1] = r;
else if (args[1] == 2)
	a[1] = d;
else if (args[1] == 4)
	a[1] = i;
else if (args[2] == 1)
	a[2] = r;
else if (args[2] == 2)
	a[1] = d;
else if (args[2] == 4)
	a[2] = i;


void from_map_add(t_check *c)
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


unsigned int add(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	c->codage = map[g->pos + 1];
	check_codage(c);
	from_map_add(c);
	c->t_reg3 = c->reg1 + c->reg2;
	check_carry(c);	
}