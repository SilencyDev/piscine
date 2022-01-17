/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:39:25 by kmacquet          #+#    #+#             */
/*   Updated: 2021/08/27 17:35:46 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
	t_btree *node;
	
	node = malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->item = item;
	node->right = 0;
	node->left = 0;
	return (node);
}