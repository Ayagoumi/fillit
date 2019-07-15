/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:07:03 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/07/15 16:22:40 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	shift_titriminos(t_fillit *table, size_t table_size)
{
	size_t	col;
	int		i;
	size_t	row_to_decrease;
	size_t	col_to_decrease;

	col = 0;
	while (col < table_size)
	{
		row_to_decrease = table[col].row[0];
		col_to_decrease = 4;
		i = -1;
		while (++i < 4)
		{
			if (table[col].col[i] < col_to_decrease)
				col_to_decrease = table[col].col[i];
		}
		i = -1;
		while (++i < 4)
		{
			table[col].row[i] = table[col].row[i] - row_to_decrease;
			table[col].col[i] = table[col].col[i] - col_to_decrease;
		}
		col++;
	}
}

char	**allocate_board(int n)
{
	int		i;
	char	**board;

	if (!(board = (char**)malloc((n + 1) * sizeof(char*))))
		return (board);
	board[n] = NULL;
	i = 0;
	while (i < n)
	{
		if (!(board[i] = (char*)malloc((n + 1) * sizeof(char))))
		{
			free_board(board, i + 1);
			return (NULL);
		}
		ft_memset((void*)board[i], 46, n);
		board[i][n] = '\0';
		i++;
	}
	return (board);
}

void	print_board(char **board, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &board[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	free_board(char **board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(board[i]);
		i++;
	}
	free(board);
}
