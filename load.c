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

unsigned int				load(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned char pos;
	unsigned int ret;

	ret = get_args(proc, c, type, map);
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
	check_carry(c->arg[1]);
	return (ret);
}
