#include <cor.h>


unsigned int		(*funcs[16])(*t_procs, *t_prog, *t_arg_type, *unsigned char)
{
	int p;

	p = 0;
	if (char[t_prog.pos + 1] == t_arg_type.T_IND)
	{
		p = char[t_prog.pos] + (t_arg_type.T_IND & IDX_MOD);
		char[p] = t_arg_type.T_IND;
	}
	else if (char[t_prog.pos + 1] == t_arg_type.T_REG)
		t_prog.reg[t_arg_type.T_REG] = t_arg_type.T_REG;
}

int main(void)
{
	
}