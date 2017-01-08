/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:36:02 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/08 08:36:11 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_input(t_msh *msh)
{
	int		ret;
	int		i;
	int		c;

	ret = 0;
	i = -1;
	INPUT = ft_strnew(2048);
	while (!ft_strchr(INPUT, '\n'))
	{
		ret = read(0, &INPUT[++i], 1);
		if (INPUT[i] == '\t')
		{
			INPUT[i] = '\0';
			--i;
		}
	}
	INPUT[i] = '\0';
}
