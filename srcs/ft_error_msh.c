#include "minishell.h"

int 	ft_error_msh(int e, char *str)
{
	if (e == NOT_FOUND)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd((str ? str : ""), 2);
	}
	else if (e == WRONG_PATH)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(str, 2);
	}
	return (0);
}