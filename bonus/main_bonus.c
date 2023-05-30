/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:00:34 by daumis            #+#    #+#             */
/*   Updated: 2023/05/30 19:20:24 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	t_data	data;
	int		i;

	if (argc < 5)
	{
		ft_putstr_fd("Usage: file1 <cmd1> <cmd2> ... <cmdn> file2 OR ", 2);
		ft_putstr_fd("here_doc LIMITER <cmd1> <cmd2> ... <cmdn> Outfile\n", 2);
		exit (1);
	}
	i = -1;
	ft_memset(&data, 0, sizeof(t_data));
	heredoc_check(&data, argc, argv);
	data.inf_name = argv[1];
	data.otf_name = argv[argc - 1];
	ft_parse_cmds(&data, argc, argv);
	get_paths(&data, env);
	if (data.no_heredoc == 0)
		heredoc_loop(&data, argv);
	while (data.commands[++i])
		ft_execute(&data, env, &i);
	ft_cleanup(&data);
	unlink("here_doc");
	close(data.pipe_fd[0]);
	close(data.pipe_fd[1]);
}
