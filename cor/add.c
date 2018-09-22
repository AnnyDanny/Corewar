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

unsigned int add(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	c->codage = map[g->pos + 1];
	check_codage(c);
	check_first_arg(c);
	check_second_arg(c);
	check_third_arg(c);
	c->reg = c->arg1 + c->arg2;
	check_carry(c);
}
