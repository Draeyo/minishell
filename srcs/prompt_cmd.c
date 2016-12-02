#include "minishell.h"

void	prompt_cmd(t_msh *msh)
{
	int 	i;

	while (42)
	{
		i = -1;
		ft_printf("\x1b[32m%s\x1b[0m $ ", USER);
		get_input(msh);
		split_fword(msh);
		start_process(msh);
		free(INPUT);
		free(COMMAND);
		while (++i < ft_tablen(ARGS))
			free(ARGS[i]);
		free(ARGS);
	}
}