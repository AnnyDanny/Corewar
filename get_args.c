/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
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

void check_carry(unsigned char arg, t_proc *proc)
{
	if (arg == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}

int check_reg(unsigned char arg, unsigned int *ret, t_arg_type *type)
{
	if (c->arg >= 0 && c->arg <= 16)
		return (1);
	else
	{
		*ret = type[0] + type[1] + type[2] + 2;
		return (0);
	}
	return (0);
}


void get(t_proc *proc, unsigned char *arg, unsigned char i, unsigned char *map)
{
	ft_memcpy((void*)arg, (const void*)&map[c->pos + i], i);
}

unsigned int get_args(t_proc *proc, t_check *c, t_arg_type *type, unsigned char *map)
{	
	int i;
	unsigned int ret;

	i = -1;
	ret = 0;
	c->pos = proc->pos + 2;
	while (i++ <= 2)
	{
		if (type[i] == T_REG_SIZE)
		{
			get(proc, &c->arg[i], 1, map);
			if (check_reg(c->arg[i], &ret, type) == 1)
			{
				c->pos += 1;
				ret += 1;
			}
			else
				return (ret);
		}
		if (type[i] == T_DIR_SIZE)
		{
			get(proc, c->arg[i], 4 - (2 * proc->cmnd), map);
			c->pos += 4 - (2 * proc->cmnd);
			ret += 4 - (2 * proc->cmnd);

		}
		if (type[i] == T_IND_SIZE)
		{
			get(proc, c->arg[i], 2, map);
			c->pos += 2;
			ret += 2;
		}
	}
	return (ret);
}
