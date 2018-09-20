/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
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
выполняет 2 операции:
1. засчитывает, что процесс (который выполняет данную команду) жив.
2. засчитывает, что жив номер (если этот номер совпадает с номером игрока, то засчитывает, что этот игрок жив)
который заходит, как аргумент (T_DIR)
*/

void from_map_add(t_check *c)
{
	c->first_arg = map[g->pos + 2];

	if (c->arg1 = 2)
		ft_memcpy((void*)c->dir, (const void*)map[c->first_arg], 4);
}

unsigned int				live(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map)
{
	t_check *c;

	g->live = 1;
	codage = map[g->pos + 1];
	check_codage(c);
	from_map_add(c);

	

}