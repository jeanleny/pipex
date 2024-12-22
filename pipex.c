/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:38:02 by lperis            #+#    #+#             */
/*   Updated: 2024/12/22 17:15:23 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(t_data *data)
{
	close(data->pfd[0]);
	close(data->pfd[1]);
	if (data->in_bool == 1)
		close(data->in_fd);
	if (data->out_bool == 1)
		close(data->out_fd);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	check_file(t_data *data, char **argv)
{
	data->in_bool = 0;
	data->out_bool = 1;
	if (access(argv[1], R_OK | F_OK) == 0)
	{
		data->in_fd = open(argv[1], O_RDONLY);
		data->in_bool = 1;
		dup2(data->in_fd, STDIN_FILENO);
	}
	data->out_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->out_fd < 0)
		data->out_bool = 0;
}

void	checkpath(t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	data->f_path = 0;
	if (data->cmd_flag[i] == NULL)
		return ;
	while (data->cmd_flag[i][j])
	{
		if (data->cmd_flag[i][j] == '/')
			data->f_path = 1;
		j++;
	}
	if (data->f_path == 0)
	{
		tmp = ft_strdup(data->cmd_flag[i]);
		free(data->cmd_flag[i]);
		data->cmd_flag[i] = ft_strjoin("/", tmp);
		free(tmp);
	}
}

int	get_path(t_data *data)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (data->path[i])
	{
		tmp = ft_strjoin(data->path[i], data->cmd_flag[0]);
		if (access(tmp, X_OK) == 0)
		{
			free(data->cmd_flag[0]);
			data->cmd_flag[0] = tmp;
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}

int	ft_access(t_data *data)
{
	int		accs;

	accs = 0;
	if ((data->cmd_flag[0] == NULL) || \
		(data->unset_path == 1 && data->f_path == 0))
		return (0);
	if (data->f_path == 0)
		accs = get_path(data);
	else
	{
		if (access(data->cmd_flag[0], X_OK) == 0)
			accs = 1;
	}
	return (accs);
}

void	pipeprocess(t_data *data, int pipe_direction)
{
	if (pipe_direction == 0)
	{
		close(data->pfd[0]);
		dup2(data->pfd[1], STDOUT_FILENO);
		close(data->pfd[1]);
	}
	else if (pipe_direction == 1)
	{
		close(data->pfd[1]);
		dup2(data->pfd[0], STDIN_FILENO);
		dup2(data->out_fd, STDOUT_FILENO);
		close(data->pfd[0]);
	}
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
	pipeprocess(data, pipe_direction);
	free(data->cmd);
	if (data->unset_path != 1)
		ft_free_tab(data->path);
	if ((exec == 1 && data->in_bool == 1) || (exec == 1 && data->out_bool == 1))
		execve(data->cmd_flag[0], data->cmd_flag, data->envp);
	ft_free_tab(data->cmd_flag);
	exit(127);
}

void	waitprocess(int cmd)
{
	while (cmd)
	{
		waitpid(-1, NULL, 0);
		cmd--;
	}
}

void	process(t_data *data, char **argv)
{
	int	i;
	int	pipe_direction;
	int	pid;
	int	cmd;

	pipe_direction = 0;
	i = 0;
	cmd = data->nb_args;
	if (pipe(data->pfd) < 0)
		return ;
	while (data->nb_args != 0)
	{
		data->cmd_flag = ft_split(data->cmd[i], ' ');
		pid = fork();
		if (pid == 0)
			child_process(data, argv, pipe_direction, i);
		i++;
		ft_free_tab(data->cmd_flag);
		data->nb_args--;
	}
	close(data->pfd[0]);
	close(data->pfd[1]);
	waitprocess(cmd);
}

void	set_path(t_data *data)
{
	int	i;

	i = 0;
	data->path = NULL;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], "PATH=", 5) == 0)
		{
			data->path = ft_split(data->envp[i] + 5, ':');
			break ;
		}
		i++;
	}
}

void	set_data(t_data *data, int argc, char **argv, char **envp)
{
	int	a;
	int	b;

	a = 0;
	b = 2;
	data->unset_path = 0;
	data->cmd = malloc(sizeof(char *) * argc - 3);
	data->envp = envp;
	set_path(data);
	if (data->path == NULL)
		data->unset_path = 1;
	while (a < argc - 3)
	{
		data->cmd[a] = argv[b];
		b++;
		a++;
	}
	data->nb_args = a;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
	{
		printf("larguboloss");
		return (0);
	}
	set_data(&data, argc, argv, envp);
	check_file(&data, argv);
	process(&data, argv);
	if (data.unset_path != 1)
		ft_free_tab(data.path);
	free(data.cmd);
	ft_close(&data);
}
