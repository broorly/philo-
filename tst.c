# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

long	ft_time(long start)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000 - start);
}

void	ft_usleep(long time)
{
	long	current_time;

	current_time = ft_time(0);
	usleep(time / 1000);
	while (ft_time(current_time) * 1000 < time)
		usleep(100);
}
int main()
{
	long time; 

	time = ft_time(0);
	ft_usleep(200 * 1000);
	printf("%ld\n", ft_time(time));
}


