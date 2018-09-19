/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:12:41 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/25 14:12:42 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR.H
# define COR.H

typedef struct			s_proc {
	unsigned int		pid;
	unsigned int		pos;
	bool				carry;
	int					player_nbr;
	unsigned char		cmnd;
	bool				live;
	unsigned int		reg[16];
	unsigned int		cycles_to_do;
	struct s_proc		*next;
}						t_proc;

typedef struct			s_champ {
	char				name[PROG_NAME_LENGTH + 1];
	unsigned int		execsize;
	char				comm[COMMENT_LENGTH + 1];
	union chmp_exec		exec;
}						t_champ;

typedef struct			s_prog {
	unsigned int		verbose;
	unsigned int		nbr_cycles;
	int					player_nbr[MAX_PLAYERS];
	t_champ				champs[MAX_PLAYERS];
	unsigned int		(*funcs[16])(*t_procs, *t_prog, *t_arg_type, *unsigned char);
	int					lives[MAX_PLAYERS];
	int					players;
	int					checks_nbr;
	short				last_live_nbr;
}						t_prog;

#endif