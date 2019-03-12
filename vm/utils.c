/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:07:17 by gdanylov          #+#    #+#             */
/*   Updated: 2018/11/13 22:56:11 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

short				ft_isfile(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (0);
	}
	perror(path);
	return (-1);
}
