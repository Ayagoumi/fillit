/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:52:35 by mzaboub           #+#    #+#             */
/*   Updated: 2019/07/15 16:35:03 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_fillit	table[26];
	int			tit_num;

	if (argc != 2)
		ft_putstr("fillit usage : ./fillit fileName\n");
	else
	{
		tit_num = 0;
		fd = open(argv[1], O_RDONLY);
		if (check_file(fd, table, &tit_num) == 0)
			ft_putstr("error\n");
		else
			fillit(table, tit_num);
		close(fd);
	}
	return (0);
}
