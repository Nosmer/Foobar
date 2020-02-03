/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:47:14 by bconsuel          #+#    #+#             */
/*   Updated: 2020/02/03 13:52:35 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	proc_signal_handler(int	signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		signal(SIGINT, proc_signal_handler);
	}
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		write(1, "$> ", 3);
		signal(SIGINT, signal_handler);
	}
}
