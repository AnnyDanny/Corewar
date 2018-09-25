/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
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
T_REG
значение из аргумента % 256 выводится на экран как ASCII символ
*/

unsigned int get_args(t_proc *proc, t_check *c, t_arg_type *type, unsigned char *map)
{
	c->pos = map[proc->pos + 2];

	ft_memcpy((void*)c->arg[0], (const void*)&map[c->pos], 1);
	if (c->arg[0] >= 0 && c->arg[0] <= 16)
		c->arg[0] = c->arg[0] % 256;
	ft_printf("%u", c->arg[0]);
}