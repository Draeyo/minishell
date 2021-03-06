/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:37:22 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/08 08:37:34 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_error_msh(int e, char *str)
{
	if (e == NOT_FOUND)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd((str ? str : ""), 2);
	}
	else if (e == WRONG_PATH)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(str ? str : "", 2);
	}
	else if (e == NO_HOME)
		ft_putendl_fd("minishell: cd: HOME not set", 2);
	else if (e == TM_ARGS)
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(str ? str : "", 2);
	}
	else if (e == P_DENIED)
	{
		ft_putstr_fd("cd: permission denied: ", 2);
		ft_putendl_fd(str ? str : "", 2);
	}
	return (0);
}
