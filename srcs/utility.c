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
	check_oldpwd(msh);
	create_oldpwd(msh);
	change_pwd(msh);
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
