/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:43:25 by lfarlen           #+#    #+#             */
/*   Updated: 2019/09/23 20:13:01 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <../libft/include/libft.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_room	t_room;
typedef struct s_link	t_link;

struct					s_link
{
	t_room	*room;
	t_link	*next;
};

struct					s_room
{
	char	*name;
	int		ant_name;
	int		nb_ants;
	int		dist_point;
	int		coord[2];

	int		start;
	int		end;

	t_link	*connection;
	t_room	*next;
};

typedef struct			s_env
{
	char	**original_map;
	t_room	*start;
	t_room	**paths;
	int		nb_ants;
	int		arrive_ants;
	int		unique_path;
	int		print_path;
	int		print_connection;
}						t_env;

void					ft_moove_ants(t_env *env);
char					**ft_get_data_commands(t_env *e, char **input);
char					**ft_get_data_comments(char **input);
void					ft_free_paths(t_room **p);
void					ft_free_start(t_room *r);
void					ft_clear_path(t_room ***paths, int i);
int						ft_check_name(char *name, t_env env);
int						ft_valid_name(char *name);
int						ft_check_connect(char *n1, char *n2, t_env env);
void					ft_print_path(t_env env);
void					ft_print_room(t_env env);
int						ft_parse_map(char **map, t_env *env);
int						ft_get_connect(char *line, t_env *env);
int						ft_add_connect(t_env *env, char *name1, char *name2);
t_link					*ft_create_connect(t_room *room);
int						ft_get_room(char *line, t_env *env, int s, int e);
int						ft_dist_point(t_env env);
int						ft_find_valid_paths(t_env *env);
int						ft_max_path(t_env *env);
void					ft_find_small_path(t_room *start, t_env *env);
int						ft_get_small_path(t_room *room);
t_room					*ft_create_link_room(char *n, int s, int e, int c[2]);
void					ft_add_room(int i, t_room *r, t_room ***paths);

#endif
