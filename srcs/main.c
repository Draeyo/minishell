/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:11:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/08 08:34:22 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	t_msh	msh;
	int		i;
	pid_t	process;
	int		status;
	char	*cmd;

	i = 0;
	status = 0;
	cmd = NULL;
	if (!ft_tablen(env))
		no_env(&msh);
	else
		msh.env = ft_tabdup(env);
	change_oldpwd(msh.env);
	if (!(msh.path = get_env(env, "PATH=")))
		msh.path = ft_strdup("/bin:/sbin:/usr/bin:/usr/sbin");
	msh.paths = ft_strsplit(msh.path, ':');
	if (!(msh.user = get_env(env, "USER=")))
		msh.user = ft_strdup("minishell");
	prompt_cmd(&msh);
	free(msh.path);
	free(msh.env);
	return (0);
}
