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

unsigned int sti(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned int pos;
	unsigned int ret;

	ret = get_args(prec, c, type, map);
	if (c->type[1] == 4)
		ft_memcpy((void*)c->arg[1], (const void*)&map[c->arg[1] % IDX_MOD], 4);
	ft_memcpy((void*)&map[proc->pos + (c->arg[1] + c->arg[2]) % IDX_MOD], (const void*)c->arg[0], 1);
	return (ret);	
}
