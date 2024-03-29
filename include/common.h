/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:31:13 by rabougue          #+#    #+#             */
/*   Updated: 2017/01/18 21:40:32 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <limits.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# define EXIT_ERROR_LINK	1
# define EXIT_ERROR_ANTS	2
# define EXIT_ERROR_ROOM	3
# define EXIT_ERROR_CMD		4
# define ANTS				1
# define CMD				2
# define ROOM				3
# define CMT				4
# define LINK				5
# define LINE_ERROR			6

typedef struct			s_env
{
	char				**map;
	char				*room_list;
	int					*index_map;
	char				**room;
	char				**cmd;
	char				**cmt;
	char				**link;
	char				**room_link;
	char				**room_only;
	char				**path;
	char				**split_path;
	int					nb_lines_map;
	int					nb_rooms_line;
	int					nb_cmd_line;
	int					nb_cmt_line;
	int					nb_link_line;
	int					nb_ants;
	int					nb_rooms;
	int					ants_line;
	int					room_line;
	int					link_line;
	char				*start;
	char				*end;
	char				**link_two;
	char				*print_map;
	int					number_step;
	bool				write_file;
	bool				sound;
	uint8_t				time;
	int					fd_file_bonus;
}						t_env;
/*
** parsing.c
*/
int8_t					parsing_map_stdin(t_env *env);
int8_t					check_multiple_same_rooms(t_env *env);
/*
** map.c
*/
void					alloc_tab(t_env *env, char *line, int size);
void					save_map(t_env *env, int option, char *argv);
/*
** parsing_ants.c
*/
int8_t					check_ants_valid(t_env *env);
/*
** parsing_room.c
*/
int8_t					count_all(t_env *env);
int8_t					stock_all(t_env *env);
int8_t					parsing_room(t_env *env);
int8_t					check_room_valid(char *line);
/*
** main.c
*/
void					check_error_gnl(char **line);
void					print_error_ants(char **map, int y_tab);
/*
** parsing_command_and_comment.c
*/
int8_t					check_if_is_command(char *line);
int8_t					check_if_is_comment(char *line);
int8_t					parsing_link(t_env *env);

void					print_error(char **map, int y_tab, int8_t err_num);
int8_t					check_nb_cmd(t_env *env);
int8_t					check_nb_room(t_env *env);
/*
** algo.c
*/
int8_t					algo(t_env *env);
int8_t					get_start_and_end(t_env *env);
void					get_room_only(t_env *env);
void					stock_link_with_room(t_env *env);
void					print_ants(t_env *env);
void					print_simple_error();
int8_t					fill_room_link_cmt_cmd(t_env *env);
char					*fill_print_map(char *s1, char *s2);
char					*fill_print_map_nbn(char *s1, char *s2);
void					check_if_room_exist(t_env *env);
int8_t					check_if_start_and_and_are_connected(t_env *env);
void					protect_argc(int argc, char **argv);
int8_t					check_option(t_env *env, char **argv, int argc);
void					create_file(t_env *env, char *argv);
void					print_usage();

#endif
