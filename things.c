#include"philo.h"

void	eating(t_philo *philo)
{
	printf("philo %d is thinking");
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	printf("philo %d has take the left fork", philo->id);
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	printf("philo %d has take the left fork", philo->id);
	printf("philo %d start eating", philo->id);
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
}

void	sleeping(t_philo *philo)
{
		printf("philo %d is sleeping");
		ft_usleep(philo->data->time_sleep * 1000);
}

// int	dead(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->data->display);
// 	pthread_mutex_lock(&philo->data->data_race[1]);
// 	philo->data->is_dead = 1;
// 	pthread_mutex_unlock(&philo->data->data_race[1]);
// 	printf("%ld | philo %d dead \n",
// 		ft_time(philo->data->current_time), philo->id);
// 	return (0);
// }