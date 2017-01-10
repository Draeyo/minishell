/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:36:14 by vlistrat          #+#    #+#             */
/*   Updated: 2017/01/09 11:37:33 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_oldpwd(t_msh *msh)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	while (ENV[++i])
	{
		if (ft_start_with(ENV[i], "OLDPWD="))
		{
			if (!(tmp = get_env(ENV, "PWD=")))
				return ;
			free(ENV[i]);
			ENV[i] = ft_strjoin("OLDPWD=", tmp);
			free(tmp);
		}
	}
}

void	change_pwd(t_msh *msh)
{
	int		i;

	i = -1;
	while (ENV[++i])
	{
		if (ft_start_with(ENV[i], "PWD=") && !ft_start_with(ENV[i], "OLDPWD="))
		{
			free(ENV[i]);
			CWD = getcwd(NULL, 0);
			ENV[i] = ft_strjoin("PWD=", CWD);
			free(CWD);
			CWD = NULL;
			return ;
		}
	}
}

void	create_oldpwd(t_msh *msh)
{
	int		i;
	char	**new_env;
	char	*tmp;

	i = 0;
	new_env = NULL;
	tmp = NULL;
	while (ENV[i] && !ft_start_with(ENV[i], "OLDPWD="))
		++i;
	if (i == ft_tablen(ENV))
	{
		tmp = get_env(ENV, "PWD=");
		CWD = ft_strjoin("OLDPWD=", tmp);
		free(tmp);
		new_env = exp_tab(ENV, (i + 1), CWD);
		ENV = new_env;
		free(CWD);
		CWD = NULL;
	}
}
