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

#ifndef COR_H
# define COR_H

#include <op.h>
#include <op.c>

#define T_REG_SIZE					1
#define T_DIR_SIZE					2
#define T_IND_SIZE					4
#define T_LAB_SIZE					8

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

typedef struct			s_check 
{
	short 				dir;
	unsigned char 		reg;
	int 				ind;
	unsigned char 		*arg;
	unsigned int 		arg1;
	unsigned int 		arg2;
	unsigned int 		arg3;
	unsigned char		pos;
	int 				count_steps;
}						t_check;


void 					check_carry(t_check *c);
unsigned int 			get_args(t_proc *proc, t_check *c, t_arg_type *type, unsigned char *map);
unsigned int 			add(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			sub(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			and(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			or(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			xor(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			ld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			ldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			lld(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			lldi(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			live(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			zjmp(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			fork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int			lfork(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			aff(t_proc *proc, t_check *c, t_arg_type *type, unsigned char *map);
unsigned int 			st(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);
unsigned int 			sti(t_proc *proc, t_prog *g, t_arg_type *type, unsigned char *map);

#endif