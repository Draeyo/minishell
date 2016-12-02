#include "minishell.h"

void	split_fword(t_msh *msh)
{
	int 	i;

	i = 0;
	while (INPUT[i] && INPUT[i] != ' ')
		i++;
	COMMAND = ft_strsub(INPUT, 0, i);
	if (!ft_strcmp(COMMAND, "exit"))
		ft_exit(EXIT_CMD, msh);
	ARGS = ft_strsplit(INPUT, ' ');
}