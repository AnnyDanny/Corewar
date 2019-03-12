/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:49:05 by vmorguno          #+#    #+#             */
/*   Updated: 2018/11/13 22:42:42 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				read1(int *fd, char **argv, int *i, short *res)
{
	(*fd) = open(argv[(*i)], O_RDONLY);
	if ((*fd) <= 0)
	{
		perror(argv[(*i)]);
		exit(-1);
	}
	(*res) = ft_binvalidator(*fd);
}

short				read2(t_prog *p, int *j, short *res)
{
	if (p->vis)
	{
		p->verbose = 0;
		p->nbr_cycles = MAX_INT;
	}
	if ((*j) > MAX_PLAYERS)
		return (-6);
	(*res) = (*res) == 0 ? (short)(*j) : (*res);
	return (*res);
}

short				ft_read_args(int argc, char **argv, t_prog *p)
{
	int				i;
	int				j;
	short			res;
	int				fd;

	i = 1;
	j = 0;
	fd = 0;
	res = 0;
	while (i < argc && res == 0)
	{
		if (argv[i][0] == '-' && (i + 1) < argc)
			res = ft_readflag(j, argv, &i, p);
		else
		{
			read1(&fd, argv, &i, &res);
			if (res == 0 && j < MAX_PLAYERS)
				ft_binreader(fd, &p->champs[j]);
			close(fd);
			j++;
		}
		i++;
	}
	res = read2(p, &j, &res);
	return (res);
}

int					add_to_read(char **argv, int *i, t_prog *p)
{
	if (argv[*i][1] == 'V')
	{
		p->vis = 1;
		return (0);
	}
	return (1);
}

short				ft_readflag(int j, char **argv, int *i, t_prog *p)
{
	unsigned int	val;

	val = 0;
	if (ft_isnum(argv[*i + 1]))
	{
		val = (unsigned int)ft_atoi(argv[*i + 1]);
		if (argv[*i][1] == 'v' && argv[*i][2] == '\0')
			p->verbose = val;
		else if (argv[*i][1] == 'n' && j < MAX_PLAYERS && argv[*i][2] == '\0')
			p->player_nbr[j] = ft_atoi(argv[*i + 1]);
		else if (!ft_strcmp(argv[*i], "-dump"))
			p->nbr_cycles = val;
		else
			return (ft_isfile(argv[*i]));
		*i = *i + 1;
		return (0);
	}
	else if (add_to_read(argv, i, p) == 0)
		return (0);
	else if (argv[*i][1] == 'v' || argv[*i][1] == 'n'
			|| !ft_strcmp(argv[*i], "-dump") || argv[*i][1] == 'V')
		return (-2);
	return (ft_isfile(argv[*i]));
}
