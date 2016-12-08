/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:37:09 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/08 08:37:11 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_exit(int e, t_msh *msh)
{
	if (e == EXIT_CMD)
	{
		free_msh(msh);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
