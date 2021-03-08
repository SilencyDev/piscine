/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:49:28 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/11 19:15:23 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strupcase(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}