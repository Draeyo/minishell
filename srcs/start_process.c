/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:31:11 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/08 08:31:12 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_process(t_msh *msh)
{
	pid_t	process;
	int		i;
	char	*cmd;
	int		tablen;
	int		ret;

	process = fork();
	i = -1;
	cmd = NULL;
	ret = -1;
	tablen = ft_tablen(PATHS);
	if (process == 0)
	{
		while (PATHS[++i] && ret < 0)
		{
			cmd = join_path(PATHS[i], COMMAND);
			ret = execve(cmd, ARGS, ENV);
			free(cmd);
		}
		if (i >= tablen && COMMAND)
			ft_error_msh(NOT_FOUND, COMMAND);
	}
	else
		waitpid(process, &PIDSTAT, 0);
}
