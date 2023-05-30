/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:53 by daumis            #+#    #+#             */
/*   Updated: 2023/05/30 19:37:46 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"

/*Data Collection*/
typedef struct s_data
{
	char	**paths;
	char	**args;
	char	**commands;
	char	*fused_cmd;
	char	*inf_name;
	char	*otf_name;
	int		io_fds[2];
	int		pipe_fd[2];
	int		prev_fd[2];
	int		no_infile;
	int		no_heredoc;
	int		cmd_exists;
	int		argc_copy;
	pid_t	pid;
}	t_data;

/*Main functions*/
void	ft_init_infile(t_data *data);
void	ft_init_outfile(t_data *data);
void	ft_parse_cmds(t_data *data, int ac, char *argv[]);
void	make_command(t_data *data, int *i);
void	parent_process(t_data *data, int *i);
void	child_process(t_data *data, char *env[], int *i);
void	ft_execute(t_data *data, char *env[], int *i);
void	get_paths(t_data *data, char *env[]);
void	ft_cleanup(t_data *data);
int		cmd_check(t_data *data, int *i);
char	*ft_join(char *s1, char *s2);
/*Bonus functions*/
int		heredoc_check(t_data *data, int argc, char *argv[]);
void	heredoc_loop(t_data *data, char *argv[]);
void	heredoc_redirect(t_data *data);
char	*ft_join_bonus(char *s1, char *s2);

#endif