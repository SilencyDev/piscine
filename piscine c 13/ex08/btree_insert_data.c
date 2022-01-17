/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:08:04 by kmacquet          #+#    #+#             */
/*   Updated: 2021/09/02 14:07:29 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rb_node.h"

t_rb_node	*btree_insert_data(t_rb_node **root, void *item, int(*cmpf)(void *, void *))
{
	if (!(*root))
	{
		*root = btree_create_node(item, NULL);
		return (NULL);
	}
	if (cmpf(item, (*root)->item) < 0)
	{
		if ((*root)->left)
			btree_insert_data(&(*root)->left, item, cmpf);
		else
			return ((*root)->left = btree_create_node(item, *root));
	}
	else
	{
		if ((*root)->right)
			btree_insert_data(&(*root)->right, item, cmpf);
		else
			return ((*root)->right = btree_create_node(item, *root));
	}
}