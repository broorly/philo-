/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:15:41 by mrafik            #+#    #+#             */
/*   Updated: 2022/08/05 16:21:53 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

void	*room(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		print(philo, "is thinking", ft_time(philo->data->current_time));
	}
	return (NULL);
}

pthread_mutex_t	*init_mutex(pthread_mutex_t *mutex, int size)
{
	int	i;

	i = 0;
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * size);
	if (!mutex)
		return (NULL);
	while (i < size)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}

int	killer(t_philo *philo, t_data *data)
{
	int	i;
	int	x;

	i = 0;
	while (i < data->number)
	{
		x = ft_time(philo[i].data->current_time + philo[i].last_time_eating);
		if (x >= data->time_die
			|| (philo[i].counter == data->h_much && data->h_much != 0))
		{
			pthread_mutex_lock(philo->data->display);
			printf("%ld philo %d is dead\n",
				ft_time(philo[i].data->current_time), philo[i].id);
			return (1);
		}
		i++;
	}
	return (0);
}
