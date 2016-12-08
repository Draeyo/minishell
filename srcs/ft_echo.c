/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:36:51 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/08 08:36:56 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_msh *msh)
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
			if (ARGS[i][j] != '\"' && ARGS[i][j] != '\'')
				write(1, &ARGS[i][j], 1);
	}
	ft_printf("\n");
}
