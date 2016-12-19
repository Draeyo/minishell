#include "minishell.h"

int		cd_valid(t_msh *msh)
{
	struct stat	stat;

	if (!ARGS[1] || !ft_strcmp(ARGS[1], "-") || !ft_strcmp())
	if (!lstat(ARGS[1], &stat))
		return (1);
	return (0);
}