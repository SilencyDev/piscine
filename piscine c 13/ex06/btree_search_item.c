/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:08:04 by kmacquet          #+#    #+#             */
/*   Updated: 2021/08/30 17:44:10 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void*data_ref, int(*cmpf)(void*,void*))
{
	void *ret = NULL;
	
	if (!root)
		return (NULL);
	ret = btree_search_item(root->left, data_ref, cmpf);
	if (!ret && !cmpf(data_ref, root->item))
		return (root->item);
	if (!ret)
		ret = btree_search_item(root->right, data_ref, cmpf);
	return (ret);
}