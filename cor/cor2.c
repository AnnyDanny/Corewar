/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 05:24:24 by gdanylov          #+#    #+#             */
/*   Updated: 2018/09/14 05:24:25 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <op.c>
// ее нужно вызывать , когда истечек нужное количество циклов
// и нужно будет выполнять действие
// выполняется, когда не осталось живых процессов
// cycle_to_die <= 0

// должна проверять аргументы и обьявляьять живым процесс и чемпиона, если его имя в аргументе
// аргумнет T_DIR - это 4 байта
// у каждого чемпиона есть число-имя. Если в аргумента число какого-то из чемпионов, значит этот чемпион
// обьявляется живым, кто будет последний - тот выиграл
// процесс жив, пока его не убьет ВМ
// ВМ убивает те процессы, которые ни разу не выполнили инструкцию лив за количество циклов в cycle_to_die
// тот процесс, который приходит в лив - жив. нужно отметить это, чтобы ВМ его не убила. 
// вопросы:
// -где находятся процессы, которые должны прийти в аргументах лива, чтобы проверить, что они выполняют данную инструкцию?
// -инструкция лив должна вызываться каждый cycle_to_die

typedef struct			s_args 
{
	unsigned int check_arg1;
	unsigned int check_arg2;
	unsigned int check_arg3;
}						t_args;

void codage_identify(t_args *args, unsigned char args)
{
    if((args & 192) == 64)
        args->arg1 = 1;
    else if((args & 192) == 192)
        args->arg1 = 3;
    else if((args & 192) == 128 )
        args->arg1 = 2;
    else
        args->arg1 = 0;
    if((args & 48 ) == 32)
        args->arg2 = 2;
    else if((args & 48 ) == 48 )
        args->arg2 = 3;
    else if((args & 48 ) == 16)
        args->arg2 = 1;
    else
        args->arg2 = 0;
    if((args & 12) == 8 )
        args->arg3 = 2;
    else if((args & 12) == 12)
        args->arg3 = 3;
    else if((args & 12) == 4)
        args->arg3 = 1;
    else
        args->arg3 = 0;
}

// int check_codage(t_args *args, unsigned int args)
// {
// 	if (args->arg1 != 0)
// 	{

// 	}
// 	else if (args->arg1 != 0)
// 	{
		
// 	}
// 	else if (args->arg1 != 0)
// 	{
		
// 	}
// 	else
// 		return (0);
// }

unsigned int				live(*t_procs, *t_prog, *t_arg_type, *unsigned char)
{
	if (p->lives[MAX_PLAYERS] > 21)
		CYCLE_TO_DIE = CYCLE_DELTA;


}


// T_REG - занимает только 1 байт
// T_IND - 2 байта
// T_DIR - столько байтов сколько указано в label_size у команды

// 1 байт - unsigned char
// 2 байта - short
// 4 байта - unsigned int
// codage - это первое число, размером в один байт - оно определяет тип следующего аргумента
// считать байт и проверить его
// считать аргумент и проверить его и сделать с ним что-то
// кодадж на карте - это положение процесса + 1 (для первого аргумента)
// в кодадже храниться значение, которое определяет сколько байтов весит следующий аргумент
// в кодадже может хваниться только 3 значение(вес аргумента), в соответствии с количеством трех аргументов
// #define IDX_MOD					(MEM_SIZE / 8)

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	size_t				i;
// 	unsigned char		*fdst;
// 	unsigned char		*fsrc;

// 	i = 0;
// 	fdst = (unsigned char *)dst;
// 	fsrc = (unsigned char *)src;
// 	while (i < n)
// 	{
// 		fdst[i] = fsrc[i];
// 		i++;
// 	}
// 	return (fdst);
// }

void check_t_reg(*t_prog, *t_arg_type)
{
	if (t_arg_type.T_REG == 0)
		t_prog.carry = 1;
	else
		t_prog.carry = 0;
}

unsigned int				load(*t_procs, *t_prog, *t_arg_type, *unsigned char)
{
	// валидация t_reg - проверить, чтобы он был в диапазоне значений от 1 до 16
	int i;
	int c[4];

	i = 0;
	if (char[t_prog.pos + 1] == t_arg_type.T_DIR)
		t_prog.reg[t_arg_type.T_REG];
	else if (char[t_prog.pos + 1] == t_arg_type.T_IND)
	{
		t_arg_type.T_IND = t_arg_type.T_IND % IDX_MOD;
		i = t_arg_type.T_IND;
		t_arg_type.T_IND = char[t_prog.pos + 1] + i;
		ft_memcpy((void*)c, t_arg_type.T_IND, 4);
		t_prog.reg[t_arg_type.T_REG] = c;
	}
	check_t_reg(t_prog.carry, t_arg_type.T_REG);

	// char[t_prog.pos + 1];
	// if (char[t_prog.pos + 1] == (short)t_arg_type.T_DIR)
	// 	(unsigned char)t_arg_type.T_REG = (short)t_arg_type.T_DIR;
	// else if (char[t_prog.pos + 1] == (short)t_arg_type.T_IND)
	// {
	// 	t_arg_type.T_IND = t_arg_type.T_IND % IDX_MOD;
	// 	i = t_arg_type.T_IND;
	// 	t_arg_type.T_IND = char[t_prog.pos + 1] + i;
	// 	t_arg_type.T_REG = 
	// }
}




// ПК («Счетчик программ»). Это специальный реестр, который содержит 
// только в памяти виртуальной машины адрес следующего набора инструкций 
// для кодирования и выполнения. Очень полезно выяснить, где мы находимся 
// в процессе выполнения, давая советы о том, когда писать материал в памяти
// есть список всех процессов, который нужно обработать, этот каунтер помогает делать это по очереди


// Флаг с именем «carry», если последняя операция прошла успешно. Только некоторые операции могут изменить carry.






unsigned int		(*funcs[16])(*t_procs, *t_prog, *t_arg_type, *unsigned char)
{
	int p;

	p = 0;
	check_codage(char[t_prog.pos + 1]);
	if (char[t_prog.pos + 1] == t_arg_type.T_IND)
	{
		p = char[t_prog.pos] + (t_arg_type.T_IND & IDX_MOD);
		char[p] = t_arg_type.T_IND;
	}
	else if (char[t_prog.pos + 1] == t_arg_type.T_REG)
		t_prog.reg[t_arg_type.T_REG] = t_arg_type.T_REG;
}
















































