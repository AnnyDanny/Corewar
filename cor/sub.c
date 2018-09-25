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
результат (первый минус второй аргумент) записывается в третий.
в зависимости от того, что записали в третий меняем carry
если записали 0 меняем carry на  1, если не 0 меняем на 0
*/

unsigned int sub(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	if (get_args(proc, c, type, map) == 1)
		proc->reg[c->arg[2]] = c->arg[0] - c->arg[1];
	check_carry(c);
}
