/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:55:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 15:00:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!get_args(argc, argv, &data))
	{
		ft_error(ARGS_ERROR);
		return (1);
	}
	if (!data_init(&data))
	{
		ft_free(&data);
		ft_error(INIT_ERROR);
		return (1);
	}
	ft_free(&data);
	return (0);
}