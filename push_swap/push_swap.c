/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:37:40 by cristian          #+#    #+#             */
/*   Updated: 2024/07/10 05:28:42 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/ft_atoi.c"
#include "libft/ft_isdigit.c"
#include "libft/ft_strlen.c"

#ifndef PTR
# define PTR 0
#endif

#ifndef HEAD
# define HEAD 1
#endif

#ifndef PREV
# define PREV 2
#endif

#ifndef STK_A
# define STK_A 0
#endif

#ifndef STK_B
# define STK_B 1
#endif

#ifndef ORD
# define ORD 1
#endif

#ifndef ORDPOS
# define ORDPOS 2
#endif

typedef	struct s_node
{
	int		data;
	int		pos;
	struct s_node	*prev;	
	struct s_node	*next;	
} t_node;


int	ft_sign(int c)
{
	if (('0' <= c && c <= '9') || c == '-' || c == '+')
		return (1);
	return (0);
}
		
int	check_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (i == 0)
		{
			if (!ft_sign(argv[i]))
				return (0);
			if (ft_sign(argv[i]) && !ft_isdigit(argv[i + 1]))
				return (0);
		}
		else
		{
			if (!ft_isdigit(argv[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

t_node	*create_node(int data, int pos)
{
	t_node	*ptr;
	
	ptr = malloc(sizeof(t_node));
	if (ptr == NULL)
		return (NULL);
	ptr->data = data;
	ptr->pos = pos;
	ptr->prev = NULL;
	ptr->next = NULL;
	return (ptr);
}

t_node	*create_unique(int data, int pos)
{
	t_node	*ptr;
	
	ptr = malloc(sizeof(t_node));
	if (ptr == NULL)
		return (NULL);
	ptr->data = data;
	ptr->pos = pos;
	ptr->prev = ptr;
	ptr->next = ptr;
	return (ptr);
}

void	delete_node(t_node **head)
{
	t_node	*prev;
	t_node	*next;

	prev = (*head)->prev;
	next = (*head)->next;
	*head = (*head)->next;
	next->prev = prev;
	prev->next = next;
}

void	free_node_interrupt(t_node *head)
{
	t_node	*ptr;

	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}

void	free_nodes(t_node *head, int *num_nodes)
{
	t_node	*ptr;
	int		num;

	num = *num_nodes;

	while (num-- > 0)
	{
		ptr = head;
		head = head->next;
		free(ptr);
		(*num_nodes)--;
	}
}

void	set_null(t_node **ptr, t_node **head, t_node **prev, int *i)
{
	*i = 0;
	*ptr = NULL;
	*head = NULL;
	*prev = NULL;
}

void	set_prev(t_node **prev, t_node **ptr)
{
			(*prev)->next = *ptr;
			(*ptr)->prev = *prev;
}

int	check_dup(t_node *head, t_node *dup)
{
	t_node	*ptr;

	ptr = head;
	while (ptr != dup)
	{
		if (dup->data == ptr->data)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

t_node	*init_stack(int num, char **argv)
{
	int	i;
	t_node	*node[3];

	set_null(&node[PTR], &node[HEAD], &node[PREV], &i);
	while (num-- > 0)
	{
		if (check_arg(argv[++i]) == 0)
			return (free_node_interrupt(node[HEAD]), NULL); 
		node[PTR] = create_node(ft_atoi(argv[i]), i);
		if (node[PTR] == NULL)
			return (free_node_interrupt(node[HEAD]), NULL); 
		if (node[PREV])
			set_prev(&node[PREV], &node[PTR]);
		if (node[HEAD] == NULL)
			node[HEAD] = node[PTR];
		if (node[PREV] && !check_dup(node[HEAD], node[PTR]))
			return (free_node_interrupt(node[HEAD]), NULL); 
		node[PREV] = node[PTR];
		node[PTR] = node[PTR]->next;
	}
	node[HEAD]->prev = node[PREV];
	node[PREV]->next = node[HEAD];
	node[PTR] = node[HEAD];
	return (node[PTR]);
}

void	sa(t_node *head_a)
{
	t_node	*next;
	int	temp_pos;
	int	temp_data;

	if (head_a->next == head_a)
		return ;
	next = head_a->next;
	temp_data = head_a->data;
	temp_pos = head_a->pos;
	head_a->data = next->data;
	head_a->pos = next->pos;
	next->data = temp_data;
	next->pos = temp_pos;
	printf("sa\n");
}

void	sb(t_node *head_b)
{
	t_node	*next;
	int	temp_pos;
	int	temp_data;

	if (head_b->next == head_b)
		return ;
	next = head_b->next;
	temp_data = head_b->data;
	temp_pos = head_b->pos;
	head_b->data = next->data;
	head_b->pos = next->pos;
	next->data = temp_data;
	next->pos = temp_pos;
	printf("sb\n");
}

void	ss(t_node *head_a, t_node *head_b)
{
	sa(head_a);
	sb(head_b);
	printf("ss\n");
}

void	check_free(t_node *head_a, t_node *head_b, int nums[2])
{
	if (head_a != NULL)
		free_nodes(head_a, &nums[STK_A]);
	if (head_b != NULL)
		free_nodes(head_b, &nums[STK_B]);
}

void	pa(t_node **head_a, t_node **head_b, int nums[2])
{
	t_node	*prev;
	t_node	*next;

	if (nums[STK_A] < 1)
	{
		check_free(*head_a, *head_b, nums);
		return ;
	}
	if (*head_b == NULL)
		*head_b = create_unique((*head_a)->data, (*head_a)->pos);
	else
	{
		prev = (*head_b)->prev;
		next = (*head_b);
		(*head_b)->prev = create_node((*head_a)->data, (*head_a)->pos);
		*head_b = (*head_b)->prev;
		(*head_b)->prev = prev;
		(*head_b)->next = next;
		prev->next = *head_b;
	}
	delete_node(head_a);
	nums[STK_A]--;
	nums[STK_B]++;
	printf("pa\n");
}
	
void	pb(t_node **head_a, t_node **head_b, int nums[2])
{

	t_node	*prev;
	t_node	*next;

	if (nums[STK_B] < 1)
		return ;
	if (*head_a == NULL)
		*head_a = create_unique((*head_b)->data, (*head_b)->pos);
	else
	{
		prev = (*head_a)->prev;
		next = (*head_a);
		(*head_a)->prev = create_node((*head_b)->data, (*head_b)->pos);
		*head_a = (*head_a)->prev;
		(*head_a)->prev = prev;
		(*head_a)->next = next;
		prev->next = *head_a;
	}
	delete_node(head_b);
	nums[STK_B]--;
	nums[STK_A]++;
	printf("pb\n");
}

void	ra(t_node **head_a)
{
	*head_a = (*head_a)->next;
	printf("ra\n");
}

void	rb(t_node **head_b)
{
	*head_b = (*head_b)->next;
	printf("rb\n");
}

void	rr(t_node **head_a, t_node **head_b)
{
	ra(head_a);
	rb(head_b);
	printf("rr\n");
}

void	rra(t_node **head_a)
{
	*head_a = (*head_a)->prev;
	printf("rra\n");
}

void	rrb(t_node **head_b)
{
	*head_b = (*head_b)->prev;
	printf("rrb\n");
}

void	rrr(t_node **head_a, t_node **head_b)
{
	rra(head_a);
	rrb(head_b);
	printf("rrr\n");
}

void	push_two(t_node **head_a, t_node **head_b, int num_nodes[2])
{
	int	temp;
	int	less;

	less = num_nodes[STK_A] - 2;
	while (num_nodes[STK_A] > less)
	{
		pa(head_a, head_b, num_nodes);
		temp = num_nodes[STK_A];
		while (temp-- > 0)
		{
			printf("A: %d: %d\n", (*head_a)->pos, (*head_a)->data);
			(*head_a) = (*head_a)->next;
		}
		temp = num_nodes[STK_B];
		while (temp-- > 0)
		{
			printf("B: %d: %d\n", (*head_b)->pos, (*head_b)->data);
			(*head_b) = (*head_b)->next;
		}
	}
	printf("head A: %d\n", (*head_a)->data);
	printf("head B: %d\n", (*head_b)->data);
}

t_node	*get_min(t_node *stack)
{
	t_node	*head;
	t_node	*min_node;

	head = stack;
	min_node = stack;
	stack  = stack->next;
	while (stack != head)
	{
		if (stack->data < min_node->data)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

int	ordered(t_node *stack, t_node *min_node)
{
	t_node	*ptr;
	int	disc;
	
	disc = 0;
	ptr = min_node->next;
	while (ptr != min_node)
	{
		if (ptr->data < ptr->prev->data)
			disc++;
		ptr = ptr->next;
	}
	if (disc > 0)
		return (-disc);
	if (min_node == stack)
		return (2);
	else
		return (1);
}

int	choose_rotation(t_node **stk_a, t_node *min_node)
{
	t_node	*ptr;
	int	dir;
	int	rev;

	dir = 0;
	rev = 0;
	ptr = *stk_a;
	while (ptr->data != min_node->data)
	{
		ptr = ptr->next;
		dir++;
	}
	ptr = *stk_a;
	while (ptr->data != min_node->data)
	{
		ptr = ptr->prev;
		rev++;
	}
	if (dir <= rev)
		return (dir);
	else
		return (-rev);
}

void	mult_rots(void (*sort)(t_node **stack), t_node **stk_a, int times)
{
	while (times-- > 0)
		sort(stk_a);
}

void	two_sort(t_node **stk_a)
{
	int	temp;
	t_node	*ptr;

	ptr = *stk_a;
	temp = ptr->data;
	ptr = ptr->next;
	if (temp > ptr->data)
		sa(*stk_a);
	temp = 2;
	while (temp-- > 0)
		*stk_a = (*stk_a)->next;
}

void	three_sort(t_node **stk_a)
{
	t_node	*ptr;
	t_node	*min_node;
	int	order;
	int	rot;

	ptr = *stk_a;
	min_node = get_min(ptr);
	order = ordered(ptr, min_node);
	if (order == ORDPOS)
		return ;
	if (order == ORD)
	{
		rot = choose_rotation(stk_a, min_node);
		if (rot > 0)
			mult_rots(ra, stk_a, rot);
		else if (rot < 0)
			mult_rots(rra, stk_a, -rot);
	}
	if (order <= 0)
	{
		sa(*stk_a);
		three_sort(stk_a);
	}
		
}
	

//void	four_sort(t_node **stk_a, t_node **stk_b, int num_nodes[2])
//{
//	return ;
//}
//void	five_sort(t_node **stk_a, t_node **stk_b, int num_nodes[2])
//{
//	return ;
//}

void	manual_sort(t_node **stk_a, t_node **stk_b, int num_nodes[2])
{
	if (*stk_b == NULL)
		num_nodes[STK_B] = 0;
	if (num_nodes[STK_A] == 1)
		return ;
	else if (num_nodes[STK_A] == 2)
		two_sort(stk_a);
	else if (num_nodes[STK_A] == 3)
		three_sort(stk_a);
//	else if (num_nodes[STK_A] == 4)
//		four_sort(stk_a, stk_b, num_nodes);
//	else if (num_nodes[STK_A] == 5)
//		five_sort(stk_a, stk_b, num_nodes);
}

//int	best_move(t_node *stk_a, t_node *stk_b, int num_nodes[2])
//{
//	int	temp;
//
//	temp = num_nodes[STK_A];
//	
//	while (temp-- > 0)
//	{
//		
//}

//void	turk_sort(t_node **stk_a, t_node **stk_b, int num_nodes[2])
//{
//	int	temp;
//	int	*moves;
	
//	temp = num_nodes[STK_A];
//	push_two(stk_a, stk_b, num_nodes);
//	while (num_nodes[STK_A] > 3)
	//{
//		best_move();
//}
int	main(int argc, char **argv)
{

	t_node	*stk_a;
	t_node	*stk_b;
	int	num_nodes[2];

	if (argc < 2)
		return ((void)printf("Error\n"), 0);
	num_nodes[STK_A] = argc - 1;
	num_nodes[STK_B] = 0;
	stk_a = NULL;
	stk_a = init_stack(num_nodes[STK_A], argv);
	if (stk_a == NULL)
		return ((void)printf("Error\n"), 0);
	stk_b = NULL;
	//para turkish_sort
	if (num_nodes[STK_A] + num_nodes[STK_B] != argc -1)
		return ((void)printf("Error\n"), 0);
	if (num_nodes[STK_A] < 6)
		manual_sort(&stk_a, &stk_b, num_nodes);
	else
		//turk_sort(&stk_a, &stk_b, num_nodes);
	//temp = num_nodes[STK_A];
	//while (temp-- > 0)
	//{
	//	printf("A: data in pos %d: %d\n", stk_a->pos, stk_a->data);
	//	stk_a = stk_a->next;
	//}
	//temp = num_nodes[STK_B];
	//while (temp-- > 0)
	//{
	//	printf("B: data in pos %d: %d\n", stk_b->pos, stk_b->data);
	//	stk_b = stk_b->next;
	//}
	//temp = num_nodes[STK_A];
	//while (temp-- > 0)
	//{
	//	stk_a = stk_a->prev;
	//	printf("data in pos %d: %d\n", stk_a->pos, stk_a->data);
	//}
	return (0);
}
