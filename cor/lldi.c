/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
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
T_REG | T_DIR | T_IND      T_REG | T_DIR    T_REG
Аналогично ldi, но без % IDX_MOD 
(это касается только операции (первй аргумент плюс второй аргумент)) плюс позиция PC),
при операции (T_IND % IDX_MOD) IDX_MOD все так же учитывается).
И в зависимости от того, что записали в третий аргумент меняем carry.
Если записали 0 меняем caryy на 1, если не 0 - меняем на 0.


ldi:
С позиции (((первый плюс второй аргумент) % IDX_MOD) плюс текущая позивиця PC)
считывается 4 байта и записывается в третий аргумент.
- Если первый аргумент T_IND - то значение первого аргумента для операции будет:
4 байта считанные с позиции ((T_IND % IDX_MOD) плюс текущая позиция PC)
*/



unsigned int lldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int current_pos;;
	t_check *c;
	unsigned int temp;

	current_pos = map[proc->pos + 2];
	get_args(proc, c, type, map);
	if (type[0] == 4)
	{
		ft_memcpy((void*)c->ind, (const void*)&map[(c->arg[0] % IDX_MOD) + proc->pos], 4);
		c->arg[0] = c->ind;
	}
	ft_memcpy((void*)prec->reg[c->arg[2]], (const void*)&map[c->arg[0] + c->arg[1] + prec->pos], 4);
	check_carry(c);
}

