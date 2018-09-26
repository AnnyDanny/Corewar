/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_carry.c                                      :+:      :+:    :+:   */
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

void check_carry(unsigned char arg)
{
	if (arg == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}

// void check_codage(t_check *c)
// {
//     if((c->codage & 192) == 64)
//         c->check_arg1 = 1;
//     else if((c->codage & 192) == 192)
//         c->check_arg1 = 3;
//     else if((c->codage & 192) == 128 )
//         c->check_arg1 = 2;
//     else
//         c->check_arg1 = 0;
//     if((c->codage & 48) == 32)
//         c->check_arg2 = 2;
//     else if((c->codage & 48) == 48 )
//         c->check_arg2 = 3;
//     else if((c->codage & 48) == 16)
//         c->check_arg2 = 1;
//     else
//         c->check_arg2 = 0;
//     if((c->codage & 12) == 8)
//         c->check_arg3 = 2;
//     else if((c->codage & 12) == 12)
//         c->check_arg3 = 3;
//     else if((c->codage & 12) == 4)
//         c->check_arg3 = 1;
//     else
//         c->check_arg3 = 0;
// }
