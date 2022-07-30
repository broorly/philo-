#include"../philo.h"

void	eating(t_philo *philo)
{
	printf("philo %d is thinking",philo->id);
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	printf("philo %d has take the left fork", philo->id);
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	printf("philo %d has take the right fork", philo->id);
	printf("philo %d start eating", philo->id);
	ft_time(philo->data->current_time);
	philo->last_time_eating = ft_time(philo->data->current_time);
	ft_usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
}

void	sleeping(t_philo *philo)
{
		printf("philo %d is sleeping", philo->id);
		ft_usleep(philo->data->time_sleep * 1000);
}
