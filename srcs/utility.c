/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:29:11 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/20 15:24:02 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_current_dir(t_msh *msh, char *pwd)
{
	int		i;
	char	*tmp;

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

void	print_env(t_msh *msh)
{
	int		i;

	i = -1;
	if (!ENV)
		ft_printf("\n");
	else
		while (ENV[++i])
			ft_printf("%s\n", ENV[i]);
}

int		cmd_exceptions(t_msh *msh)
{
	EX_FILE = 0;
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
	else if (exec_file(msh))
		return (1);
	else
		return (1);
	return (0);
}

int		split_fword(t_msh *msh)
{
	int		i;

	i = 0;
	while (INPUT[i] && (INPUT[i] == ' ' || INPUT[i] == '\t'))
		i++;
	while (INPUT[i] && INPUT[i] != ' ')
		i++;
	COMMAND = ft_strsub(INPUT, 0, i);
	ARGS = ft_strsplit(INPUT, ' ');
	if (!COMMAND[0] || COMMAND[0] == '\n' || COMMAND[0] == ' '
			|| COMMAND[0] == '\t')
		return (0);
	return (cmd_exceptions(msh));
}
