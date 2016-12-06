#include "minishell.h"

static int 	check_env(t_msh *msh)
{
	int 	i;
	int		j;
	char	*env_var;

	i = -1;
	j = -1;
	while (ARGS[1][++j] != '=');
	env_var = ft_strsub(ARGS[1], 0, j);
	while (ENV[++i])
		if (ft_strstr(ENV[i], env_var))
		{
			free(env_var);
			return (i);
		}
	free(env_var);
	return (-1);
}

int		ft_setenv(t_msh *msh)
{
	char	**new_env;
	int		i;
	int		check;

	i = -1;
	if (!ARGS[1])
		return (-1);
	check = check_env(msh);
	new_env = (char**)malloc(sizeof(*new_env) * (ft_tablen(ENV) + 1));
	while (ENV[++i])
		new_env[i] = ft_strdup(ENV[i]);
	DEBUG(1);
	ft_free_tab(ENV);
	DEBUG(2);
	if (ARGS[1] && check >= 0)
	{
		free(new_env[check]);
		new_env[check] = ft_strdup(ARGS[1]);
	}
	else if (ARGS[1] && check < 0)
	{
		new_env[i] = ft_strdup(ARGS[1]);
		i++;
	}
	new_env[i] = NULL;
	ENV = new_env;
	//ENV = ft_tabdup(new_env);
	//free_tab(new_env);
	return (1);
}