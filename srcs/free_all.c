#include "minishell.h"

void	free_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_msh(t_msh *msh)
{
//	if (PATHS)
//		free_tab(PATHS);
//	if (PATH)
//		free(PATH);
//	if (ENV)
//		free_tab(ENV);
//	if (COMMAND)
//		free(COMMAND);
//	if (INPUT)
//		free(INPUT);
//	if (ARGS)
//		free_tab(ARGS);
}