/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:46 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/17 19:27:31 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void display_list(t_stack *a)
{
	while(a)
	{
		printf("%d ", a->content);
		a = a->next;
	}
	printf("\n");
}

int get_arg(char **v, t_stack **stack)
{
	char	**buf;
	int		i;

	i = 1;
	if (!v)
		return(0);
	while (v[i])
	{
		buf = ft_split(v[i], ' ');
		if (!buf)
			return (1);
		check_nbr(buf, stack);
		i++;
	}
	free_t_split(buf);
	return (0);
}

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	
	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	get_arg(av, &a);
	if(is_sorted(a))
		return (0);
	//-----------------------------
	printf("Init a and b:\n");
	printf("a : ");
	display_list(a);
	printf("b : ");
	display_list(b);
	//------------------------------
	printf("Exec sa: \n");
	sa(&a, 1);
	printf("a : ");
	display_list(a);
	printf("b : ");
	display_list(b);
	//------------------------------------
	printf("Exec pb pb pb: \n");
	pb(&a, &b, 1);
	pb(&a, &b, 1);
	pb(&a, &b, 1);

	printf("a : ");
	display_list(a);
	printf("b : ");
	display_list(b);
	//--------------------------------
	printf("Exec ra rb (equiv. to rr): \n");
	rr(&a, &b, 1);
	printf("a : ");
	display_list(a);
	printf("b : ");
	display_list(b);
		//--------------------------------
	printf("Exec rra rrb (equiv. to rrr): \n");
	rrr(&a, &b, 1);
	printf("a : ");
	display_list(a);
	printf("b : ");
	display_list(b);
		//------------------------------
	printf("Exec sa: \n");
	sa(&a, 1);
	printf("a : ");
	display_list(a);
	printf("b : ");
	display_list(b);
//------------------------------------
	printf("Exec pa pa pa: \n");
	pa(&a, &b, 1);
	pa(&a, &b, 1);
	pa(&a, &b, 1);

	printf("a : ");
	display_list(a);
	printf("b : ");
	display_list(b);
	// algorithme(&a);
	return 0;
}
