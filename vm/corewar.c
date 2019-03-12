/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:08:07 by vmorguno          #+#    #+#             */
/*   Updated: 2018/11/14 20:03:54 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visual.h"

static inline void	ft_introduce(t_prog *p, unsigned char *mem)
{
	int				i;

	i = 0;
	if (!(p->vis))
		ft_printf("Introducing contestants...\n");
	while (i < p->players)
	{
		ft_loadchamp(mem, p, i);
		if (!(p->vis))
			ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",
					i + 1, p->champs[i].execsize,
					p->champs[i].name, p->champs[i].comm);
		i++;
	}
}

static inline void	prepare_prog(t_prog *p, unsigned char *mem, short *res)
{
	p->players = *res;
	ft_introduce(p, mem);
	if (p->vis)
	{
		init_window(p);
		draw_all(p, 0, 0, mem);
	}
	p->prcs = ft_init_proc(p, *res);
	p->lastpid = *res;
}

int					main(int argc, char **argv)
{
	t_prog			*p;
	short			res;
	unsigned char	*mem;
	int				winner;

	mem = ft_memcreator();
	p = ft_init_prog();
	if ((res = ft_read_args(argc, argv, p)) > 0)
	{
		prepare_prog(p, mem, &res);
		winner = ft_vmachine(p, mem);
		if (p->nbr_cycles == MAX_INT || p->nbr_cycles > p->counter)
		{
			if (p->vis)
				draw_end(p, winner);
			ft_printf("Contestant %d, \"%s\", has won !\n",
						winner + 1, p->champs[winner].name);
		}
	}
	else
		ft_print_error(res, &p, &mem);
	return (0);
}

void				ft_print_error(short code, t_prog **p, unsigned char **mem)
{
	static char		errors[6][25] = {"this is not a file", "display help",
									"no magic header", "wrong file structure",
									"wrong champ exec size",
									"too many players"};

	free(*mem);
	free(*p);
	if (!code || code == -2)
		usage();
	else if (code != -1)
		ft_printf("Error : %s\n", errors[(code * -1) - 1]);
}

t_prog				*ft_init_prog(void)
{
	t_prog			*p;
	int				i;

	i = 0;
	p = ft_memalloc(sizeof(t_prog));
	p->nbr_cycles = MAX_INT;
	p->pause_s = 1;
	if (!p->vis)
	{
		p->pause_s = 0;
		p->pause = 1;
	}
	while (i < MAX_PLAYERS)
	{
		p->player_nbr[i] = ((i + 1) * -1);
		i++;
	}
	return (p);
}
