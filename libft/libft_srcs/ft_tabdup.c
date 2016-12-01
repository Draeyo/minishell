/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 07:57:05 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/01 08:04:11 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_tabdup(char **tab)
{
	char	**ret;
	int		i;
	int		len;

	i = -1;
	len = ft_tablen(tab);
	ret = (char**)malloc(sizeof(*ret) * len);
	ret[len] = NULL;
	while (++i < len)
		ret[i] = ft_strdup(tab[i]);
	return (ret);
}
