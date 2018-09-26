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
unsigned int				lld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned int pos;
	unsigned int ret;

	ret = get_args(prec, c, type, map);
	{
		if (type[0] == T_DIR_SIZE)
			prec->reg[c->arg[1]] = c->arg[0];
		if (type[0] == T_IND_SIZE)
		{
			pos = prec->pos + c->arg[0];
			ft_memcpy((void*)proc->reg[c->arg[1]], (const void*)&map[pos], 4);
		}
	}
	check_carry(c->arg[2]);
	return (ret);
}
