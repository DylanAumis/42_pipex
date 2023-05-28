/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:38:41 by daumis            #+#    #+#             */
/*   Updated: 2023/05/28 16:29:00 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*This function will parse the commands and store them into a 2D Array */
void	ft_parse_cmds(t_data *data, int ac, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 3;
	data->commands = malloc((ac - 3) * sizeof(char *));
	if (!data->commands)
		return ;
	while (j < (ac - 1))
	{
		data->commands[i] = argv[j];
		i++;
		j++;
	}
	data->commands[i] = NULL;
}

/*This function will check if the cmd exists within paths and store it*/
void	make_command(t_data *data, int *i)
{
	int		j;

	j = 0;
	data->cmd_exists = 0;
	data->fused_cmd = NULL;
	data->args = ft_split(data->commands[*i], ' ');
	while (data->paths[j])
	{
		free(data->fused_cmd);
		data->fused_cmd = ft_join(data->paths[j], data->args[0]);
		if (access(data->fused_cmd, F_OK) == 0)
		{
			data->cmd_exists = 1;
			break ;
		}
		j++;
	}
	if (!data->cmd_exists)
	{
		ft_putstr_fd(data->args[0], 2);
		ft_putstr_fd(" : command not found", 2);
		write(2, "\n", 1);
	}
}

/*This function will isolate the "PATH" line from env*/
void	get_paths(t_data *data, char *env[])
{
	int		path_start;
	int		i;
	char	*path_copy;
	char	*temp_path;

	i = 0;
	path_start = 1;
	while (path_start != 0)
	{
		path_start = ft_strncmp("PATH=", env[i], 5);
		i++;
	}
	i -= 1;
	path_copy = ft_strdup(env[i]);
	temp_path = path_copy;
	path_copy += 5;
	data->paths = ft_split(path_copy, ':');
	free(temp_path);
}

/*This function will join our commands with the path (Ex: /bin + ls = /bin/ls)*/
char	*ft_join(char *s1, char *s2)
{
	char	*pstr;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	pstr = malloc (size * sizeof(char) + 2);
	if (!pstr)
		return (0);
	while (s1 && s1[i])
	{
		pstr[i] = s1[i];
		i++;
	}
	pstr[i++] = '/';
	while (s2 && s2[j])
		pstr[i++] = s2[j++];
	pstr[i] = '\0';
	return (pstr);
}

int	heredoc_check(t_data *data, char *argv[])
{
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
	{
		data->no_heredoc = 0;
		data->io_fds[0] = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (data->io_fds[0] == -1)
			data->no_infile = 1;
	}
	else
		data->no_heredoc = 1;
	return (0);
}
