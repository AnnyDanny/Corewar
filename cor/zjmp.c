/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
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
перемещает PC с текущей позиции на T_DIR % IDX_MOD если carry равен 1
*/


unsigned int				zjmp(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned int pos;

	pos = map[proc->pos + 2];
	if (proc->carry == 1)
	{
		ft_memcpy((void*)c->dir, (const void*)&map[pos], 2);
		proc->pos = c->dir % IDX_MOD;
	}
}
