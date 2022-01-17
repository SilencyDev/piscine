/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:08:04 by kmacquet          #+#    #+#             */
/*   Updated: 2021/09/01 15:18:37 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rb_node.h"

int	btree_level_count(t_rb_node *root)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	else
	{
		left = btree_level_count(root->left);
		right = btree_level_count(root->right);
		if (left > right)
			return (left + 1);
		else
			return (right + 1);
	}
}