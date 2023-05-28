/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:00:34 by daumis            #+#    #+#             */
/*   Updated: 2023/05/27 13:12:08 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	t_data	data;
	int		i;

	if (argc < 5)
	{
		ft_putstr_fd("Usage: file1 <cmd1> <cmd2> file2\n", 2);
		exit (1);
	}
	ft_memset(&data, 0, sizeof(t_data));
	data.inf_name = argv[1];
	data.otf_name = argv[argc - 1];
	ft_parse_cmds(&data, argc, argv);
	get_paths(&data, env);
	i = 0;
	while (data.commands[i])
	{
		ft_execute(&data, env, argc, &i);
		i++;
	}
	ft_cleanup(&data);
}
