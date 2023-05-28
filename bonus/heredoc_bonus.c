/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:44:04 by daumis            #+#    #+#             */
/*   Updated: 2023/05/28 16:34:37 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*Modified join Function that doesnt add the char "/" at the end of s1*/
char	*ft_join_bonus(char *s1, char *s2)
{
	char	*pstr;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	pstr = malloc (size * sizeof(char) + 1);
	if (!pstr)
		return (0);
	while (s1 && s1[i])
	{
		pstr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		pstr[i++] = s2[j++];
	pstr[i] = '\0';
	return (pstr);
}

/*This function will initialize here_doc as "file1" if it has been found*/
void	heredoc_redirect(t_data *data)
{
	data->io_fds[0] = open("here_doc", O_RDONLY);
	if (data->io_fds[0] == -1)
		data->no_infile = 1;
	dup2(data->io_fds[0], STDIN_FILENO);
	close(data->io_fds[0]);
}

/*This loop uses GNL to check if the limiter as been found in the input*/
void	heredoc_loop(t_data *data, char *argv[])
{
	char	*line;
	char	*limiter;

	limiter = ft_join_bonus(argv[2], "\n");
	write(1, ">", 1);
	line = get_next_line(0, 0);
	while (ft_strncmp(line, limiter, ft_strlen(line)) != 0)
	{
		write(1, ">", 1);
		write(data->io_fds[0], line, ft_strlen(line));
		free(line);
		line = get_next_line(0, 0);
	}
	get_next_line(0, 1);
	free(line);
	free(limiter);
	close(data->io_fds[0]);
}
