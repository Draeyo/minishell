/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:34:42 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/13 10:34:43 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		change_oldpwd(char **env)
{
	int 	i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	while (env[++i])
	{
		if (ft_start_with(env[i], "OLDPWD"))
		{
			tmp = getcwd(NULL, 0);
			free(env[i]);
			env[i] = ft_strjoin("OLDPWD=", tmp);
			free(tmp);
			return ;
		}
	}
}

void		no_env(t_msh *msh)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	ENV = (char**)malloc(sizeof(char*) * 3);
	ENV[0] = ft_strjoin("PWD=", tmp);
	ENV[1] = ft_strjoin("OLDPWD=", tmp);
	ENV[2] = NULL;
}
