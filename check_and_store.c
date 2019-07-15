/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:05:48 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/07/15 16:35:01 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_file(int fd, t_fillit *table, int *n)
{
	int		r;
	char	buff[22];
	char	last;
	int		nbr;

	r = 0;
	last = '\n';
	while (((r = read(fd, buff, 21)) > 0) && (*n < 26))
	{
		buff[r] = '\0';
		nbr = check_links(buff);
		if (check_form(buff) == 0 || (nbr != 6 && nbr != 8))
			return (0);
		else
			assigne(table, (*n)++, buff);
		last = buff[20];
	}
	if ((r < 0) || (last != 0))
		return (0);
	return (1);
}

void	assigne(t_fillit *table, int i, char *buff)
{
	int		hash_nbr;
	int		j;

	hash_nbr = 0;
	j = 0;
	while (buff[j])
	{
		if (buff[j] == '#')
		{
			table[i].row[hash_nbr] = (j / 5);
			table[i].col[hash_nbr] = (j % 5);
			hash_nbr++;
		}
		j++;
	}
	table[i].alpha = i + 65;
}
