/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:01:27 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/08 08:28:23 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

/*
** DEBUG
*/
# define DEBUG(x) ft_printf("DEBUG %d\n", x)

/*
** ERRORS
*/
# define NOT_FOUND 1
# define WRONG_PATH 2

/*
** EXIT
*/
# define EXIT_CMD 1

/*
** STRUCT
*/
# define ENV msh->env
# define PATH msh->path
# define PATHS msh->paths
# define INPUT msh->input
# define ARGS msh->args
# define COMMAND msh->command
# define PIDSTAT msh->pidstat
# define USER msh->user
# define CWD msh->cwd
# define OLD_CWD msh->old_cwd
# define TMP_CWD msh->tmp_cwd

typedef struct		s_msh
{
	char		**env;
	char		*path;
	char		**paths;
	char		*input;
	char		**args;
	char		*command;
	char		*user;
	int			pidstat;
	char		*cwd;
	char		*old_cwd;
	char		*tmp_cwd;
}					t_msh;

int					ft_error_msh(int e, char *str);
int					ft_exit(int e, t_msh *msh);
int					split_fword(t_msh *msh);
int					cmd_exeptions(t_msh *msh);
int					ft_setenv(t_msh *msh);
int					ft_unsetenv(t_msh *msh);

char				*get_env(char **env, char *rule);
char				*join_path(char *s1, char *s2);

void				get_input(t_msh *msh);
void				prompt_cmd(t_msh *msh);
void				start_process(t_msh *msh);
void				ft_free_tab(char **tab);
void				free_msh(t_msh *msh);
void				move_cd(t_msh *msh);
void				print_env(t_msh *msh);
void				ft_echo(t_msh *msh);

#endif
