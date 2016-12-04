#include "minishell.h"

void	prompt_cmd(t_msh *msh)
{
	int 	i;

	while (42)
	{
		i = -1;
		ft_printf("\x1b[1;34m#\x1b[0m \x1b[36m%s\x1b[0m \n\x1b[1;31m$\x1b[0m ", USER);
		get_input(msh);
		if (split_fword(msh))
			start_process(msh);
		free(INPUT);
		free(COMMAND);
		while (++i < ft_tablen(ARGS))
			free(ARGS[i]);
		free(ARGS);
	}
}