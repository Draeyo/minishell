/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:11:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/01 08:04:57 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		get_input(t_msh *msh)
{
	int 	ret;
	int 	i;
	char	c;

	ret = 0;
	i = -1;
	c = 0;
	INPUT = ft_strnew(2048);
	while (!ft_strchr(INPUT, '\n'))
		ret = read(0, &INPUT[++i], 1);
	INPUT[i] = '\0';
}

static void		split_fword(t_msh *msh)
{
	int 	i;

	i = 0;
	while (INPUT[i] && INPUT[i] != ' ')
		i++;
	COMMAND = ft_strsub(INPUT, 0, i);
	ARGS = ft_strsplit(INPUT, ' ');
}

static char		*join_path(char *s1, char *s2)
{
	char	*ret;
	int 	i;
	int 	j;

	ret = NULL;
	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[++i])
		ret[i] = s1[i];
	ret[i] = '/';
	while (s2[++j])
		ret[++i] = s2[j];
	return (ret);
}

int		main(int ac, char **av, char **env)
{
	t_msh	msh;
	int 	i;
	pid_t	process;
	int 	status;

	i = 0;
	status = 0;
	msh.env = ft_tabdup(env);
	msh.path = get_env(env, "PATH");
	msh.paths = ft_strsplit(msh.path, ':');
	while (42)
	{
		i = 0;
		ft_putstr("$>");
		get_input(&msh);
		split_fword(&msh);
		process = fork();
		if (process == 0)
			while (msh.paths[i] && execve(join_path(msh.paths[i], msh.command), msh.args, env) < 0)
				i++;
			if (i == ft_tablen(msh.paths))
				ft_putendl_fd("not found", 2);
		else
			waitpid(process, &status, 0);
		free(msh.input);
		free(msh.command);
		for (int j = 0; j < ft_tablen(msh.args); j++)
				free(msh.args[j]);
		free(msh.args);
	}
	free(msh.path);
	free(msh.env);
	return (0);
}
