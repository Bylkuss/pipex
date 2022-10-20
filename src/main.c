/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:50:22 by loadjou           #+#    #+#             */
/*   Updated: 2022/08/14 16:58:33 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"
#include <string.h>

int	main(int argc, char **argv, char **envp)
{
	int	fd;

	if (argc == 5)
	{
		fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd < 0)
			error_msg("File2 can't be opened");
		pipex(fd, argv, envp);
		close(fd);
	}
	else
		error_msg("Error! Format must be as flw:\nfile1 cmd1 cmd2 file2\n");
	return (0);
}
