/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:05:58 by hmassonn          #+#    #+#             */
/*   Updated: 2021/06/12 19:26:56 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ping.h"

int			main(int ac, char **av)
{
	if (ac < 2 || (av[1][0] == '-' && av[1][1] == 'h'))
	{
		printf("Usage: %s [-hv] destination\n", av[0]);
		return (EXIT_FAILURE);
	}

    return 1;
}