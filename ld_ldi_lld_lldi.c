/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_ldi_lld_lldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:05:03 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/26 15:05:04 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <op.c>
#include <cor.h>

unsigned int				ld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
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
	check_carry(c->arg[1], proc);
	return (ret);
}

unsigned int ldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
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
	ft_memcpy((void*)prec->reg[c->arg[2]], (const void*)&map[((c->arg[0] + c->arg[1]) % IDX_MOD) + prec->pos], 4);
	return (ret);
}

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
	check_carry(c->arg[2], proc);
	return (ret);
}

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
	check_carry(c->arg[2], proc);
	return (ret);
}
