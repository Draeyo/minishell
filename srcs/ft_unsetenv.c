/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:35:16 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/20 14:09:44 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		comp_env(char *str, char *env_var)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str || !env_var)
		return (0);
	while (str[i] && str[i] != '=')
		i++;
	tmp = ft_strsub(str, 0, i);
	if (!ft_strcmp(tmp, env_var))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

static void		red_unsetenv(t_msh *msh, char *env_var, int *a)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (ENV[++i])
	{
		++j;
		if ((ENV[j] && comp_env(ENV[i], env_var)) || *a)
		{
			free(ENV[i]);
			ENV[i] = NULL;
			if (ENV[j])
				ENV[i] = ft_strdup(ENV[j]);
			*a = 1;
		}
		else if (!ENV[j] && comp_env(ENV[i], env_var))
		{
			free(ENV[i]);
			ENV[i] = NULL;
		}
	}
}

int				ft_unsetenv(t_msh *msh)
{
	int		j;
	int		a;
	char	*env_var;

	j = 0;
	a = 0;
	if (!ARGS[1])
		return (-1);
	while (ARGS[1][j] && ARGS[1][j] != '=')
		j++;
	env_var = ft_strsub(ARGS[1], 0, j);
	red_unsetenv(msh, env_var, &a);
	free(env_var);
	if (!a)
		return (0);
	return (1);
}
