#include "ft_strace.h"

void		ft_error(char *s)
{
	ft_putendl(s);
	exit(-1);
}

static void	ft_usage(void)
{
	ft_putendl("Usage: ./ft_strace [-c] [PROG] [ARGS]");
	exit(-1);
}

static int	get_opt(int argc, char **argv)
{
	if (argv[2] && !ft_strcmp(argv[1], "-c") && argc > 2)
		return (1);
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	int		opt;

	if (argc < 2)
		ft_usage();
	opt = get_opt(argc, argv);
	opt ? ft_strace(argv[2], env, argv, opt): ft_strace(argv[1], env, argv, opt);
	return (0);
}
