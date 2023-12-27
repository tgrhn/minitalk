/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:00:15 by tkarakad          #+#    #+#             */
/*   Updated: 2023/11/25 12:00:46 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	bit_to_string(int signum)
{
	static int	bit_count = 0;
	static char	received_char = 0;

	received_char <<= 1;
	if (signum == SIGUSR2)
		received_char |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		write (1, &received_char, 1);
		received_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	ft_putstr("Server PID is: ");
	ft_putnbr(getpid());
	ft_putstr("Received message from the client is: ");
	while (1)
	{
		signal(SIGUSR1, bit_to_string);
		signal(SIGUSR2, bit_to_string);
		pause();
	}
	return (0);
}
