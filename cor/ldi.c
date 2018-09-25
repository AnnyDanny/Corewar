/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
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
T_REG | T_DIR | T_IND    T_REG | T_DIR   T_REG

2

С позиции (((первый плюс второй аргумент) % IDX_MOD) плюс текущая позивиця PC)
считывается 4 байта и записывается в третий аргумент.
- Если первый аргумент T_IND - то значение первого аргумента для операции будет:
4 байта считанные с позиции ((T_IND % IDX_MOD) плюс текущая позиция PC)

1 - записать в переменную текущую позицию;
2 - проверить если первый аргумент т инд, тогда:
    -- записать в переменную значени т инд остаток от идикс мод;
    -- к этой переменной прибавить переменную с текущей поцизией и записать это значение и записать в новую позицию;
    -- считать с новой позиции 4 байта и записать это значение в т инд;
3 - если первый аргумегт т дир или т рег
	-- записать первый аргумент в переменную арг1;
4 - записать второй аргумент в переменную арг2;
5 - записать в переменную первый плюс второй аргумент остаток от идиск мод + текущая позиция;
6 - считать 4 байта с этой переменной и записать в третий аргумент (в т рег)
*/

// void check_first(t_check *c)
// {
// 	unsigned int c->pos_first_arg;

// 	c->pos_first_arg = map[g->pos + 2];
// 	if (c->check_arg1 == 1)
// 	{
// 		ft_memcpy((void*)arg1, (const void*)map[pos_first_arg], 1);
// 		c->pos_second_arg = c->pos_first_arg + 1;
// 	}
// 	else if (c->check_arg1 == 2)
// 	{
// 		ft_memcpy((void*)arg1, (const void*)map[pos_first_arg], 2);
// 		c->pos_second_arg = c->pos_first_arg + 2;
// 	}
// }

// void check_second(t_check *c)
// {
// 	if (c->check_arg2 == 1)
// 	{
// 		ft_memcpy((void*)arg2, (const void*)map[pos_second_arg], 1);
// 		c->pos_third_arg = c->pos_second_arg + 1;
// 	}
// 	else if (c->check_arg2 == 2)
// 	{
// 		ft_memcpy((void*)args, (const void*)map[pos_second_arg], 2);
// 		c->pos_third_arg = c->pos_second_arg + 2;
// 	}
// }

// void pos_first_second(t_check *c, unsigned int current_pos)
// {
// 	unsigned char pos;

// 	pos = ((c->arg1 + c->arg2) % IDX_MOD) + current_pos;
// 	ft_memcpy((void*)c->reg, (const void*)map[pos], 4);
// }

unsigned int ldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
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
	ft_memcpy((void*)prec->reg[c->arg[2]], (const void*)&map[((c->arg[0] + c->arg[1]) % IDX_MOD) + prec->pos], 4);
}














