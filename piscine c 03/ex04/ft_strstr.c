/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:42:16 by kmacquet          #+#    #+#             */
/*   Updated: 2021/01/23 12:11:20 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	k;
	char			*str_init;

	str_init = str;
	i = 0;
	k = 0;
	if (*to_find == '\0')
		return (str_init);
	while (to_find[k])
		k++;
	while (*str)
	{
		while (str[i] == to_find[i])
		{
			if ((i + 1) == k)
				return (str);
			i++;
		}
		i = 0;
		str++;
	}
	return (0);
}
