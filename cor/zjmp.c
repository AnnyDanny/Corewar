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

	c->codage = map[g->pos + 1];
	c->first_arg = map[g->pos + 2];
	check_codage(c);
	if (g->carry == 1)
	{
		if (c->arg1 == 2)
			ft_memcpy((void*)c->dir, (const void*)map[c->first_arg], 2);
		g->pos = c->dir % IDX_MOD;
	}
}
