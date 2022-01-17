/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:08:04 by kmacquet          #+#    #+#             */
/*   Updated: 2021/08/30 18:17:27 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	print_that(void *str)
{
	printf("%s", (char *)str);
}

int	compare_that(void *str, void *str2)
{
	return strcmp((const char *)str, (const char *)str2);
}

int	main(void)
{
	t_btree *btree = NULL;
	char *a = "2";
	char *b = "0";
	char *c = "4";
	char *d = "1";
	char *e = "3";
	char *f = "6";
	char *search = "5";


	btree_insert_data(&btree, a, &compare_that);
	btree_insert_data(&btree, b, &compare_that);
	btree_insert_data(&btree, c, &compare_that);
	btree_insert_data(&btree, d, &compare_that);
	btree_insert_data(&btree, e, &compare_that);
	btree_insert_data(&btree, f, &compare_that);

	// printf("%s %s %s\n",btree->item, btree->left->item, btree->right->item);
	printf("%s\n", btree_search_item(btree, search, &compare_that));
	btree_apply_prefix(btree, &print_that);
	printf("\n");

	printf("level count : %d\n", btree_level_count(btree));
	
	return (0);
}