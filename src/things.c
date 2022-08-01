#include"../philo.h"

void	eating(t_philo *philo)
{
	printf("philo %d is thinking\n",philo->id);
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	printf("philo %d has take the left fork  \n", philo->id);
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	printf("philo %d has take the right fork   %d\n", philo->id);
	printf("philo %d start eating\n", philo->id);
	philo->last_time_eating = ft_time(philo->data->current_time);
	ft_usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
}

void	sleeping(t_philo *philo)
{
		printf("philo %d is sleeping\n", philo->id);
		ft_usleep(philo->data->time_sleep * 1000);.
}
