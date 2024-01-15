/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:29:07 by codespace         #+#    #+#             */
/*   Updated: 2024/01/15 16:37:57 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		data->forks[i].fork_id = i + 1;
		if (pthread_mutex_init(&data->forks[i].mfork, NULL) != 0)
			return (0);
		// printf("FORK ID::::::::; %i\n", data->forks[i].fork_id);
		i++;
	}
	return (1);
}

int	init_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->total_philos);
	if (!data->philos)
		return (0);
	data->forks = malloc(sizeof(t_fork) * data->total_philos);
	if (!data->forks)
		return (0);
	data->end = 0;
	if (!init_forks(data))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!get_args(argc, argv, &data))
	{
		ft_error(ARGS_ERROR);
		return (1);
	}
	if (!init_data(&data))
	{
		ft_free(&data);
		ft_error(INIT_ERROR);
		return (1);
	}
	if (!create_philos(&data))
	{
		ft_free(&data);
		ft_error(THREAD_ERROR);
		return (1);
	}
	ft_finish(&data);
}
