/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:36:29 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/08 08:36:35 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char **env, char *rule)
{
	int		i;
	char	*ret;
	int		len;

	i = -1;
	ret = NULL;
	len = ft_strlen(rule);
	while (env[++i])
		if (ft_strstr(env[i], rule))
			ret = ft_strsub(env[i], len, ft_strlen(env[i]) - len);
	return (ret);
}
