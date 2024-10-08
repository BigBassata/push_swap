/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:12:21 by user              #+#    #+#             */
/*   Updated: 2024/09/02 18:27:35 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error_mess_print(void)
{
	write(2, "Error\n", 6);
}

void	ft_free_chainedlst(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_free_lst(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_free_lst(t_list *lst)
{
	if (!lst)
		return ;
	free(lst->content);
	free(lst);
}

t_list	*ft_before_last_lst(t_list *lst)
{
	t_list	*bfll;

	bfll = NULL;
	while (lst->next)
	{
		bfll = lst;
		lst = lst->next;
	}
	return (bfll);
}

int	ft_stack_a_sort_check(t_stack *stack_a)
{
	t_list	*lst;

	lst = stack_a->top;
	if (!lst || !lst->next)
		return (1);
	while (lst->next)
	{
		if (*(int *)(lst->content) > *(int *)(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}
