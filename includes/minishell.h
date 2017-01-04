/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:01:27 by vlistrat          #+#    #+#             */
/*   Updated: 2016/12/22 12:06:48 by vlistrat         ###   ########.fr       */
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
# define NO_HOME 3
# define TM_ARGS 4
# define P_DENIED 5

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
# define EX_FILE msh->ex_file
# define SHLVL msh->shlvl
# define NEW_PATH msh->new_path

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
	int			ex_file;
	int			shlvl;
	char		*new_path;
}					t_msh;

int					ft_error_msh(int e, char *str);
int					ft_exit(int e, t_msh *msh);
int					split_fword(t_msh *msh);
int					cmd_exeptions(t_msh *msh);
int					ft_setenv(t_msh *msh);
int					ft_unsetenv(t_msh *msh);
int					ft_start_with(char *str, char *comp);
int					cd_valid(t_msh *msh, char *arg);
int					exec_file(t_msh *msh);
int					str_env_str(char *str, char *comp);

char				*get_env(char **env, char *rule);
char				*join_path(char *s1, char *s2);
char				*home_convpath(t_msh *msh, char *current);
char				*shlvl_mod(t_msh *msh, int a);

void				get_input(t_msh *msh);
void				prompt_cmd(t_msh *msh);
void				start_process(t_msh *msh);
void				ft_free_tab(char **tab);
void				free_msh(t_msh *msh);
void				move_cd(t_msh *msh);
void				print_env(t_msh *msh);
void				ft_echo(t_msh *msh);
void				change_oldpwd(char **env);
void				no_env(t_msh *msh);
void				change_current_dir(t_msh *msh, char *pwd);
void				check_env_vars(t_msh *msh);
void				add_env_var(t_msh *msh, char *var);
void				strfree(char *str);

#endif
