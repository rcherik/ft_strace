#include "ft_strace.h"

t_c		**init_stat(t_syscall **tab)
{
	int		i;
	t_c		**stat;
	t_c		*sc;

	i = 0;
	stat = (t_c **)malloc(sizeof(t_c *) * 315);
	ft_bzero(stat, sizeof(t_c *) * 315);
	while (i < 314)
	{
		sc = (t_c *)malloc(sizeof(t_c));
		sc->name = tab[i]->name;
		stat[i] = sc;
		i++;
	}
	stat[i] = NULL;
	return (stat);
}

void		ret_stat(t_c **stat, unsigned long int num, struct user_regs_struct regs, struct timeval t)
{
	struct timeval		tmp;

	stat[num]->err = (long long int)regs.rax < 0 ? stat[num]->err += 1 : stat[num]->err;
	ft_bzero(&tmp, sizeof(struct timeval));
	gettimeofday(&tmp, NULL);
	tv_sub(&tmp, &tmp, &t);
	tv_add(&stat[num]->t, &stat[num]->t, &tmp);
}

static void	sort(t_c **tab)
{
	int	o;
	int	i;
	t_c	*tmp;

	o = 0;
	while (!o)
	{
		o = 1;
		i = 0;
		while (tab[i + 1])
		{
			if (timercmp(&tab[i]->t, &tab[i + 1]->t, <))
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				o = 0;
			}
			i++;
		}
	}
}

void		print_stat(t_c **stat)
{
	int			i;
	struct timeval		total_time;
	struct timeval		dtv;
	int			total_call;
	int			total_err;
	const char		*dashes = "----------------";
	char			error_str[sizeof(int)*3];
	double			float_syscall_time;
	double			percent;
	double			float_total;

	i = 0;
	ft_bzero(&total_time, sizeof(struct timeval));
	total_call = 0;
	total_err = 0;
	while (stat[i])
	{
		total_call += stat[i]->n;
		total_err += stat[i]->err;
		tv_add(&total_time, &total_time, &stat[i]->t);
		i++;
	}
	if (total_time.tv_sec || total_time.tv_usec)
		sort(stat);
	printf("%6.6s %11.11s %11.11s %9.9s %9.9s %s\n",
		"% time", "seconds", "usecs/call", "calls", "errors", "syscall");
	printf("%6.6s %11.11s %11.11s %9.9s %9.9s %s\n",
		dashes, dashes, dashes, dashes, dashes, dashes);
	i = 0;
	float_total = tv_float(&total_time);
	while (stat[i])
	{
		if (stat[i]->n)
		{
			float_syscall_time = tv_float(&stat[i]->t);
			percent = (100.0 * float_syscall_time);
			if (percent != 0.0)
				   percent /= float_total;
			tv_div(&dtv, &stat[i]->t, stat[i]->n);
			printf("%6.2f", percent);
			printf("%12.6f", float_syscall_time);
			printf("%12lu", (long)(1000000 * dtv.tv_sec + dtv.tv_usec));
			printf("%9u", stat[i]->n);
			error_str[0] = '\0';
			if (stat[i]->err)
				sprintf(error_str, "%u", stat[i]->err);
			printf("%11.9s ", error_str);
			printf("%s\n", stat[i]->name);
		}
		i++;
	}
	printf("%6.6s %11.11s %11.11s %9.9s %9.9s %s\n",
		dashes, dashes, dashes, dashes, dashes, dashes);
	printf("%6.6s%12.6f %10.11s %9u %10.9s %s\n", "100.00", float_total, "",
		total_call, ft_itoa(total_err) , "total");
}
