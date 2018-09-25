/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_sec_third.c                            :+:      :+:    :+:   */
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

// c->pos_first_arg = proc->reg[map[pos + 2]];???
	// ft_memcpy((void*)c->arg1, (const void*)proc->reg[c->pos_first_arg], 1);???


// unsigned int add(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
// {
// 	t_check *c;

// 	c->codage = map[g->pos + 1];
// 	check_codage(c);
// 	check_first_arg(c);
// 	check_second_arg(c);
// 	check_third_arg(c);
// 	g->reg[] = c->arg1 + c->arg2;
// 	check_carry(c);
// }

// int get_reg(t_proc *proc, t_check *c, t_arg_type *type, unsigned char *map)
// {
// 	ft_memcpy((void*)c->reg, (const void*)&map[c->pos], 1);
// 	return ((c->reg >= 0 && c->reg <= 16) ? 1 : 0);
// 		c->pos = c->pos + 1;
// }

unsigned int get_args(t_proc *proc, t_check *c, t_arg_type *type, unsigned char *map)
{	
	int i;
	int j;

	i = 0;
	j = 0;
	c->pos = map[proc->pos + 2];
	while (i <= 2)
	{
		if (type[i] == 1)
		{
			ft_memcpy((void*)c->arg[j], (const void*)&map[c->pos], 1);
			return ((c->arg[j] >= 0 && c->arg[j] <= 16) ? 1 : 0);
			c->pos = c->pos + 1;
		}
		if (type[i] == 2)
		{
			ft_memcpy((void*)c->arg[j], (const void*)&map[c->pos], 4 - (2 * proc->cmnd));
			c->pos = c->pos + 4;

		}
		if (type[i] == 4)
		{
			ft_memcpy((void*)c->arg[j], (const void*)&map[c->pos], 2);
			c->pos = c->pos + 2;
		}
		j++;
		i++;
	}
	return (1);
}

// int check_first_arg_4(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
// {
// 	t_check *c;

// 	c->pos_first_arg = map[proc->pos + 2];
// 	if (type->args[0] == 1)
// 	{
// 		ft_memcpy((void*)c->reg, (const void*)&map[c->pos_first_arg], 1);
// 		if (c->reg >= 0 && c->reg <= 16)
// 			c->arg1 = c->reg;
// 		else
// 			return (0);
// 		c->pos_second_arg = map[c->pos_first_arg + 1];
// 	}
// 	if (type->args[0] == 2)
// 	{
// 		ft_memcpy((void*)c->arg1, (const void*)&map[c->pos_first_arg], 4);
// 		c->pos_second_arg = map[c->pos_first_arg + 4];
// 	}
// 	if (type[0] == 4)
// 	{
// 		ft_memcpy((void*)c->arg1, (const void*)&map[c->pos_first_arg], 2);
// 		c->pos_second_arg = map[c->pos_first_arg + 2];
// 	}
// 	return (1);
// }

// int check_second_arg_4(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
// {
// 	t_check *c;

// 	if (type->args[1] == 1)
// 	{
// 		ft_memcpy((void*)c->reg, (const void*)&map[c->pos_second_arg], 1);
// 		if (c->reg >= 0 && c->reg <= 16)
// 			c->arg2 = c->reg;
// 		else
// 			return (0);
// 		c->pos_third_arg = map[c->pos_second_arg + 1];
// 	}
// 	if (type->args[1] == 2)
// 	{
// 		ft_memcpy((void*)c->arg2, (const void*)&map[c->pos_second_arg], 4);
// 		c->pos_third_arg = map[c->pos_second_arg + 4];
// 	}
// 	if (type->args[1] == 4)
// 	{
// 		ft_memcpy((void*)c->arg2, (const void*)&map[c->pos_second_arg], 2);
// 		c->pos_third_arg = map[c->pos_second_arg + 2];
// 	}
// 	return (1);
// }

// int check_third_arg_4(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
// {
// 	t_check *c;

// 	if (type->args[2] == 1)
// 	{
// 		ft_memcpy((void*)c->reg, (const void*)map[c->pos_third_arg], 1);
// 		if (c->reg >= 0 && c->reg <= 16)
// 			c->arg3 = c->reg;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }
