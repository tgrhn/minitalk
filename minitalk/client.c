/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:00:02 by tkarakad          #+#    #+#             */
/*   Updated: 2023/11/25 12:00:04 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	send_char(pid_t pid, char character)
{
	int	i;
	int	bit;

	i = 7;
	bit = 0;
	while (i >= 0)
	{
		bit = (character >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(100);
	}
}

void	send_string(pid_t pid, const char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
}

void	print_error(void)
{
	ft_putstr("You must write ./client [server_pid] [message]\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t		server_pid;
	const char	*msg;

	if (argc != 3)
	{
		print_error();
	}
	server_pid = ft_atoi(argv[1]);
	msg = argv[2];
	send_string(server_pid, msg);
	return (0);
}
