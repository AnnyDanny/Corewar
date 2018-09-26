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

unsigned int lldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int current_pos;;
	t_check *c;
	unsigned int temp;
	unsigned int ret;

	current_pos = proc->pos + 2;
	ret = get_args(proc, c, type, map);
	if (type[0] == 4)
	{
		ft_memcpy((void*)c->ind, (const void*)&map[(c->arg[0] % IDX_MOD) + proc->pos], 4);
		c->arg[0] = c->ind;
	}
	ft_memcpy((void*)prec->reg[c->arg[2]], (const void*)&map[c->arg[0] + c->arg[1] + proc->pos], 4);
	check_carry(c->arg[2]);
	return (ret);
}
