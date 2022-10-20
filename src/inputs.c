/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:57:28 by loadjou           #+#    #+#             */
/*   Updated: 2022/08/14 16:56:30 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

char	*get_cmd(char *s)
{
	char	**temp;
	char	*cmd;

	temp = ft_split(s, ' ');
	cmd = ft_substr(*temp, 0, ft_strlen(*temp));
	freetab(temp);
	return (cmd);
}

char	*check_path(char **env, char *argv)
{
	int		i;
	char	*cmd;
	char	*rpath;

	i = 0;
	cmd = get_cmd(argv);
	cmd = ft_strjoin("/", cmd);
	while (env[i++])
	{
		rpath = ft_strjoin(env[i], cmd);
		if (access(rpath, (F_OK, X_OK)) == 0)
		{
			free(cmd);
			return (rpath);
		}
		free(rpath);
	}
	free(cmd);
	free(rpath);
	error_msg("Command not found! Please try again...");
	return (NULL);
}

char	*get_paths(char **env, char *cmd)
{
	int		i;
	char	*paths;
	char	**splitted_p;

	i = 0;
	while (env[i] != NULL)
	{
		paths = ft_strstr(env[i], "PATH=");
		if (paths)
		{
			paths = ft_strtrim(paths, "PATH=");
			splitted_p = ft_split(paths, ':');
			free(paths);
			return (check_path(splitted_p, cmd));
		}
		i++;
	}
	error_msg("Sorry! Error occured while trying to get envp.");
	return (NULL);
}
