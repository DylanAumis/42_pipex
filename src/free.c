/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:11:57 by dylan             #+#    #+#             */
/*   Updated: 2023/05/28 16:25:51 by dylan            ###   ########.fr       */
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
