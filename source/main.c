/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:13:32 by rabougue          #+#    #+#             */
/*   Updated: 2016/11/22 18:09:06 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	main(int argc, char **argv)
{
	t_env	env;
	int8_t	ret;

	ret = 0;
	memset(&env, 0, sizeof(env));
	if (argc == 1)
		save_map(&env);
	/*else if (argc == 2)*/
		/*parsing_map_file(&env);*/
	ret = parsing_map_stdin(&env);
	if (ret >= EXIT_ERROR_LINK && ret <= EXIT_ERROR_CMD)
		print_error(env.map, env.nb_lines_map, ret);
	ft_2d_tab_free(env.map, env.nb_lines_map);
	(void)argc;
	(void)argv;
}
