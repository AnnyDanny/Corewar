/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
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
*/

unsigned int sub(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	c->codage = map[g->pos + 1];
	check_codage(c);
	check_first_arg(c);
	check_second_arg(c);
	check_third_arg(c);
	c->reg = c->arg1 - c->arg2;
	check_carry(c);
}
