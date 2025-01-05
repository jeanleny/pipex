/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:58:10 by lperis            #+#    #+#             */
/*   Updated: 2025/01/05 14:44:46 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(t_data *data)
{
	close(data->pfd[0]);
	close(data->pfd[1]);
	if (data->in_fd > 0)
		close(data->in_fd);
	if (data->out_fd > 0)
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
	data->status = 0;
	data->unset_path = 0;
	data->cmd = malloc(sizeof(char *) * argc - 3);
	if (data->cmd == NULL)
		return ;
	data->envp = envp;
	set_path(data);
	if (data->path == NULL)
		data->unset_path = 1;
	while (a < argc - 3)
	{
		data->cmd[a] = argv[b + a];
		a++;
	}
	data->nb_args = a;
}

void	waitprocess(t_data *data, int *pid)
{
	int	pid_status;
	int	i;

	i = 0;
	pid_status = 0;
	while (i < 2)
	{
		if (waitpid(-1, &pid_status, 0) == pid[1])
		{
			if (data->status == 0)
				data->status = WEXITSTATUS(pid_status);
		}
		i++;
	}
}
