/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:46:23 by loadjou           #+#    #+#             */
/*   Updated: 2022/08/22 11:24:20 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	count;
	int	index;

	count = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[count])
	{
		index = 0;
		while (str[count + index] == to_find[index])
		{
			if (to_find[index + 1] == '\0')
				return (str + count);
			index++;
		}
		count++;
	}
	return (0);
}

void	freetab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
