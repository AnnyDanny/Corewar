/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
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
T_DIR | T_IND   T_REG

4

Аналогично ld, но без % IDX_MOD
"Если первый аргумент T_DIR, то идет просто запись первого аргумента в T_REG
Если первый аргумент T_IND, то идем на ячейку от текущей позиции + это значение
с той позиции считываем 4 байта и записываем в T_REG
В зависимости от того, что записали в T_REG меняем carry
Если записали 0, меняем carry на 1, если не ноль - меняем на 0."
*/

unsigned int				lld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned int pos;

	if (get_args(prec, c, type, map) == 1)
	{
		if (type[0] == 2)
			prec->reg[c->arg[2]] = c->arg[0];
		if (type[0] == 4)
		{
			pos = prec->pos + c->arg[0];
			ft_memcpy((void*)proc->reg[c->arg[1]], (const void*)&map[pos], 4);
		}
	}
	check_carry(c);
}