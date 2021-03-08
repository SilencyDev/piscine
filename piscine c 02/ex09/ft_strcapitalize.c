/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 22:40:51 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/12 11:32:20 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcapitalize(char *str)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	j = i;
	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (i <= j)
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
				&& !((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				|| (str[i - 1] >= '0' && str[i - 1] <= '9')
				|| (str[i - 1] >= 'a' && str[i - 1] <= 'z')))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
