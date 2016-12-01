#include "minishell.h"

char	*get_env(char **env, char *rule)
{
	int		i;
	char	*ret;
	int		len;

	i = -1;
	ret = NULL;
	len = ft_strlen(rule) + 1;
	while (env[++i])
		if (ft_strstr(env[i], rule))
			ret = ft_strsub(env[i], len, ft_strlen(env[i]) - len);
	return (ret);
}