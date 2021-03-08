/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:31:24 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/14 20:41:56 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	o;

	i = ft_strlen(dest);
	if (size < i)
		k = i + size;
	else
		k = i + ft_strlen(src);
	if (size > 0)
	{
		o = 0;
		while (src[o] && size > i - 1)
		{
			dest[i] = src[o];
			size--;
			i++;
			o++;
		}
		dest[i] = '\0';
	}
	return (k);
}
