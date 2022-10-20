/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:42:05 by loadjou           #+#    #+#             */
/*   Updated: 2022/08/21 11:28:17 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

static void	ft_child1(int fds[], char **argv, char **env)
{
	char	*cmd;
	int		file1;
	char	**full_cmd;

	file1 = open(argv[1], O_RDONLY, 0644);
	if (file1 == -1)
		error_msg("Error while trying to open file1\n");
	dup2(fds[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(fds[0]);
	cmd = get_paths(env, argv[2]);
	full_cmd = ft_split(argv[2], ' ');
	if (execve(cmd, full_cmd, env) == -1)
		error_msg("Error! ExecVe-1\n");
	free(cmd);
	freetab(full_cmd);
	close(fds[1]);
	close(file1);
}

static void	ft_child2(int file2, int fds[], char **argv, char **env)
{
	char	*cmd;
	char	**full_cmd;

	dup2(fds[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fds[1]);
	cmd = get_paths(env, argv[3]);
	full_cmd = ft_split(argv[3], ' ');
	if (execve(cmd, full_cmd, env) == -1)
	{
		free(cmd);
		freetab(full_cmd);
		// freetab(full_cmd);
		error_msg("Error! ExecVe-2\n");
	}
	free(cmd);
	freetab(full_cmd);
	close(fds[0]);
	close(file2);
}

void	pipex(int fd, char **argv, char **env)
{
	pid_t	child1;
	pid_t	child2;
	int		fdpipe[2];

	if (pipe(fdpipe) == -1)
		error_msg("Error while trying to create a pipe!");
	child1 = fork();
	if (child1 < 0)
		error_msg("Error while trying to fork !");
	if (child1 == 0)
		ft_child1(fdpipe, argv, env);
	child2 = fork();
	if (child2 < 0)
		error_msg("Error while trying to fork !");
	if (child2 == 0)
		ft_child2(fd, fdpipe, argv, env);
	close(fdpipe[0]);
	close(fdpipe[1]);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
}
