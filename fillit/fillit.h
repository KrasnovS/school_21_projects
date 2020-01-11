/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:07:06 by lfarlen           #+#    #+#             */
/*   Updated: 2019/05/04 22:16:06 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 21

typedef struct	s_position
{
	int			row;
	int			col;
}				t_position;

typedef struct	s_figurka
{
	t_position	*tochka;
	char		bukva;
}				t_figurka;

typedef struct	s_solver
{
	int			size;
	char		*table;
}				t_solver;

void			*ft_memalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			ft_usage(void);
int				ft_valid_fig(char *buf);
int				ft_figurki(char *list, t_figurka ***p_list_tetri);
size_t			ft_strlen(const char *str);
t_figurka		*ft_get_fig(char *list, size_t *p_i, char *tmp, size_t k);
int				ft_get_next_fig(char *list, char *buf, char c, size_t *tmp_i);
void			ft_move(char *tetri);
void			ft_move_v(char *tetri, int k);
void			ft_move_h(char *tetri, int k);
t_figurka		*tmp_fig(char *str);
int				ft_points(t_position *point);
int				ft_on_map(t_position p1, t_position p2);
void			ft_memdel(void **ap);
void			ft_solver(t_figurka **list);
int				ft_map_size(int n);
size_t			ft_lstlen(t_figurka **list_tetri);
int				ft_resolver(t_figurka **list, t_solver *d);
int				ft_place_fig(t_figurka **list, t_solver *d, int pos, int i);
void			on_fig(char *table, t_figurka *tetri, int pos, int size);
void			off_fig(char *table, t_figurka *tetri);
void			ft_write_on(char *table, char letter, int index);
int				ft_check(char *table, t_figurka **list);
int				ft_search(char *table, char c);
int				ft_on_fig(char *table, t_figurka *tetri, int pos, int size);
int				ft_point(char *table, int col, int row, int size);
void			ft_print_map(char *empty, int size);
void			ft_error(void);
void			free_list(t_figurka **list_tetri);
#endif
