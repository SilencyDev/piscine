/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:08:04 by kmacquet          #+#    #+#             */
/*   Updated: 2021/08/31 15:02:42 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	apply(t_btree *root, int init_level, int level, int *first ,void (*applyf)(void*item, int current_level, int is_first_elem))
{
	if (!root)
		return ;
	if (level == 0)
	{
		if (*first)
			applyf(root->item, init_level, *first = 0);
		else
			applyf(root->item, init_level, *first);
	}
	else if (level > 0)
	{
		apply(root->left, init_level, level - 1, first, applyf);
		apply(root->right, init_level, level - 1, first, applyf);
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void*item, int current_level, int is_first_elem))
{
	int	i = 0;
	int	size = btree_level_count(root);
	int first = 1;

	while (i < size)
	{
		apply(root, i, i, &first, applyf);
		first = 1;
		i++;
	}
}