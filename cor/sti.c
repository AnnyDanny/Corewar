/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
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
T_REG    T_REG | T_DIR | T_IND.    T_REG | T_DIR

2

значение T_REG (первый аргумент) записывается в ячейку по адресу 
((текущая позиция PC плюс (второй аргумент плюс третий аргумент) % IDX_MOD)
- Если второй аргумент T_IND - то ясное дело, что вместо второго аргумента, в уравнение
подставляются те 4 байта, которые мы берем из ячейки (T_IND % IDX_MOD)
*/

unsigned int ldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned char int pos;

	if (get_args(prec, c, type, map) == 1)
	{
		if (c->type[1] == 4)
			ft_memcpy((void*)c->arg[1], (const void*)&map[c->arg[1] % IDX_MOD], 4);
		ft_memcpy((void*)&map[proc->pos + (c->arg[1] + c->arg[2]) % IDX_MOD], (const void*)c->arg[0], 1);
	}
}