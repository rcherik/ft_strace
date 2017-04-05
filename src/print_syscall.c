#include "ft_strace.h"

void		print_ret(t_syscall *sc, struct user_regs_struct regs)
{
	int	type;

	type = sc->args[sc->n_args];
	if (type == INT)
		printf(" = %lld\n", regs.rax);
	else if (type == PTR)
		printf(" = 0x%llx\n", regs.rax);
	else if (type == VOID)
		printf(" = ?\n");
	else
		printf(" = 0\n");
}

char 	*print_string(pid_t child, unsigned long addr)
{
	char		*ret;
	int		allocated;
	int		read;
	unsigned long	tmp;

	ret = (char *)malloc(4096);
	allocated = 4096;
	read = 0;
	while (1)
	{
		if (read + sizeof(tmp) > allocated)
		{
			allocated *= 2;
			ret = realloc(ret, allocated);
		}
		tmp = ptrace(PTRACE_PEEKDATA, child, addr + read);
        	if (errno != 0)
		{
            		ret[read] = 0;
            		break ;
        	}
		ft_memcpy(ret + read, &tmp, sizeof(tmp));
        	if (ft_memchr(&tmp, 0, sizeof(tmp)) != NULL)
            		break ;
        	read += sizeof(tmp);
    	}
	return (ret);
}

static unsigned long long int	get_reg(int i, struct user_regs_struct regs)
{
	switch (i)
	{
		case 0 : return regs.rdi;
		case 1 : return regs.rsi;
		case 2 : return regs.rdx;
		case 3 : return regs.r10;
		case 4 : return regs.r8;
		default: return regs.r9;
	}
}

static int	print_string_star(pid_t child, unsigned long addr, struct user_regs_struct regs)
{
	int	i;
	int	len;
	char	*ret;
	char	**tmp;

	i = 0;
	tmp = (char **)addr;
	len = ft_tablen(tmp);
	if (ft_tablen(tmp) > MAX_VARS)
		return (printf("[*/ %d vars */]", len));
	return (printf("[\"%s\"]", print_string(child, get_reg(0, regs))));
}


static int	print_args(int n, int *args, struct user_regs_struct regs, pid_t child)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!n)
		printf(")");
	while (i < n)
	{
		if (args[i] == INT)
			len += printf("%llu", get_reg(i, regs));
		if (args[i] == STRING)
			len += printf("\"%s\"", print_string(child, get_reg(i, regs)));
		if (args[i] == PTR)
			len += !get_reg(i, regs) ? printf("NULL") : printf("0x%llx", get_reg(i, regs));
		if (args[i] == STRINGSTAR)
			len += print_string_star(child, get_reg(i, regs), regs);
		if (args[i] == STRUCT)
			len += printf("{STRUCT}");
		if (args[i] == VARGS)
			len += printf("{...}");
		if (i == n - 1)
			len += printf(")");
		else
			len += printf(", ");
		i++;
	}
	if (!len)
		return (1);
	return (len);
}

void	print_syscall(t_syscall *sc, struct user_regs_struct regs, pid_t child)
{
	int	shit;

	shit = printf("%s(", sc->name);
	shit += print_args(sc->n_args, sc->args, regs, child);
	while (shit < 42)
	{
		printf(" ");
		shit++;
	}
}
