/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:11:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/01 08:04:57 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	t_msh	msh;
	int 	i;
	pid_t	process;
	int 	status;
	char 	*cmd;
	int 	ret;

	i = 0;
	status = 0;
	cmd = NULL;
	ret = -1;
	msh.env = ft_tabdup(env);
	msh.path = get_env(env, "PATH=");
	msh.paths = ft_strsplit(msh.path, ':');
	msh.user = get_env(env, "USER=");
	for (int j = 0; j < ft_tablen(msh.env); j++)
		ft_printf("%s\n", msh.env[j]);
	prompt_cmd(&msh);
/*	while (42)
	{
		i = 0;
		ft_printf("\x1b[32m%s\x1b[0m $ ", msh.user);
		get_input(&msh);
		split_fword(&msh);
		process = fork();
		if (process == 0)
		{
		//	while (msh.paths[i] && execve(join_path(msh.paths[i], msh.command), msh.args, env) < 0)
		//		i++;
			while (msh.paths[++i] && ret < 0)
			{
				cmd = join_path(msh.paths[i], msh.command);
				ret = execve(cmd, msh.args, msh.env);
				free(cmd);
			}
			if (i == ft_tablen(msh.paths))
				ft_putendl_fd("not found", 2);
		}
		else
			waitpid(process, &status, 0);
		free(msh.input);
		free(msh.command);
		for (int j = 0; j < ft_tablen(msh.args); j++)
				free(msh.args[j]);
		free(msh.args);
	}*/
	free(msh.path);
	free(msh.env);
	return (0);
}
