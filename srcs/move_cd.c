/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:37:26 by vlistrat          #+#    #+#             */
/*   Updated: 2017/01/04 09:43:59 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		cd_back(t_msh *msh, char *homedir)
{
	if (ARGS[1] && !ft_strcmp(ARGS[1], "-"))
	{
		homedir = get_env(ENV, "OLDPWD=");
		ft_printf("%s\n", homedir);
		if (chdir(homedir))
		{
			ft_error_msh(WRONG_PATH, homedir);
			free(homedir);
			return (0);
		}
		change_current_dir(msh, homedir);
		free(homedir);
		return (1);
	}
	return (0);
}

static int		cd_std(t_msh *msh, char *homedir)
{
	if (ARGS[1] && ft_strcmp(ARGS[1], "-"))
	{
		if (ARGS[1][0] == '~')
		{
			if (!(homedir = home_convpath(msh, ARGS[1])))
			{
				ft_error_msh(NO_HOME, NULL);
				return (0);
			}
		}
		else
			homedir = ft_strdup(ARGS[1]);
		if (chdir(homedir))
		{
			free(homedir);
			return (0);
		}
		change_current_dir(msh, ARGS[1]);
		free(homedir);
		return (1);
	}
	return (0);
}

static int		cd_home(t_msh *msh, char *homedir)
{
	if (!ARGS[1] || (ARGS[1] && !ft_strcmp(ARGS[1], "~")))
	{
		if (!(homedir = get_env(ENV, "HOME=")))
		{
			free(homedir);
			ft_error_msh(NO_HOME, NULL);
			return (0);
		}
		if (chdir(homedir))
			ft_error_msh(WRONG_PATH, homedir);
		change_current_dir(msh, homedir);
		free(homedir);
		return (1);
	}
	return (0);
}

void			move_cd(t_msh *msh)
{
	char	*homedir;
	char	*new_path;

	NEW_PATH = NULL;
	if (!cd_valid(msh, (ARGS[1] ? ARGS[1] : NULL)))
		return ;
	if (ft_tablen(ARGS) > 2)
	{
		ft_error_msh(TM_ARGS, (ARGS[1] ? ARGS[1] : NULL));
		return ;
	}
	if (cd_home(msh, homedir))
		return ;
	else if (cd_std(msh, homedir))
		return ;
	else if (cd_back(msh, homedir))
		return ;
}
