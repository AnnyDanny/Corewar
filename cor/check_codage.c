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

/*
1 = reg - 1 byte
2 = dir - 2 or 4 bytes
3 - ind - 2 bytes, read 4 bytes

что делать, если кодаж весит 0 байт?

если валидация кодажа универсальная и идет в отдельной функции, 
а в команды уже приходят валидные аргументы, согласно кодажу, то может быть такое:


Еще один нюанс: 
при чтении байтов нужно кастить их в 
зависимости от размера чтения:

1 байт - unsigned char
2 байта - short
4 байта - unsigned int

*/

void check_codage(t_check *c)
{
    if((c->codage & 192) == 64)
        c->check_arg1 = 1;
    else if((c->codage & 192) == 192)
        c->check_arg1 = 3;
    else if((c->codage & 192) == 128 )
        c->check_arg1 = 2;
    else
        c->check_arg1 = 0;
    if((c->codage & 48) == 32)
        c->check_arg2 = 2;
    else if((c->codage & 48) == 48 )
        c->check_arg2 = 3;
    else if((c->codage & 48) == 16)
        c->check_arg2 = 1;
    else
        c->check_arg2 = 0;
    if((c->codage & 12) == 8)
        c->check_arg3 = 2;
    else if((c->codage & 12) == 12)
        c->check_arg3 = 3;
    else if((c->codage & 12) == 4)
        c->check_arg3 = 1;
    else
        c->check_arg3 = 0;
}
