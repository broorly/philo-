#include"../philo.h"

void	*room(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eating(philo);
		sleeping(philo);
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

void killer(t_philo *philo,t_data *data)
{
	int i;
	i = 0;
	while (i < data->number)
	{
		if(philo[i].last_time_eating - ft_time(philo->last_time_eating) > data->time_die )
		{
			printf("philo %d is dead\n",philo[i].id);
			pthread_mutex_lock(philo->data->display);
			printf("philo %d is dead\n",philo[i].id);
		}
		i++;
	}
}