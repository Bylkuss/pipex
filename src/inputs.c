/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:57:28 by loadjou           #+#    #+#             */
/*   Updated: 2022/08/22 11:26:08 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

char	*get_cmd(char *s)
{
	char	**temp;
	char	*cmd;
	int		len;

	temp = ft_split(s, ' ');
	len = ft_strlen(*temp);
	cmd = ft_substr(*temp, 0, len);
	freetab(temp);
	return (cmd);
}

char	*check_path(char **env, char *argv)
{
	int		i;
	char	*cmd1;
	char	*cmd;
	char	*rpath;

	i = 0;
	cmd1 = get_cmd(argv);
	cmd = ft_strjoin("/", cmd1);
	free(cmd1);
	while (env[i++])
	{
		rpath = ft_strjoin(env[i], cmd);
		if (env[i] && access(rpath, (F_OK, X_OK)) == 0)
		{
			free(cmd);
			freetab(env);
			return (rpath);
		}
		free(rpath);
	}
	free(cmd);
	free(rpath);
	freetab(env);
	error_msg("Command not found! Please try again...");
	return (NULL);
}

char	*get_paths(char **env, char *cmd)
{
	int		i;
	char	*paths;
	char	**splitted_p;
	char	*ret;

	i = 0;
	while (env[i] != NULL)
	{
		paths = ft_strstr(env[i], "PATH=");
		if (paths)
		{
			paths = ft_strtrim(paths, "PATH=");
			splitted_p = ft_split(paths, ':');
			ret = check_path(splitted_p, cmd);
			free(paths);
			return (ret);
		}
		i++;
	}
	error_msg("Sorry! Error occured while trying to get envp.");
	return (NULL);
}
