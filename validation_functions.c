/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:31:42 by mzaboub           #+#    #+#             */
/*   Updated: 2019/07/15 16:20:52 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_form(char *buff)
{
	int		i;

	i = -1;
	if (!(buff[4] == '\n' && buff[9] == '\n' && buff[14] == '\n' &&\
				buff[19] == '\n'))
		return (0);
	if ((buff[20] != '\n' && buff[20] != '\0') || (check_char_numbs(buff) == 0))
		return (0);
	return (1);
}

int	check_char_numbs(char *buff)
{
	int	cp;
	int	co;
	int	i;

	co = 0;
	cp = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '.')
			cp++;
		if (buff[i] == '#')
			co++;
		i++;
	}
	if (co != 4 || cp != 12)
		return (0);
	return (1);
}

int	check_links(char *buff)
{
	int i;
	int link;

	i = 0;
	link = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			if (buff[i + 1] == '#')
				link++;
			if ((i > 0) && buff[i - 1] == '#')
				link++;
			if ((i < 15) && buff[i + 5] == '#')
				link++;
			if ((i > 4) && buff[i - 5] == '#')
				link++;
		}
		i++;
	}
	return (link);
}
