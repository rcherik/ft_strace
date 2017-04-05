#include "ft_strace.h"

static char	*get_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i]);
		i++;
	}
	return (NULL);
}

char		*try_path(char *cmd, char **env)
{
	char	**tab;
	char	*path;
	char	*tmp;
	int	i;

	i = 0;
	if ((path = get_path(env)) == NULL)
		ft_error("Error: can't get path.");
	tab = ft_strsplit(ft_strchr(path, '/'), ':');
	while (tab[i])
	{
		tmp = (char *)malloc(sizeof(ft_strlen(tab[i]) + ft_strlen(cmd)) + 2);
		ft_bzero(tmp, sizeof(tmp));
		ft_strcat(tmp, tab[i]);
		ft_strcat(tmp, "/");
		ft_strcat(tmp, cmd);
		if (!access(tmp, F_OK))
			return (tmp);
		ft_strdel(&tmp);
		i++;
	}
	return (NULL);
}
