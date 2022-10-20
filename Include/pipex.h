/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:45:10 by loadjou           #+#    #+#             */
/*   Updated: 2022/08/14 17:05:22 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/types.h>
# include <unistd.h>

char	*get_paths(char **env, char *argv);
char	*ft_strstr(char *str, char *to_find);
char	*check_path(char **env, char *argv);
char	*get_cmd(char *s);
void	error_msg(char *msg);
void	freetab(char **tab);
void	pipex(int fd, char **argv, char **env);
#endif
