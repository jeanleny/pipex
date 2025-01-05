/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:38:02 by lperis            #+#    #+#             */
/*   Updated: 2025/01/05 14:50:56 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	pipeprocess(t_data *data, int pipe_direction, char **argv)
{
	if (pipe_direction == 0)
	{
		dup2(data->in_fd, STDIN_FILENO);
		close(data->pfd[0]);
		if (data->in_fd > 0)
			dup2(data->pfd[1], STDOUT_FILENO);
		close(data->pfd[1]);
	}
	else if (pipe_direction == 1)
	{
		close(data->pfd[1]);
		dup2(data->pfd[0], STDIN_FILENO);
		if (access(argv[4], W_OK) < 0)
		{
			free(data->cmd);
			ft_free_tab(data->cmd_flag);
			ft_free_tab(data->path);
			ft_close(data);
			exit(data->status);
		}
		dup2(data->out_fd, STDOUT_FILENO);
		close(data->pfd[0]);
	}
}

void	execution(t_data *data, int exec, int cmd_nb)
{
	if (cmd_nb == 0)
	{
		if (exec == 1 && data->in_fd > 0)
			execve(data->cmd_flag[0], data->cmd_flag, data->envp);
	}
	else if (cmd_nb == 1)
	{
		if (exec == 1 && data->out_fd > 0)
			execve(data->cmd_flag[0], data->cmd_flag, data->envp);
	}
	return ;
}

void	child_process(t_data *data, char **argv, int pipe_direction, int i)
{
	int	exec;

	checkpath(data);
	exec = ft_access(data);
	if (data->cmd[i] == argv[2])
		pipe_direction = 0;
	else if (data->cmd[i] == argv[3])
		pipe_direction = 1;
	pipeprocess(data, pipe_direction, argv);
	free(data->cmd);
	if (data->unset_path != 1)
		ft_free_tab(data->path);
	execution(data, exec, pipe_direction);
	ft_free_tab(data->cmd_flag);
	ft_close(data);
	if (data->status == 0)
		data->status = 127;
	exit(data->status);
}

void	process(t_data *data, char **argv)
{
	int	i;
	int	pipe_direction;
	int	pid;
	int	get_pid[2];

	pipe_direction = 0;
	i = 0;
	if (pipe(data->pfd) < 0)
		return ;
	while (data->nb_args != 0)
	{
		data->cmd_flag = ft_split(data->cmd[i], ' ');
		pid = fork();
		if (pid == 0)
			child_process(data, argv, pipe_direction, i);
		else if (pid < 0)
			exit(-1);
		get_pid[i] = pid;
		i++;
		ft_free_tab(data->cmd_flag);
		data->nb_args--;
	}
	close(data->pfd[0]);
	close(data->pfd[1]);
	waitprocess(data, get_pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
	{
		ft_putstr_fd("Wrong arguments", 2);
		return (0);
	}
	set_data(&data, argc, argv, envp);
	check_file(&data, argv);
	process(&data, argv);
	if (data.unset_path != 1)
		ft_free_tab(data.path);
	free(data.cmd);
	ft_close(&data);
	exit(data.status);
}
