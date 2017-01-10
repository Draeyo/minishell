/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:31:11 by vlistrat          #+#    #+#             */
/*   Updated: 2017/01/09 11:40:23 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_bin(t_msh *msh)
{
	struct stat		stat;
	char			*tmp;
	int				i;
	int				ret;

	i = -1;
	tmp = NULL;
	ret = -1;
	while (PATHS[++i] && ret < 0)
	{
		tmp = join_path(PATHS[i], COMMAND);
		if ((ret = lstat(tmp, &stat)) == 0)
			CMD_PATH = ft_strdup(tmp);
		free(tmp);
	}
	if (ret == 0)
		return (1);
	return (0);
}

void		start_process(t_msh *msh)
{
	pid_t	process;
	int		ret;

	if (!check_bin(msh) && !EX_FILE)
	{
		ft_error_msh(NOT_FOUND, COMMAND);
		return ;
	}
	process = fork();
	ret = -1;
	if (process == 0)
	{
		if (EX_FILE)
			ret = execve(COMMAND, ARGS, ENV);
		else
		{
			ret = execve(CMD_PATH, ARGS, ENV);
			free(CMD_PATH);
			CMD_PATH = NULL;
		}
		if (ret < 0)
			ft_error_msh(NOT_FOUND, COMMAND);
	}
	else
		waitpid(process, &PIDSTAT, 0);
}
