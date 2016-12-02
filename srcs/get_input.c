#include "minishell.h"

void	get_input(t_msh *msh)
{
	int 	ret;
	int 	i;
	int 	c;

	ret = 0;
	i = -1;
	INPUT = ft_strnew(2048);
	while (!ft_strchr(INPUT, '\n'))
		ret = read(0, &INPUT[++i], 1);
	INPUT[i] = '\0';
}