#include"philo.h"

void	*room(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		pthread_mutex_lock(&philo->data->data_race[1]);
		if (philo->data->is_dead == 0)
			pthread_mutex_lock(&philo->data->display);
	printf("%ld | philo %d %s\n thinking ", time, philo->id);
	pthread_mutex_unlock(&philo->data->display);
		pthread_mutex_unlock(&philo->data->data_race[1]);
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