/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:55:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 19:58:45 by mlopez-i         ###   ########.fr       */
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
		ft_exit(&data);
		ft_error(INIT_ERROR);
		return (1);
	}
	if (!threads_init(&data))
	{
		ft_exit(&data);
		ft_error(THREAD_ERROR);
		return (1);
	}
	
	ft_exit(&data);
	return (0);
}
