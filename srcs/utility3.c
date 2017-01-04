/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:34:19 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/20 15:28:02 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd_valid(t_msh *msh, char *arg)
{
	struct stat	stat;
	char		*tmp;

	tmp = NULL;
	if (!arg || !ft_strcmp(arg, "-") || !ft_strcmp(arg, "~"))
		return (1);
	if (arg && arg[0] == '~' && arg[1])
		NEW_PATH = home_convpath(msh, arg);
	else if (arg && ((arg[0] && arg[0] != '/') || (arg[0] && arg[1]
		&& arg[0] != '.' && arg[1] != '/')))
	{
		tmp = getcwd(NULL, 0);
		NEW_PATH = join_path(tmp, arg);
		free(tmp);
	}
	if (lstat((!NEW_PATH ? arg : NEW_PATH), &stat) < 0)
	{
		ft_error_msh(WRONG_PATH, ARGS[1]);
		return (0);
	}
	if (access((!NEW_PATH ? arg : NEW_PATH), X_OK) < 0)
	{
		ft_error_msh(P_DENIED, ARGS[1]);
		return (0);
	}
	return (1);
}

int		str_end_str(char *str, char *comp)
{
	int		i;
	int		j;

	i = ft_strlen(str) - ft_strlen(comp) - 1;
	j = -1;
	while (str[++i])
		if (str[i] != comp[++j])
			return (0);
	return (1);
}

char	*shlvl_mod(t_msh *msh, int a)
{
	char	*shlvl;
	int		lvl;

	shlvl = get_env(ENV, "SHLVL=");
	if (a >= 0)
		lvl = ft_s_atoi(shlvl) + 1;
	else
		lvl = ft_s_atoi(shlvl) - 1;
	free(shlvl);
	shlvl = ft_xtoa(lvl);
	SHLVL = lvl;
	return (shlvl);
}

int		exec_file(t_msh *msh)
{
	struct stat		stat;

	if (COMMAND[0] != '/' && COMMAND[0] != '.')
		return (0);
	if (lstat(COMMAND, &stat) < 0)
		return (0);
	if (!access(COMMAND, X_OK))
	{
		EX_FILE = 1;
		return (1);
	}
	return (0);
}

void	strfree(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}
