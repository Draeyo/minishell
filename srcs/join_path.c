/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:34:33 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/08 08:34:58 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_path(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = NULL;
	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[++i])
		ret[i] = s1[i];
	ret[i] = '/';
	while (s2[++j])
		ret[++i] = s2[j];
	return (ret);
}
