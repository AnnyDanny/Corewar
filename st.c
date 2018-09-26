/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
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

unsigned int st(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	unsigned char ret;
	t_check *c;

	ret = get_args(proc, c, type, map);
	if (type[1] == 4)
		ft_memcpy((void*)&map[proc->pos + (c->ind % IDX_MOD)], (const void*)c->reg, 1);
	if (type[1] == 1)
		ft_memcpy((void*)&map[proc->reg[c->reg]], (const void*)c->reg, 1)
	return (ret);
}
