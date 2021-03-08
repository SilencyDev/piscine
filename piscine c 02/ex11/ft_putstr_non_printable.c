/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:42:22 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/13 13:58:58 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void		ft_putstr_non_printable(char *str)
{
	unsigned int i;

	i = 0;
	while ((unsigned int)str[i])
	{
		if ((unsigned int)str[i] < ' ' || str[i] > 126)
		{
			ft_putchar('\\');
			ft_putnbr(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
