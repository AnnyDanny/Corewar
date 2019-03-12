/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:15:13 by gdanylov          #+#    #+#             */
/*   Updated: 2018/11/13 22:56:25 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	usage(void)
{
	printf("Usage: ./corewar [-d N -s N -v N | -b --stealth |\
	-n --stealth] [-a] <champion1.cor> <...>\n");
	printf("-a        : Prints output from 'aff' (Default is to hide it)\n");
	printf("#### TEXT OUTPUT MODE ######################################\n");
	printf("    -dump N     : Dumps memory after N cycles then exits\n");
	printf("    -s N	: Runs N cycles, dumps memory, pauses, then repeats\n");
	printf("    -v N	: Verbosity levels,\
	can be added together to enable several\n");
	printf("		- 0	: Show only essentials\n");
	printf("		- 1	: Show lives\n");
	printf("		- 2	: Show cycles\n");
	printf("		- 4	: Show operations (Params are NOT litteral ...)\n");
	printf("		- 8	: Show deaths\n");
	printf("		- 16	: Show PC movements (Except for jumps)\n");
	printf("#### NCURSES OUTPUT MODE ####################################\n");
	printf("    -V	        : Ncurses output mode\n");
	printf("#############################################################\n");
}
