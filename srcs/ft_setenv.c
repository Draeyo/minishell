/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:32:51 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/20 10:35:43 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		change_user(t_msh *msh)
{
	char *user;

	user = get_env(ENV, "USER=");
	free(USER);
	USER = user;
}

static void		change_path(t_msh *msh)
{
	char	*path;

	path = get_env(ENV, "PATH=");
	ft_free_tab(PATHS);
	PATHS = ft_strsplit(path, ':');
	free(path);
}

static int		check_env(t_msh *msh)
{
	int		i;
	int		j;
	char	*env_var;

	i = -1;
	j = -1;
	while (ARGS[1][++j] && ARGS[1][j] != '=')
		;
	if (j == ft_strlen(ARGS[1]) && ARGS[1][j - 1] != '=')
		return (-2);
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

char		**exp_tab(char **tab, size_t len, char *new_entry)
{
	int		i;
	char	**ret;

	i = -1;
	ret = (char**)malloc(sizeof(char*) * (len + 1));
	ret[len] = NULL;
	while (tab[++i])
		ret[i] = ft_strdup(tab[i]);
	if (new_entry)
		ret[i] = ft_strdup(new_entry);
	ft_free_tab(tab);
	return (ret);
}

int				ft_setenv(t_msh *msh)
{
	char	**new_env;
	int		i;
	int		check;

	i = -1;
	if (!ARGS[1])
		return (-1);
	if ((check = check_env(msh)) == -2)
		return (0);
	if (ARGS[1] && check >= 0)
	{
		free(ENV[check]);
		ENV[check] = ft_strdup(ARGS[1]);
	}
	else if (ARGS[1] && check < 0)
	{
		new_env = exp_tab(ENV, ft_tablen(ENV) + 1, ARGS[1]);
		ENV = new_env;
	}
	if (ft_start_with(ARGS[1], "PATH="))
		change_path(msh);
	else if (ft_start_with(ARGS[1], "USER="))
		change_user(msh);
	return (1);
}
