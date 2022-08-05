/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:15:19 by mrafik            #+#    #+#             */
/*   Updated: 2022/08/05 16:17:06 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data || argc < 5 || argc > 6)
	{
		printf("nn hh \n");
		return (0);
	}
	if (!v_init(data, argc, argv))
		return (0);
	philo = (t_philo *) malloc(sizeof(t_philo) * data->number);
	if (!philo)
		return (0);
	philo_init(data, philo);
	threads(philo);
	while (1)
	{
		if (killer(philo, data))
			return (0);
	}
	return (0);
}
