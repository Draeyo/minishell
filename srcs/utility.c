/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:29:11 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/08 08:30:40 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		change_current_dir(t_msh *msh, char *pwd)
{
	int		i;
	char 	*tmp;

	i = -1;
	tmp = NULL;
	while (ENV[++i])
	{
		if (ft_start_with(ENV[i], "OLDPWD"))
		{
			tmp = get_env(ENV, "PWD=");
			free(ENV[i]);
			ENV[i] = ft_strjoin("OLDPWD=", tmp);
			free(tmp);
		}
	}
	i = -1;
	while (ENV[++i])
		if (ft_start_with(ENV[i], "PWD") && !ft_start_with(ENV[i], "OLDPWD"))
		{
			free(ENV[i]);
			CWD = getcwd(NULL, 0);
			ENV[i] = ft_strjoin("PWD=", CWD);
			free(CWD);
			return ;
		}
}

void			move_cd(t_msh *msh)
{
	char	*homedir;

	if (!ARGS[1] || (ARGS[1] && !ft_strcmp(ARGS[1], "~")))
	{
		if (!(homedir = get_env(ENV, "HOME=")))
		{
			free(homedir);
			ft_error_msh(NO_HOME, NULL);
			return ;
		}
		if (chdir(homedir))
			ft_error_msh(WRONG_PATH, homedir);
		change_current_dir(msh, homedir);
		free(homedir);
	}
	if (ARGS[1] && ft_strcmp(ARGS[1], "-"))
	{
		if (chdir(ARGS[1]))
		{
			ft_error_msh(WRONG_PATH, ARGS[1]);
			return ;
		}
		change_current_dir(msh, ARGS[1]);
	}
	if (ARGS[1] && !ft_strcmp(ARGS[1], "-"))
	{
		homedir = get_env(ENV, "OLDPWD=");
		ft_printf("%s\n", homedir);
		if (chdir(homedir))
		{
			ft_error_msh(WRONG_PATH, homedir);
			free(homedir);
			return ;
		}
		change_current_dir(msh, homedir);
		free(homedir);
	}
}

void			print_env(t_msh *msh)
{
	int		i;

	i = -1;
	if (!ENV)
		ft_printf("\n");
	else
		while (ENV[++i])
			ft_printf("%s\n", ENV[i]);
}

int				cmd_exceptions(t_msh *msh)
{
	if (!ft_strcmp(COMMAND, "exit"))
		ft_exit(EXIT_CMD, msh);
	else if (!ft_strcmp(COMMAND, "env"))
		print_env(msh);
	else if (!ft_strcmp(COMMAND, "cd"))
		move_cd(msh);
	else if (!ft_strcmp(COMMAND, "setenv"))
		ft_setenv(msh);
	else if (!ft_strcmp(COMMAND, "unsetenv"))
		ft_unsetenv(msh);
	else if (!ft_strcmp(COMMAND, "echo"))
		ft_echo(msh);
	else
		return (1);
	return (0);
}

int				split_fword(t_msh *msh)
{
	int		i;

	i = 0;
	while (INPUT[i] && INPUT[i] != ' ')
		i++;
	COMMAND = ft_strsub(INPUT, 0, i);
	ARGS = ft_strsplit(INPUT, ' ');
	return (cmd_exceptions(msh));
}
