/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:01:27 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/30 14:34:16 by vlistrat         ###   ########.fr       */
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

# define ENV msh->env
# define PATH msh->path
# define PATHS msh->paths
# define INPUT msh->input
# define ARGS msh->args
# define COMMAND msh->command

typedef struct		s_msh
{
	char		**env;
	char		*path;
	char		**paths;
	char		*input;
	char		**args;
	char		*command;
}					t_msh;

char				*get_env(char **env, char *rule);

# endif
