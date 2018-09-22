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
*/

unsigned int and(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	c->codage = map[g->pos + 1];
	check_codage(c);
	check_first_arg(c);
	check_second_arg(c);
	check_third_arg(c);
	c->reg = c->arg1 & c->arg2;
	check_carry(c);	
}
