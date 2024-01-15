/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:29:34 by codespace         #+#    #+#             */
/*   Updated: 2024/01/15 19:22:49 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>


/*	defines	*/
# define ARGS_ERROR 0
# define INIT_ERROR 1
# define THREAD_ERROR 2

/*	struct of forks	*/
typedef struct s_fork
{
	pthread_mutex_t	mfork;
	int				id;
}	t_fork;

/*	struct of each philosopher	*/
typedef struct s_philo
{
	struct s_data		*data;
	pthread_t			thread;
	int					philo;
	int					eating;
	int					meals_eaten;
	int					last_meal;
	t_fork				*l_fork;
	t_fork				*r_fork;
}	t_philo;

/*	struct of general data	*/
typedef struct s_data
{
	int				total_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				num_to_eat;
	int				start_time;
	int				dead;
	int				finish;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	mwrite;
}	t_data;

/*	argcs.c		*/
int		str_is_digit(char *str);
long	ft_atoi(const char *str);
int		get_args(int argc, char *argv[], t_data *data);

/*	errors.c	*/
void	ft_error(int error);
void	ft_free(t_data *data);
void	ft_finish(t_data *data);

/*	philo.c		*/
int		init_forks(t_data *data);
int		init_data(t_data *data);
/*	threads.c	*/
void	*ft_routine(void *dat);
int		create_philos(t_data *data);

#endif