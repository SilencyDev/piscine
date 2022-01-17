/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_node.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:39:19 by kmacquet          #+#    #+#             */
/*   Updated: 2021/08/31 16:21:55 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_NODE_H
# define FT_RB_NODE_H
# include <stdio.h>
# include <stdlib.h>
# include "string.h"

enum	e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef struct	s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	void				*item;
	enum e_rb_color		color;
}				t_rb_node;

t_rb_node	*btree_create_node(void *item, t_rb_node *parent);
void	btree_apply_prefix(t_rb_node *root, void (*applyf)(void *));
void	btree_apply_infix(t_rb_node *root, void (*applyf)(void *));
void	btree_apply_suffix(t_rb_node *root, void (*applyf)(void *));
t_rb_node	*btree_insert_data(t_rb_node **root, void *item, int(*cmpf)(void *, void *));
void	*btree_search_item(t_rb_node *root, void *data_ref, int(*cmpf)(void *, void *));
int		btree_level_count(t_rb_node *root);
void	btree_apply_by_level(t_rb_node *root,void(*applyf)(void*item,int current_level,int is_first_elem));
void	rb_insert(struct s_rb_node **root, void*item, int(*cmpf)(void *,void *));

#endif