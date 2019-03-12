/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 09:58:12 by mvolkov           #+#    #+#             */
/*   Updated: 2018/07/22 20:50:47 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# define WIN_WIDTH 255
# define WIN_HEIGHT 68

# define PAUSE				"** PAUSED ** "
# define RUN				"** RUNNING **"
# define CYCLES_SECONDS		"Delay : "
# define CYCLE				"Cycle : "
# define PROCESSES			"Processes : "
# define CURRENT			"Live breakdown for current period : "
# define LAST				"Live breakdown for last period : "
# define TO_DIE				"CYCLE_TO_DIE : "
# define DELTA				"CYCLE_DELTA : "
# define LIVE				"NBR_LIVE : "
# define MAX_CHECKS_VIS		"MAX_CHECKS : "

# include <time.h>
# include <fcntl.h>
# include "corewar.h"

/*
**			drawAll.c
*/

void		draw_map(t_prog *p, unsigned char *mem);
void		change_color(t_prog *p);
void		draw_all(t_prog *p, int cycles, int counter, unsigned char *mem);
void		draw_champ(int i, short champ_num, t_prog *p, unsigned char *mem);

/*
**			init_window.c
*/

void		init_window(t_prog *p);
void		render_init_pair(void);

/*
**			draw_skelet.c
*/

void		draw_skelet(t_prog *p);
void		draw_info_tab(t_prog *p);
void		draw_bare(t_prog *p);
void		draw_bare_last(t_prog *p);

/*
**			draw_helper.c
*/

void		draw_end(t_prog *p, short winner);
void		set_live(t_prog *p, short champ_num, unsigned int pos);
void		new_colors(short champ_num, int start, t_prog *p);
void		render_keyboard(t_prog *p);
void		render_keyboard_end(t_prog *p);

/*
**			draw_colors.c
*/

void		fill_info_tab(t_prog *p, int cycles, int counter);
void		draw_players(t_prog *p);
void		refresh_map(t_prog *p);
void		color_on(t_prog *p, int i);
void		color_off(t_prog *p, int i);

#endif
