/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:36:51 by vlistrat          #+#    #+#             */
/*   Updated: 2017/01/09 11:37:52 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		quote_check(char *str, int j)
{
	if (j && str[j - 1] != '\\' && (str[j] == '\"' || str[j] == '\''))
		return (0);
	else if (j && str[j - 1] == '\\' && (str[j] == '\"' || str[j] == '\''))
		return (1);
	else if (!j && (str[j] == '\"' || str[j] == '\''))
		return (0);
	else if (str[j + 1] && str[j] == '\\' && (str[j + 1] == '\"'
		|| str[j + 1] == '\''))
		return (0);
	else
		return (1);
}

void			ft_echo(t_msh *msh)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (ARGS[++i])
	{
		j = -1;
		if (i > 1)
			ft_printf(" ");
		while (ARGS[i][++j])
			if (quote_check(ARGS[i], j))
				write(1, &ARGS[i][j], 1);
	}
	ft_printf("\n");
}
