/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:08:04 by kmacquet          #+#    #+#             */
/*   Updated: 2021/08/30 17:07:53 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	print_that(void *str)
{
	printf("%s", (char *)str);
}

int	main(void)
{
	t_btree *btree = NULL;
	char *a = "2";
	char *b = "0";
	char *c = "4";
	char *d = "1";
	char *e = "3";


	btree_insert_data(&btree, a, &strcmp);
	btree_insert_data(&btree, b, &strcmp);
	btree_insert_data(&btree, c, &strcmp);
	btree_insert_data(&btree, d, &strcmp);
	btree_insert_data(&btree, e, &strcmp);

	// printf("%s %s %s\n",btree->item, btree->left->item, btree->right->item);
	btree_apply_prefix(btree, &print_that);
	
	return (0);
}