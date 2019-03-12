/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfuncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:38:17 by vmorguno          #+#    #+#             */
/*   Updated: 2018/11/13 22:50:50 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visual.h"

unsigned char		*ft_memcreator(void)
{
	unsigned char	*mem;

	mem = ft_memalloc(MEM_SIZE);
	return (mem);
}

void				ft_loadchamp(unsigned char *mem, t_prog *p, short champ_num)
{
	unsigned int	i;
	unsigned int	j;

	j = champ_num * MEM_SIZE / p->players;
	i = 0;
	while (i < p->champs[champ_num].execsize)
	{
		mem[j] = p->champs[champ_num].exec.obts[i++];
		if (p->vis)
			draw_champ(j, champ_num, p, mem);
		j++;
	}
}

void				ft_memdumper(unsigned char *mem)
{
	unsigned int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if ((i % 64) == 0)
		{
			if (i != 0)
				ft_printf("\n%#.4x : ", i);
			else
				ft_printf("0x0000 : ");
		}
		ft_printf("%.2x ", (unsigned int)mem[i]);
		i++;
	}
	ft_printf("\n");
}
