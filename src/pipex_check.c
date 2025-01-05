/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:17:01 by lperis            #+#    #+#             */
/*   Updated: 2025/01/05 14:51:56 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file(t_data *data, char **argv)
{
	data->in_fd = open(argv[1], O_RDONLY);
	if (data->in_fd < 0)
	{
		if (access(argv[1], F_OK) != 0)
			ft_printf_pfd(2, "No such file or directory %s\n", argv[1]);
		else if (access(argv[1], R_OK) != 0)
		{
			ft_printf_pfd(2, "Permission denied %s\n", argv[1]);
			data->status = 0;
		}
	}
	data->out_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->out_fd < 0)
	{
		if (access(argv[4], W_OK) != 0)
		{
			ft_printf_pfd(2, "permission denied %s\n", argv[4]);
			data->status = 1;
		}
		else
			return ;
	}
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
	ft_printf_pfd(2, "Command not found\n", data->cmd_flag[0]);
	return (0);
}

int	ft_access(t_data *data)
{
	int		accs;

	accs = 0;
	if (data->cmd_flag[0] == NULL && data->in_fd >= 0 \
		&& data->out_fd >= 0)
		ft_printf_pfd(2, "Command not found\n", data->cmd_flag[0]);
	if ((data->cmd_flag[0] == NULL) || \
		(data->unset_path == 1 && data->f_path == 0))
		return (accs);
	if (data->f_path == 0)
		accs = get_path(data);
	else
	{
		if (access(data->cmd_flag[0], X_OK) == 0)
			accs = 1;
		else if (data->in_fd >= 0 && data->out_fd >= 0)
		{
			ft_printf_pfd(2, "%s: No such file or directory\n", \
				data->cmd_flag[0]);
		}
	}
	return (accs);
}
