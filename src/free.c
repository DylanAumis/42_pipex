/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:11:57 by dylan             #+#    #+#             */
/*   Updated: 2023/05/30 17:55:46 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*Function that will free all allocated ressources if they are freeable*/
void	ft_cleanup(t_data *data)
{
	int	j;

	j = 0;
	if (data->args)
	{
		while (data->args[j])
			free(data->args[j++]);
		free(data->args);
	}
	j = 0;
	if (data->paths)
	{
		while (data->paths[j])
			free(data->paths[j++]);
		free(data->paths);
	}
	if (data->commands)
		free(data->commands);
	if (!data->cmd_exists)
		free(data->fused_cmd);
}

/*This function will check if user input exists as a command or not*/
int	cmd_check(t_data *data, int *i)
{
	char	*dupcmd;

	dupcmd = NULL;
	if (ft_strchr(data->commands[*i], '/'))
	{
		dupcmd = ft_strdup(data->commands[*i]);
		data->fused_cmd = dupcmd;
		if (access(data->fused_cmd, F_OK) != 0)
		{
			ft_putstr_fd(data->fused_cmd, 2);
			ft_putstr_fd(": command not found", 2);
			write(2, "\n", 1);
		}
		return (0);
	}
	return (1);
}
