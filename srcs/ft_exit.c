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