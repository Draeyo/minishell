#include "minishell.h"

static void		change_current_dir(t_msh *msh, char *pwd)
{
	int 	i;

	i = -1;

	while (ENV[++i])
		if (ft_strstr(ENV[i], "PWD"))
		{
			free(ENV[i]);
			CWD = getcwd(NULL, 0);
			ENV[i] = ft_strjoin("PWD=", CWD);
			free(CWD);
		}
}

void			move_cd(t_msh *msh)
{
	char 	*homedir;

	if ((ARGS[1] && ft_strcmp(ARGS[1], "-")) || !ARGS[1])
	{
		if (OLD_CWD)
			free(OLD_CWD);
		OLD_CWD = getcwd(NULL, 0);
	}
	if (!ARGS[1] || (ARGS[1] && !ft_strcmp(ARGS[1], "--")))
	{
		homedir = get_env(ENV, "HOME=");
		if (chdir(homedir))
			ft_error_msh(WRONG_PATH, homedir);
		change_current_dir(msh, homedir);
		free(homedir);
	}
	if (ARGS[1] && ft_strcmp(ARGS[1], "-") && chdir(ARGS[1]))
	{
		ft_error_msh(WRONG_PATH, ARGS[1]);
		return ;
	}
	else
		change_current_dir(msh, ARGS[1]);
	if (ARGS[1] && !ft_strcmp(ARGS[1], "-") && chdir(OLD_CWD))
	{
		ft_error_msh(WRONG_PATH, ARGS[1]);
		return ;
	}
	else
		change_current_dir(msh, OLD_CWD);
}

void			print_env(t_msh *msh)
{
	int 	i;

	i = -1;
	while (ENV[++i])
		ft_printf("%s\n", ENV[i]);
}

int 			cmd_exceptions(t_msh *msh)
{
	if (!ft_strcmp(COMMAND, "exit"))
		ft_exit(EXIT_CMD, msh);
	else if (!ft_strcmp(COMMAND, "env"))
		print_env(msh);
	else if (!ft_strcmp(COMMAND, "cd"))
		move_cd(msh);
	else
		return (1);
	return (0);
}

int				split_fword(t_msh *msh)
{
	int 	i;

	i = 0;
	while (INPUT[i] && INPUT[i] != ' ')
		i++;
	COMMAND = ft_strsub(INPUT, 0, i);
	ARGS = ft_strsplit(INPUT, ' ');
	return (cmd_exceptions(msh));
}