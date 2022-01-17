/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:39:25 by kmacquet          #+#    #+#             */
/*   Updated: 2021/09/02 10:54:20 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rb_node.h"

t_rb_node *btree_create_node(void *item, t_rb_node *parent)
{
	t_rb_node *node;
	
	node = malloc(sizeof(t_rb_node));
	if (!node)
		return (NULL);
	node->item = item;
	node->right = 0;
	node->left = 0;
	node->parent = parent;
	node->color = RB_RED;
	return (node);
}