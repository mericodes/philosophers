/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:55:12 by codespace         #+#    #+#             */
/*   Updated: 2024/02/02 17:14:23 by mlopez-i         ###   ########.fr       */
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
	data.t_start = get_time(0);
	pthread_mutex_unlock(&data.mdata);
	has_ended(&data);
	ft_exit(&data);
	return (0);
}
