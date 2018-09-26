/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:00:59 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/26 15:01:05 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <op.c>
#include <cor.h>

unsigned int and(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned int ret;

	ret = get_args(proc, c, type, map);
		proc->reg[c->arg[2]] = c->arg[0] & c->arg[1];
	check_carry(c->arg[2], proc);
	return (ret);
}

unsigned int or(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned int ret;

	ret = get_args(proc, c, type, map);
		proc->reg[c->arg[2]] = c->arg[0] | c->arg[1];
	check_carry(c->arg[2], proc);
	return (ret);
}

unsigned int xor(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;
	unsigned int ret;

	ret = get_args(proc, c, type, map);
	proc->reg[c->arg[2]] = c->arg[0] ^ c->arg[1];
	check_carry(c->arg[2], proc);	
	return (ret);
}
