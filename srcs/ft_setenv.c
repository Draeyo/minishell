/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:32:51 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/08 08:32:54 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		check_env(t_msh *msh)
{
	int		i;
	int		j;
	char	*env_var;

	i = -1;
	j = -1;
	while (ARGS[1][++j] != '=')
		;
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

static char		**exp_tab(char **tab, size_t len, char *new_entry)
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
	check = check_env(msh);
	if (ARGS[1] && check >= 0)
	{
		ft_free_tab(ENV);
		free(new_env[check]);
		new_env[check] = ft_strdup(ARGS[1]);
		return (1);
	}
	else if (ARGS[1] && check < 0)
		new_env = exp_tab(ENV, ft_tablen(ENV) + 1, ARGS[1]);
	ENV = new_env;
	return (1);
}
