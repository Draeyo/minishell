/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:37:43 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/20 15:23:29 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	if (tab)
		free(tab);
	tab = NULL;
}

void	free_msh(t_msh *msh)
{
	if (PATH)
		free(PATH);
	if (COMMAND)
		free(COMMAND);
	if (INPUT)
		free(INPUT);
	if (ENV)
		free_tab(ENV);
	if (PATHS)
		free_tab(PATHS);
	if (ARGS)
		free_tab(ARGS);
}
