/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:55:11 by mzaboub           #+#    #+#             */
/*   Updated: 2019/07/15 16:21:49 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_fillit
{
	size_t	row[4];
	size_t	col[4];
	char	alpha;
}				t_fillit;

typedef	struct	s_board_indice
{
	size_t	i;
	size_t	j;
}				t_board_indice;

void			fillit(t_fillit *table, int table_size);
int				check_and_place(char **board, t_board_indice indice,\
		t_fillit colum);
void			remove_titrimino(char **board, t_board_indice indice,\
		t_fillit colum);
int				backtracking(t_fillit *table, int tab_index, int tab_size,\
		char **board);
void			shift_titriminos(t_fillit *table, size_t table_size);
char			**allocate_board(int n);
void			print_board(char **board, int size);
void			free_board(char **board, int size);
void			assigne(t_fillit *table, int i, char *buff);
int				check_char_numbs(char *buff);
int				check_links(char *buff);
int				check_form(char *buff);
int				check_file(int fd, t_fillit *table, int *n);

# define VALID 0
# define NON_VALID 1

#endif
