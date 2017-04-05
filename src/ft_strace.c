#include "ft_strace.h"
#include "sys.h"

static char	*get_signame(int sig)
{
	if (sig == SIGCHLD)
		return ("SIGCHLD");
	if (sig == SIGWINCH)
		return ("SIGWINCH");
	return (NULL);
}

static void	print_siginfo(pid_t child, int status)
{
	siginfo_t	sig_info;
	char		*sig_name;

	ptrace(PTRACE_GETSIGINFO, child, 0, &sig_info);
	if (sig_info.si_signo == SIGINT)
	{
		printf("Process %d detached\n", child);
		exit(0);
	}
	sig_name = get_signame(sig_info.si_signo);
	if (!sig_name)
		return ;
	printf("--- %s {si_signo=%s, si_code=%d, si_pid=%d, si_status=%d, si_utime=%d, si_stime=%d} ---\n",
	sig_name, sig_name, sig_info.si_code, sig_info.si_pid, sig_info.si_status,
	(int)sig_info.si_utime, (int)sig_info.si_stime);
}

static int	wait_syscall(pid_t child, int opt, t_c **stat)
{
	int 		status;
	siginfo_t	sig_info;

	while (42)
	{
		ptrace(PTRACE_SYSCALL, child, 0, 0);
		waitpid(child, &status, 0);
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
			return (0);
		else
		{
			if (!opt)
				print_siginfo(child, status);
		}
		if (WIFEXITED(status))
		{
			opt ? print_stat(stat) : printf(" = ?\n+++ exited with %d +++\n", WEXITSTATUS(status));
			return (1);
		}
	}
	return (0);
}

static void	block_sig(sigset_t *sig_block)
{
	sigemptyset(sig_block);
	sigaddset(sig_block, SIGHUP);
	sigaddset(sig_block, SIGINT);
	sigaddset(sig_block, SIGQUIT);
	sigaddset(sig_block, SIGPIPE);
	sigaddset(sig_block, SIGTERM);
	sigprocmask(SIG_BLOCK, sig_block, NULL);
}

static void	ft_father(pid_t child, int opt)
{
	struct user_regs_struct regs;
	sigset_t		set;
	sigset_t		sig_block;
	int			status;
	int			n_sys;
	t_syscall		**tab;
	t_c			**stat;
	struct timeval		t;

	n_sys = 0;
	tab = init_syscall();
	if (opt)
		stat  = init_stat(tab);
	sigemptyset(&set);
	ptrace(PTRACE_SEIZE, child, 0, 0);
	ptrace(PTRACE_INTERRUPT, child, 0, 0);
	sigprocmask(SIG_SETMASK, &set, NULL);
	waitpid(child, &status, 0);
	block_sig(&sig_block);
	ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
	while (42)
	{
		if (wait_syscall(child, opt, stat))
			break ;
		ptrace(PTRACE_GETREGS, child, NULL, &regs);
		if (!n_sys && regs.orig_rax == KILL)
			continue ;
		ft_bzero(&t, sizeof(struct timeval));
		gettimeofday(&t, NULL);
		opt ? stat[regs.orig_rax]->n += 1 : print_syscall(tab[regs.orig_rax], regs, child);
		if (opt && regs.orig_rax == EXIT_GROUP)
			stat[regs.orig_rax]->n -= 1;
		ptrace(PTRACE_SEIZE, child, 0, 0);
		if (wait_syscall(child, opt, stat))
			break ;
		ptrace(PTRACE_GETREGS, child, NULL, &regs);
		opt ? ret_stat(stat, regs.orig_rax, regs, t) : print_ret(tab[regs.orig_rax], regs);
		n_sys++;
	}
}

void		ft_strace(char *prog, char **env, char **argv, int opt)
{
	pid_t			child;
	char			*tmp;
	
	if (access(prog, F_OK))
		tmp = try_path(prog, env);
	else
		tmp = prog;
	if (!tmp)
	{
		printf("ft_strace: Can't start '%s': No such file or directory\n", prog);
		exit(1);
	}
	child = fork();
	if (!child)
	{
		kill(getpid(), SIGSTOP);
		opt ? execv(tmp, argv + 2) : execv(tmp, argv + 1);
	}
	else
		ft_father(child, opt);
}
