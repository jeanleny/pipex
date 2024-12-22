/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:27:06 by lperis            #+#    #+#             */
/*   Updated: 2024/12/22 17:14:12 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_data
{
	char	**path;
	char	**envp;
	char	**cmd;
	char	**cmd_flag;
	char	**args;
	char	*infile;
	char	*outfile;
	int		in_fd;
	int		out_fd;
	int		nb_args;
	int		in_bool;
	int		out_bool;
	int		f_path;
	int		out_index;
	int		pfd[2];
	int		multipipe;
	int		multipipe_bool;
	int		unset_path;
}	t_data;

void	check_file(t_data *data, char **argv);
void	checkpath(t_data *data);
int		ft_access(t_data *data);
void	pipeprocess(t_data *data, int pipe_direction);
void	child_process(t_data *data, char **argv, int pipe_direction, int i);
void	process(t_data *data, char **argv);
void	set_data(t_data *data, int argc, char **argv, char **envp);
void	set_path(t_data *data);

#endif
