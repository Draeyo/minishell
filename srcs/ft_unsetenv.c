#include "minishell.h"

int 	ft_unsetenv(t_msh *msh)
{
	int		i;
	int		j;
	int 	a;
	char	*env_var;

	i = -1;
	j = -1;
	a = 0;
	if (!ARGS[1])
		return (-1);
	while (ARGS[1][++j] != '=');
	env_var = ft_strsub(ARGS[1], 0, j);
	j = 0;
	while (ENV[++i])
	{
		++j;
		if ((ENV[j] && ft_strstr(ENV[i], env_var)) || a)
		{
			free(ENV[i]);
			ENV[i] = NULL;
			if (ENV[j])
				ENV[i] = ft_strdup(ENV[j]);
			a = 1;
		}
	}
	free(env_var);
	if (!a)
		return (0);
	return (1);
}