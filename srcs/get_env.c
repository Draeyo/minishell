/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:36:29 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/20 10:36:41 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_start_with(char *str, char *comp)
{
	int		i;

	i = -1;
	if (ft_strlen(str) < ft_strlen(comp))
		return (0);
	while (comp[++i])
	{
		if (comp[i] != str[i])
			return (0);
	}
	return (1);
}

char	*get_env(char **env, char *rule)
{
	int		i;
	char	*ret;
	int		len;

	i = -1;
	ret = NULL;
	len = ft_strlen(rule);
	while (env[++i])
		if (ft_start_with(env[i], rule))
			ret = ft_strsub(env[i], len, ft_strlen(env[i]) - len);
	return (ret);
}
