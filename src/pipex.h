/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:27:06 by lperis            #+#    #+#             */
/*   Updated: 2025/01/05 15:59:27 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_data
{
	char	**path;
	char	**envp;
	char	**cmd;
	char	**cmd_flag;
	int		in_fd;
	int		out_fd;
	int		nb_args;
	int		f_path;
	int		pfd[2];
	int		unset_path;
	int		status;
}	t_data;

void	check_file(t_data *data, char **argv);
void	checkpath(t_data *data);
int		ft_access(t_data *data);
void	pipeprocess(t_data *data, int pipe_direction, char **argv);
void	child_process(t_data *data, char **argv, int pipe_direction, int i);
void	process(t_data *data, char **argv);
void	set_data(t_data *data, int argc, char **argv, char **envp);
void	set_path(t_data *data);
void	ft_close(t_data *data);
void	ft_free_tab(char **tab);
int		get_path(t_data *data);
void	waitprocess(t_data *data, int *pid);
void	execution(t_data *data, int exec, int cmd_nb);

#endif
