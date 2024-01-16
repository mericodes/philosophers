/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:48 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 17:02:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*	./philo 5 800 200 200 [5]	*/

void	wait_threads(t_data *data)
{
	while (get_int(&data->mdata, &data->start) == 0)
		;
}

void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->data);
	printf("THREAD PHILO ID::: %i \n", philo->id);
	return (NULL);
}

int	sim_start(t_data *data)
{
	int	i;

	i = -1;
	if (data->max_meals == 0)
		return (0);
	else if (data->total_philos == 1)
		return (0);	//cambiar
	else
	{
		printf("START::: %i \n", data->start);
		printf("ELSE OK   TOTALPHILOS::: %li\n", data->total_philos);
		while (++i < data->total_philos)
		{
			printf("PHILO[I]::: %i   PHILO ID::: %i \n", i, data->philos[i].id);
			if (pthread_create(&data->philos[i].tid, NULL, &simulation, &data->philos[i]) != 0)
				return (0);
		}
	}
	printf("THREAD OK \n");
	set_int(&data->mdata, &data->start, 1);
	printf("START::: %i \n", data->start);
	return (1);
}