/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:33:03 by vlistrat          #+#    #+#             */
/*   Updated: 2017/01/09 11:39:41 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		check_pwd(t_msh *msh)
{
	char	*tmp;
	char	*tmp_pwd;
	char	*tmp_path;
	char	**tmp_env;

	tmp_path = NULL;
	tmp_env = NULL;
	tmp_pwd = NULL;
	if (!(tmp = get_env(ENV, "PWD=")))
	{
		tmp_pwd = getcwd(NULL, 0);
		tmp_path = ft_strjoin("PWD=", tmp_pwd);
		free(tmp_pwd);
		tmp_env = exp_tab(ENV, ft_tablen(ENV) + 1, tmp_path);
		free(tmp_path);
		ENV = tmp_env;
	}
	else
		free(tmp);
}

static void		clean_loop(t_msh *msh)
{
	int		i;

	i = -1;
	if (INPUT)
		strfree(&INPUT);
	if (COMMAND)
		strfree(&COMMAND);
	if (ARGS)
	{
		while (ARGS[++i])
			strfree(&ARGS[i]);
		free(ARGS);
		ARGS = NULL;
	}
}

void			prompt_cmd(t_msh *msh)
{
	int		i;
	char	*path;

	while (42)
	{
		i = -1;
		path = getcwd(NULL, 0);
		check_pwd(msh);
		ft_printf("\n\x1b[1;34m#\x1b[0m \x1b[36m%s\x1b[0m in ", USER);
		ft_printf("\x1b[1;33m%s\x1b[0m\n\x1b[1;31m%c\x1b[0m ", path, '$');
		free(path);
		get_input(msh);
		if (split_fword(msh))
			start_process(msh);
		if (NEW_PATH)
			strfree(&NEW_PATH);
		if (CMD_PATH)
			strfree(&CMD_PATH);
		clean_loop(msh);
	}
}
