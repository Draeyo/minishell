/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:34:42 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/20 10:40:12 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_oldpwd(char **env)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	while (env[++i])
	{
		if (ft_start_with(env[i], "OLDPWD"))
		{
			tmp = getcwd(NULL, 0);
			free(env[i]);
			env[i] = ft_strjoin("OLDPWD=", tmp);
			free(tmp);
			return ;
		}
	}
}

void	no_env(t_msh *msh)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	ENV = (char**)malloc(sizeof(char*) * 3);
	ENV[0] = ft_strjoin("PWD=", tmp);
	ENV[1] = ft_strjoin("OLDPWD=", tmp);
	ENV[2] = NULL;
	free(tmp);
}

char	*home_convpath(t_msh *msh, char *current)
{
	char	*ret;
	char	*home;
	char	*path;

	if (!(home = get_env(ENV, "HOME=")))
		return (NULL);
	ret = ft_strjoin(home, &current[1]);
	free(home);
	return (ret);
}

void	add_env_var(t_msh *msh, char *var)
{
	int		len;
	int		i;
	char	**ret;

	len = ft_tablen(ENV) + 1;
	i = -1;
	ret = (char**)malloc(sizeof(char*) * (len + 1));
	ret[len] = NULL;
	while (ENV[++i])
		ret[i] = ft_strdup(ENV[i]);
	if (var)
		ret[i] = ft_strdup(var);
	ft_free_tab(ENV);
	ENV = ret;
}

void	check_env_vars(t_msh *msh)
{
	char	*pwd;
	char	*old_pwd;

	if (!(pwd = get_env(ENV, "PWD=")))
	{
		pwd = getcwd(NULL, 0);
		add_env_var(msh, ft_strjoin("PWD=", pwd));
	}
	if (!(old_pwd = get_env(ENV, "OLDPWD=")))
	{
		old_pwd = getcwd(NULL, 0);
		add_env_var(msh, ft_strjoin("OLDPWD=", old_pwd));
	}
	free(pwd);
	free(old_pwd);
}
