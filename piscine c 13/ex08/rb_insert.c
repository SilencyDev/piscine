/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:08:04 by kmacquet          #+#    #+#             */
/*   Updated: 2021/09/02 14:12:09 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rb_node.h"

t_rb_node	*get_sibling(t_rb_node *root)
{
	if (!root || !root->parent)
		return (NULL);
	if (root->parent->left != root)
		return (root->parent->left);
	else if (root->parent->right != root)
		return (root->parent->right);
}

t_rb_node	*get_uncle(t_rb_node *root)
{
	if (!root || !root->parent || !root->parent->parent)
		return (NULL);
	if (root->parent->parent->left != root->parent)
		return (root->parent->parent->left);
	else if (root->parent->parent->right != root->parent)
		return (root->parent->parent->right);
}

void	left_rotate(t_rb_node *node)
{
	t_rb_node *tmp;
	
	if (!node || !node->parent)
		return ;
	tmp = node->parent->parent;
	node->parent->parent = node;
	node->parent->right = node->left;
	node->left = node->parent;
	node->parent = tmp;
}

void	right_rotate(t_rb_node *node)
{
	t_rb_node *tmp;
	
	if (!node || !node->parent)
		return ;
	tmp = node->parent->parent;
	node->parent->parent = node;
	node->parent->right = node->right;
	node->right = node->parent;
	node->parent = tmp;
}

void	rb_insert_fix(t_rb_node **root, t_rb_node *node)
{
	if ((*root)->color = RB_RED); // case 0
		(*root)->color = RB_BLACK;
}

void	rb_insert(t_rb_node **root, void *item, int(*cmpf)(void *,void *)) 
{
	rb_insert_fix(root, btree_insert_data(root, item, cmpf));
}