/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:36:51 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/19 20:59:45 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

int				check_base(char *str, int baselen)
{
	int		j;
	char	ref[255];

	j = 0;
	if (str[j] == '\0')
		return (0);
	while (str[j])
	{
		if (str[j] == '-' || str[j] == '+' || baselen < 2)
			return (0);
		if (ref[(int)str[j]])
			return (0);
		ref[(int)str[j]] = 1;
		j++;
	}
	return (1);
}

int				ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			ft_putnbr(long int nb, char *str, int baselen)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == baselen)
	{
		ft_putchar(str[1]);
	}
	if (nb > baselen)
		ft_putnbr((nb / baselen), str, baselen);
	ft_putchar(str[nb % baselen]);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int			baselen;
	long int	longnbr;

	longnbr = (long int)nbr;
	if (!check_base(base, ft_strlen(base)))
		;
	else
	{
		baselen = ft_strlen(base);
		ft_putnbr(longnbr, base, baselen);
	}
}
