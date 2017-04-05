#ifndef FT_SRTRACE_H
# define FT_SRTRACE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ptrace.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/reg.h>
# include <sys/user.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>
# include "libft.h"

# define INT		0
# define STRING		1
# define PTR		2
# define STRUCT		3
# define STRINGSTAR	4
# define VOID		5
# define VARGS		6
# define MAX_VARS	5

typedef struct			s_syscall
{
	char			*name;
	int			n_args;
	int			*args;
}				t_syscall;

typedef struct			s_c
{
	char			*name;
	int			n;
	int			err;
	struct timeval		t;
}				t_c;

void		ft_strace(char *prog, char **env, char **argv, int opt);
void		ft_error(char *s);
void		print_syscall(t_syscall *sc, struct user_regs_struct regs, pid_t child);
t_syscall	**init_syscall(void);	
t_c		**init_stat(t_syscall **tab);
void		ret_stat(t_c **stat, unsigned long int num, struct user_regs_struct regs, struct timeval t);
void		print_stat(t_c **stat);
char		*try_path(char *cmd, char **env);
void 		tv_div(struct timeval *tv, const struct timeval *a, int n);
void		tv_add(struct timeval *tv, const struct timeval *a, const struct timeval *b);
double		tv_float(const struct timeval *tv);
void		tv_sub(struct timeval *tv, const struct timeval *a, const struct timeval *b);

#endif
