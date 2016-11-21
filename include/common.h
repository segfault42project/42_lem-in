/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:31:13 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/21 20:46:19 by rabougue         ###   ########.fr       */
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
	char				**map; // map stored int this char **
	char				*room_list; // all rooms stored in room_list tab
	int					*index_map; // index of all map (see define for more info)

	char				**room; // all room stored here
	char				**cmd; // all command stored here
	char				**cmt; // all comment stored here
	char				**link; // all link stored here

	int					nb_lines_map; // nb line of all map
	int					nb_rooms_line; // nb room_line only
	int					nb_cmd_line; // nb cmd_line only
	int					nb_cmt_line; // nb cmt_line only
	int					nb_link_line; // nb link_line only


	int					nb_ants; // nb ants
	int					nb_rooms; // nb rooms

	int					ants_line; // nb ants_line
	int					room_line; // nb room_line (all line between ants line and before link_line)
	int					link_line; //nb link_line (all line at the first link_line)

	char				*start;
	char				*end;
}						t_env;
/*
** parsing.c
*/
int8_t					parsing_map_stdin(t_env *env);
/*
** map.c
*/
void					alloc_tab(t_env *env, char *line, int size);
void					save_map(t_env *env);
/*
** parsing_ants.c
*/
int8_t					check_ants_valid(t_env *env);
/*
** parsing_room.c
*/
int8_t					count_all(t_env *env);
void					stock_all(t_env *env);
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

#endif
