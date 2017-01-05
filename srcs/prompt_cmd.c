/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:33:03 by vlistrat          #+#    #+#             */
/*   Updated: 2017/01/05 09:21:43 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		clean_loop(t_msh *msh)
{
	int		i;

	i = 0;
	if (INPUT)
		strfree(INPUT);
	if (COMMAND)
		strfree(COMMAND);
	if (ARGS)
	{
		while (i++ < ft_tablen(ARGS))
			strfree(ARGS[i]);
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
		path = get_env(ENV, "PWD=");
		ft_printf("\n\x1b[1;34m#\x1b[0m \x1b[36m%s\x1b[0m in ", USER);
		ft_printf("\x1b[1;33m%s\x1b[0m\n\x1b[1;31m%c\x1b[0m ", path, '$');
		free(path);
		get_input(msh);
		if (split_fword(msh))
			start_process(msh);
		if (NEW_PATH)
		{
			free(NEW_PATH);
			NEW_PATH = NULL;
		}
		clean_loop(msh);
	}
}
