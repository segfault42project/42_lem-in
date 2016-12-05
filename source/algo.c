/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:00:29 by rabougue          #+#    #+#             */
/*   Updated: Mon Nov 28 22:45:27 2016                                        */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int8_t	check_if_start_and_and_are_connected(t_env *env)
{
	int		i;
	char	**split;
	char	*start;
	char	*end;

	i = 0;
	start = ft_strcdup(env->start, ' ');
	end = ft_strcdup(env->end, ' ');
	while (ft_strccmp(start, env->room_link[i], ',') != 0)
	{
		i++;
		if (i >= env->nb_rooms_line)
			print_simple_error();
	}
	split = ft_strsplit(env->room_link[i], ',');
	i = 0;
	while (split[i])
	{
		if (ft_strcmp(end, split[i]) == 0)
		{
			free(start);
			free(end);
			ft_2d_tab_free(split, ft_count_2d_tab(split));
			return (true);
		}
		++i;
	}
	free(start);
	free(end);
	ft_2d_tab_free(split, ft_count_2d_tab(split));
	return (false);
}

int8_t	check_if_start_found(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_rooms_line)
	{
		while (env->path[i] == NULL)
			++i;
		if (ft_strccmp(env->path[i], env->start, ' ') == 0)
			return (true);
		++i;
	}
	return (false);
}

int8_t	check_if_room_is_already_stored(t_env *env, int iter)
{
	int	i;

	i = 0;
	while (i < env->nb_rooms_line)
	{
		while (env->path[i] == NULL)
			++i;
		if (env->split_path[iter] == NULL)
		{
			ft_fprintf(2, RED"No path found\n"END);
			exit(EXIT_FAILURE);
		}
		if (ft_strcmp(env->path[i], env->split_path[iter]) == 0)
			return (true);
		++i;
	}
	return (false);
}
//================================Temp_function================================

void	print_path(t_env *env)
{
	for(int a = 0; a < env->nb_rooms_line; ++a)
		ft_fprintf(1, "%s\n", env->path[a]);
}

void	print_room_link(t_env *env)
{
	ft_fprintf(1, YELLOW"===========Room_link=============\n"END);
	for(int a = 0; a < env->nb_rooms_line; ++a)
		ft_fprintf(1, YELLOW"%s\n"END, env->room_link[a]);
	ft_fprintf(1, YELLOW"================END==============\n"END);
}

//=============================================================================

int8_t	looking_for_connected_room(t_env *env, int iter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strccmp(env->path[iter], env->room_link[i], ',') != 0)
	{
		i++;
		if (env->room_link[i] == NULL)
			print_simple_error();
	}
	while (j < env->nb_rooms_line)
	{
		while (env->path[j] == NULL)
			++j;
		if (ft_strccmp(env->path[j], env->room_link[i], ',') == 0)
		{
			env->split_path = ft_strsplit(env->room_link[i], ',');
			return (true);
		}
		++j;
	}
	return (false);
}

void	looking_for_path(t_env *env)
{
	int		iter;
	int		i;

	iter = env->nb_rooms_line -1;
	env->path = (char **)ft_memalloc(sizeof(char *) * env->nb_rooms_line);
	env->path[iter] = ft_strcdup(env->end, ' ');
	if (check_if_start_and_and_are_connected(env) == true)
	{
		env->path[--iter] = ft_strcdup(env->start, ' ');
		print_path(env);
		return ;
	}
	while (check_if_start_found(env) == false)
	{
		i = 1;
		if (looking_for_connected_room(env, iter) == true)
		{
			while (check_if_room_is_already_stored(env, i) == true)
				i++;
			--iter;
			env->path[iter] = ft_strdup(env->split_path[i]);
			ft_2d_tab_free(env->split_path, ft_count_2d_tab(env->split_path));
		}
	}
}

void	check_if_room_exist(t_env *env)
{
	int	i;
	int	j;
	int	iter = 0;

	i = 0;
	j = 0;
	char	**split;
	char	**link_only;

	link_only = (char **)ft_memalloc(sizeof(char *) * (env->nb_link_line * 2));
	split = NULL;
	while (i < env->nb_link_line)
	{
		split = ft_strsplit(env->link[i], '-');
		while (split[iter])
		{
			link_only[j] = split[iter];
			++iter;
			++j;
		}
		++i;
		iter = 0;
	}
	i = 0;
	j = 0;
	/*for (int a = 0; a < env->nb_link_line * 2; ++a)*/
		/*ft_fprintf(1, "%s\n", link_only[a]);*/
	while (i < env->nb_link_line * 2)
	{
		while (j < env->nb_rooms_line)
		{
			ft_fprintf(1, "%s, %s\n", link_only[i], env->room_only[j]);
			if (ft_strccmp(link_only[i], env->room_only[j], ' ') == 0)
				break ;
			++j;
			if (j >= env->nb_rooms_line)
				print_simple_error();
		}
		++i;
		j = 0;
	}
}

int8_t	algo(t_env *env)
{
	/*print_room_link(env);*/
	/*for(int a = 0; a < env->nb_link_line; a++)*/
		/*ft_fprintf(1, "%s\n", env->link[a]);*/
	check_if_room_exist(env);
	/*for(int a = 0; a < env->nb_link_line; a++)*/
		/*ft_fprintf(1, YELLOW"%s\n"END, env->link[a]);*/
	/*for(int b = 0; b < env->nb_rooms_line; b++)*/
		/*ft_fprintf(1, YELLOW"%s\n"END, env->room_only[b]);*/
	looking_for_path(env);
	return (EXIT_SUCCESS);
}
