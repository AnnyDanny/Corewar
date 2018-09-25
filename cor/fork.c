/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
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
T_DIR

2

Значение (T_DIR % IDX_MOD) плюс текущая позиция PC является позицией, 
на которой создается копия текущего процесса со всеми его параметрами (кроме самой позиции)
*/

unsigned int				fork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned int pos;

	ft_memcpy((void*)c->arg[0], (const void*)&map[proc->pos + 2], 4 - (2 * proc->cmnd));
	pos = (c->arg[0] % IDX_MOD) + proc->pos;
	// копию текущего процесса записывать в новый элемент листа?
}