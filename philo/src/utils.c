/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:56:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 16:44:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_error(int error)
{
	if (error == ARGS_ERROR)
	{
		write(1, "Wrong arguments. Try: \n", 23);
		write(1, "- number_of_philosophers\n- time_to_die\n", 39);
		write(1, "- time_to_eat\n- time_to_sleep\n", 30);
		write(1, "- [number_of_times_each_philosopher_must_eat]\n", 46);
	}
	if (error == INIT_ERROR)
		write(1, "Initialization error\n", 21);
	if (error == THREAD_ERROR)
		write(1, "Error creating threads\n", 23);
}

void	ft_free(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
}

/*long	get_time()
{
	
}*/