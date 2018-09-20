/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_codage.c                                     :+:      :+:    :+:   */
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


void check_carry(t_check *c)
{
	if (c->reg == 0)
		g->carry = 1;
	else
		g->carry = 0;
}

void check_codage(t_check *c)
{
    if((c->codage & 192) == 64)
        c->arg1 = 1;
    else if((c->codage & 192) == 192)
        c->arg1 = 3;
    else if((c->codage & 192) == 128 )
        c->arg1 = 2;
    else
        c->arg1 = 0;
    if((c->codage & 48) == 32)
        c->arg2 = 2;
    else if((c->codage & 48) == 48 )
        c->arg2 = 3;
    else if((c->codage & 48) == 16)
        c->arg2 = 1;
    else
        c->arg2 = 0;
    if((c->codage & 12) == 8)
        c->arg3 = 2;
    else if((c->codage & 12) == 12)
        c->arg3 = 3;
    else if((c->codage & 12) == 4)
        c->arg3 = 1;
    else
        c->arg3 = 0;
}
