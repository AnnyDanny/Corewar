/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
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
T_DIR | T_IND    T_REG

Если первый аргумент T_DIR, то идет просто запись первого аргумента в T_REG
Если первый аргумент T_IND, то сначала T_IND перезаписывается на (T_IND % IDX_MOD)
а потом идем на ячейку от текущей позиции + это значение
с той позиции считываем 4 байта и записываем в T_REG
В зависимости от того, что записали в T_REG меняем carry
Если записали 0, меняем carry на 1, если не ноль - меняем на 0. 
*/

unsigned int				load(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned char pos;

	if (get_args(proc, c, type, map) == 1)
	{
		if (type->args[0] == 2)
			proc->reg[c->reg] = c->dir;
		else if (type->args[1] == 4)
		{
			c->ind = c->ind % IDX_MOD;
			pos = proc->pos + c->ind;
			ft_memcpy((void*)proc->reg[c->reg], (const void*)&map[pos], 4);
		}
	}
	check_carry(c);
}

// void from_map_load(t_check *c)
// {
// 	c->first_arg = map[g->pos + 2];
// 	if (c->arg1 == 2)
// 	{
// 		ft_memcpy((void*)c->dir, (const void*)map[c->first_arg], 4);
// 		c->second_arg = map[c->first_arg + 4];
// 	}
// 	else if (c->arg1 == 3)
// 	{
// 		ft_memcpy((void*)c->ind, (const void*)map[c->first_arg], 3);
// 		c->second_arg = map[c->first_arg + 3];
// 	else if (c->arg2 == 1)
// 		ft_memcpy((void*)c->reg, (const void*)map[c->second_arg], 1);
// }

// int check_valid_reg(t_check *c)
// {
// 	if (c->reg >= 1 && c->reg <= 16)
// 		return (1);
// 	return (0);
// }

// unsigned int				load(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
// {
// 	int tmp;
// 	unsigned char pos_ind;

// 	tmp = 0;
// 	c->codage = map[g->pos + 1];
// 	if (c->arg1 == 2)
// 		g->reg[reg] = c->dir;
// 	else if (c->arg1 == 3)
// 	{
// 		tmp = c->ind % IDX_MOD;
// 		pos_ind = map[c->first_arg + tmp];
// 		ft_memcpy((void*)c->reg, (const void*)map[pos_ind], 4);
// 	}
// 	check_valid_reg(c);
// 	check_carry(c);
// }
