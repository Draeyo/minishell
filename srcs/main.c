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
	msh.old_cwd = NULL;
	msh.tmp_cwd = NULL;
	prompt_cmd(&msh);
	free(msh.path);
	free(msh.env);
	return (0);
}
