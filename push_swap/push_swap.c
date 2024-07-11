/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:37:40 by cristian          #+#    #+#             */
/*   Updated: 2024/07/11 19:15:59 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/ft_atoi.c"
#include "libft/ft_isdigit.c"
#include "libft/ft_bzero.c"
#include "libft/ft_calloc.c"
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
			if ((argv[i] == '-' || argv[i] == '+') 
				&& !ft_isdigit(argv[i + 1]))
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

t_node	*create_node(int data)
{
	t_node	*ptr;
	
	ptr = malloc(sizeof(t_node));
	if (ptr == NULL)
		return (NULL);
	ptr->data = data;
	ptr->prev = NULL;
	ptr->next = NULL;
	return (ptr);
}

t_node	*create_unique(int data)
{
	t_node	*ptr;
	
	ptr = malloc(sizeof(t_node));
	if (ptr == NULL)
		return (NULL);
	ptr->data = data;
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
		node[PTR] = create_node(ft_atoi(argv[i]));
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

void	print_stack(t_node **stack)
{
	t_node	*head;
	t_node	*ptr;

	if (*stack == NULL)
		return ((void)printf("NULL\n"));
	head = *stack;
	printf("%d\n", head->data);
	ptr = head->next;
	while (ptr != head)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}

void	sa(t_node *head_a)
{
	t_node	*next;
	int	temp_data;

	if (head_a->next == head_a)
		return ;
	next = head_a->next;
	temp_data = head_a->data;
	head_a->data = next->data;
	next->data = temp_data;
	printf("sa\n");
}

void	sb(t_node *head_b)
{
	t_node	*next;
	int	temp_data;

	if (head_b->next == head_b)
		return ;
	next = head_b->next;
	temp_data = head_b->data;
	head_b->data = next->data;
	next->data = temp_data;
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
		*head_b = create_unique((*head_a)->data);
	else
	{
		prev = (*head_b)->prev;
		next = (*head_b);
		(*head_b)->prev = create_node((*head_a)->data);
		*head_b = (*head_b)->prev;
		(*head_b)->prev = prev;
		(*head_b)->next = next;
		prev->next = *head_b;
	}
	delete_node(head_a);
	nums[STK_A]--;
	nums[STK_B]++;
	if (nums[STK_A] == 0)
		*head_a = NULL;
	printf("pa\n");
}
	
void	pb(t_node **head_a, t_node **head_b, int nums[2])
{

	t_node	*prev;
	t_node	*next;

	if (nums[STK_B] < 1)
		return ;
	if (*head_a == NULL)
		*head_a = create_unique((*head_b)->data);
	else
	{
		prev = (*head_a)->prev;
		next = (*head_a);
		(*head_a)->prev = create_node((*head_b)->data);
		*head_a = (*head_a)->prev;
		(*head_a)->prev = prev;
		(*head_a)->next = next;
		prev->next = *head_a;
	}
	delete_node(head_b);
	nums[STK_B]--;
	nums[STK_A]++;
	if (nums[STK_B] == 0)
		*head_b = NULL;
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
			printf("A: %d\n", (*head_a)->data);
			(*head_a) = (*head_a)->next;
		}
		temp = num_nodes[STK_B];
		while (temp-- > 0)
		{
			printf("B: %d\n", (*head_b)->data);
			(*head_b) = (*head_b)->next;
		}
	}
	printf("head A: %d\n", (*head_a)->data);
	printf("head B: %d\n", (*head_b)->data);
}

int	same_sign(int n1, int n2)
{
	if (n1 < 0 && n2 < 0)
		return (1);
	else if (n1 > 0 && n2 > 0)
		return (1);
	return (0);
}

int	is_min(int num, t_node *stack)
{
	t_node	*head;

	head = stack;
	if (stack->data < num)
		return (0);
	stack  = stack->next;
	while (stack != head)
	{
		if (stack->data < num)
			return (0);
		stack = stack->next;
	}
	return (1);
	
}

int	is_max(int num, t_node *stack)
{
	t_node	*head;

	head = stack;
	if (stack->data > num)
		return (0);
	stack  = stack->next;
	while (stack != head)
	{
		if (stack->data > num)
			return (0);
		stack = stack->next;
	}
	return (1);
	
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

t_node	*get_max(t_node *stack)
{
	t_node	*head;
	t_node	*max_node;

	head = stack;
	max_node = stack;
	stack  = stack->next;
	while (stack != head)
	{
		if (stack->data > max_node->data)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

int	calc_least(int	movs_a, int movs_b)
{
	int	sim;

	sim = 0;
	printf("mova: %d, movb: %d, sim: %d\n", movs_a, movs_b, sim);
	if(movs_a > 0 && movs_b > 0)
	{
		while (movs_a > 0 && movs_b > 0)
		{
			movs_a--;
			movs_b--;
			sim++;
		}
	}
	if(movs_a < 0 && movs_b < 0)
	{
		while (movs_a < 0 && movs_b < 0)
		{
			movs_a++;
			movs_b++;
			sim++;
		}
	}
	printf("mova: %d, movb: %d, sim: %d\n", movs_a, movs_b, sim);
	return (sim + abs(movs_a) + abs(movs_b));	
}

int	ordered(t_node *stack, t_node *min_node)
{
	t_node	*ptr;
	
	ptr = min_node->next;
	while (ptr != min_node)
	{
		if (ptr->data < ptr->prev->data)
			return (0);
		ptr = ptr->next;
	}
	if (min_node == stack)
		return (2);
	else
		return (1);
}

int	choose_rotation(t_node **stk_a, t_node *node)
{
	t_node	*ptr;
	int	dir;
	int	rev;

	dir = 0;
	rev = 0;
	ptr = *stk_a;
	printf("stack data: %d\n", ptr->data);
	printf("node data: %d\n", node->data);
	if (node->data == ptr->data)
		printf("DA LO MISMO ME CAGO EN DIOS\n");
	while (ptr->data != node->data)
	{
		ptr = ptr->next;
		dir++;
	}
	ptr = *stk_a;
	while (ptr->data != node->data)
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

void	trot(void (*s)(t_node **a, t_node **b), t_node **x, t_node **y, int *t)
{
	if (t[STK_A] < 0 && t[STK_B] < 0)
	{
		while (t[STK_B] < 0 && t[STK_A] < 0)
		{
			t[STK_A]++;
			t[STK_B]++;
			s(x, y);
		}
	}
	if (t[STK_A] > 0 && t[STK_B] > 0)
	{
		while (t[STK_B] > 0 && t[STK_A] > 0)
		{
			t[STK_A]--;
			t[STK_B]--;
			s(x, y);
		}
	}
}

int	initially_ordered(t_node **stk_a)
{
	t_node	*ptr;
	t_node	*min_node;
	int	order;
	int	rot;

	ptr = *stk_a;
	min_node = get_min(ptr);
	order = ordered(ptr, min_node);
	if (order == ORDPOS)
		return (order);
	if (order == ORD)
	{
		rot = choose_rotation(stk_a, min_node);
		if (rot > 0)
			mult_rots(ra, stk_a, rot);
		else if (rot < 0)
			mult_rots(rra, stk_a, -rot);
		return (order);
	}
	return (order);
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
		return ;
	}
	if (!order)
	{
		sa(*stk_a);
		three_sort(stk_a);
	}
		
}
	
void	manual_sort(t_node **stk_a, int num_nodes[2])
{
	if (num_nodes[STK_A] == 1)
		return ;
	else if (num_nodes[STK_A] == 2)
		two_sort(stk_a);
	else if (num_nodes[STK_A] == 3)
		three_sort(stk_a);
}

int	choose_btween(t_node **stk_b, t_node *node)
{
	int	dir;
	int	rev;
	t_node	*b;

	dir = 0;
	rev = 0;
	b = *stk_b;
	while (!(b->data < node->data) || !(b->prev->data > node->data))
	{
		b = b->next;
		dir++;
		printf("dir es: %d\n", dir);
	}
	printf("va despues de: %d\n", b->prev->data);
	printf("va antes de: %d\n", b->data);
	b = *stk_b;
	while (!(b->data < node->data) || !(b->prev->data > node->data))
	{
		b = b->prev;
		rev++;
		printf("rev es: %d\n", rev);
	}
	printf("va despues de: %d\n", b->prev->data);
	printf("va antes de: %d\n", b->data);
	if (dir < rev)
		return (dir);
	else
		return (-rev);
}

int	get_btween(t_node **stk_b, t_node *node)
{
	t_node	*b;
	int	b_moves;
	t_node	*val;

	b = *stk_b;
	b_moves = 0;
	val = NULL;
	if (is_min(node->data, b)) 
	{
		printf("ES MIN\n");
		val = get_min(b)->next;
		printf("va despues de: %d\n", val->prev->data);
		printf("va antes de: %d\n", val->data);
	}
	else if (is_max(node->data, b))
	{
		printf("ES MAX\n");
		val = get_max(b);
		printf("va despues de: %d\n", val->prev->data);
		printf("va antes de: %d\n", val->data);
	}
	if (val)
	{
		printf("entra siendo min o max\n");
		b_moves = choose_rotation(stk_b, val);
		printf("b_moves con val %d\n",  b_moves);
	}
	else
	{
		printf("entra sin ser min o max\n");
		b_moves  = choose_btween(stk_b, node);
		printf("b_moves normal %d\n",  b_moves);
	}
	printf("b_moves final es: %d\n",  b_moves);
	return (b_moves);
}

int	choose_btween_ordered(t_node **stk_a, t_node *node)
{
	int	dir;
	int	rev;
	t_node	*a;

	dir = 0;
	rev = 0;
	a = *stk_a;
	while (!(a->data > node->data) || !(a->prev->data < node->data))
	{
		a = a->next;
		dir++;
		printf("dir es: %d\n", dir);
	}
	printf("va despues de: %d\n", a->prev->data);
	printf("va antes de: %d\n", a->data);
	a = *stk_a;
	while (!(a->data > node->data) || !(a->prev->data < node->data))
	{
		a = a->prev;
		rev++;
		printf("rev es: %d\n", rev);
	}
	printf("va despues de: %d\n", a->prev->data);
	printf("va antes de: %d\n", a->data);
	if (dir < rev)
		return (dir);
	else
		return (-rev);
}

int	get_btween_ordered(t_node **stk_a, t_node *node)
{
	t_node	*a;
	int	a_moves;
	t_node	*val;

	a = *stk_a;
	a_moves = 0;
	val = NULL;
	if (is_min(node->data, a)) 
	{
		printf("ES MIN\n");
		val = get_min(a);
		printf("va despues de: %d\n", val->prev->data);
		printf("va antes de: %d\n", val->data);
	}
	else if (is_max(node->data, a))
	{
		printf("ES MAX\n");
		val = get_max(a)->next;
		printf("va despues de: %d\n", val->prev->data);
		printf("va antes de: %d\n", val->data);
	}
	if (val)
	{
		printf("entra siendo min o max\n");
		a_moves = choose_rotation(stk_a, val);
		printf("a_moves con val %d\n",  a_moves);
	}
	else
	{
		printf("entra sin ser min o max\n");
		a_moves  = choose_btween_ordered(stk_a, node);
		printf("a_moves normal %d\n",  a_moves);
	}
	printf("a_moves final es: %d\n",  a_moves);
	return (a_moves);
}

int	abs(int	num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	*best_push(t_node **stk_a, t_node **stk_b, int num_nodes[2])
{
	int	least;
	int	temp;
	int	moves[2];
	int	*best;
	t_node	*node;

	temp = num_nodes[STK_A];
	node = *stk_a;
	best = ft_calloc(2, sizeof(int));
	least = -1;
	while (temp-- > 0)
	{
		printf("\nstk_a: %d nodo:%d\n", (*stk_a)->data, node->data);
		moves[STK_A] = choose_rotation(stk_a, node);
		printf("moves a: %d\n", moves[STK_A]);
		moves[STK_B] = get_btween(stk_b, node);
		printf("moves b: %d\n", moves[STK_B]);
		node = node->next;
		if (least < 0)
		{
			least = calc_least(moves[STK_A], moves[STK_B]);
			printf("entra con least:%d\n", least);
			best[STK_A] = moves[STK_A];
			best[STK_B] = moves[STK_B];
			printf("best a:%d\n", best[STK_A]);
			printf("best b:%d\n", best[STK_B]);
		}
		if (calc_least(moves[STK_A], moves[STK_B]) < least)
		{
			
			least = calc_least(moves[STK_A], moves[STK_B]);
			printf("entra con least:%d\n", least);
			best[STK_A] = moves[STK_A];
			best[STK_B] = moves[STK_B];
			printf("best a:%d\n", best[STK_A]);
			printf("best b:%d\n", best[STK_B]);
		}
	}
	printf("sale con least:%d\n", least);
	return (best);
}

void	sim_cases(int opt[2], t_node **stk_a, t_node **stk_b)
{
	if (opt[STK_A] > 0 && opt[STK_B] > 0)
	{
		trot(rr, stk_a, stk_b, opt);
		return ;
	}
	if (opt[STK_A] < 0 && opt[STK_B] < 0)
	{
		trot(rrr, stk_a, stk_b, opt);
		return ;
	}
}

void	rem_rots(int opt[2], t_node **stk_a, t_node **stk_b)
{
		if (opt[STK_A])
		{
		if (opt[STK_A] > 0)
			mult_rots(ra, stk_a, opt[STK_A]);
		else if (opt[STK_A] < 0) 
			mult_rots(rra, stk_a, -opt[STK_A]);
		}
		if (opt[STK_B])
		{
		if (opt[STK_B] > 0)
			mult_rots(rb, stk_b, opt[STK_B]);
		else if (opt[STK_B] < 0)
			mult_rots(rrb, stk_b, -opt[STK_B]);
		}
}

void	order_list(t_node **stk_a, t_node **stk_b, int num_nodes[2])
{
	int	rot;
	t_node	*min_node;

	while (num_nodes[STK_B] > 0)
	{
		rot = get_btween_ordered(stk_a, *stk_b);
		if (rot > 0)
			mult_rots(ra, stk_a, rot);
		else if (rot < 0)
			mult_rots(rra, stk_a, -rot);
		printf("STACK A\n");
		print_stack(stk_a);
		printf("STACK B\n");
		print_stack(stk_b);
		pb(stk_a, stk_b, num_nodes);
		printf("STACK A\n");
		print_stack(stk_a);
		printf("STACK B\n");
		print_stack(stk_b);
	}
	min_node = get_min(*stk_a);
	rot = choose_rotation(stk_a, min_node);
	if (rot > 0)
		mult_rots(ra, stk_a, rot);
	else if (rot < 0)
		mult_rots(rra, stk_a, -rot);
}
		

void	turk_sort(t_node **stk_a, t_node **stk_b, int num_nodes[2])
{
	int	*opt;
	
	if (initially_ordered(stk_a))
		return ;
	push_two(stk_a, stk_b, num_nodes);
	while (num_nodes[STK_A] > 3)
	{
		printf("entra a best_push\n");
		opt = best_push(stk_a, stk_b, num_nodes);
		printf("opt a: %d\n", opt[STK_A]);
		printf("opt b: %d\n", opt[STK_B]);
		if (same_sign(opt[STK_A], opt[STK_B]))
			sim_cases(opt, stk_a, stk_b);
		rem_rots(opt, stk_a, stk_b);
		printf("STACK A\n");
		print_stack(stk_a);
		printf("STACK B\n");
		print_stack(stk_b);
		pa(stk_a, stk_b, num_nodes);
		printf("STACK A\n");
		print_stack(stk_a);
		printf("STACK B\n");
		print_stack(stk_b);
		free(opt);
	}
	three_sort(stk_a);
	printf("ENTRA EN ORDER LIST\n");
	order_list(stk_a, stk_b, num_nodes);
	printf("STACK A\n");
	print_stack(stk_a);
	printf("STACK B\n");
	print_stack(stk_b);
}

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
	//para turk_sort
//	if (num_nodes[STK_A] + num_nodes[STK_B] != argc -1)
//		return ((void)printf("Error\n"), 0);
	if (num_nodes[STK_A] < 4)
		manual_sort(&stk_a, num_nodes);
	else
		turk_sort(&stk_a, &stk_b, num_nodes);
	return (0);
}
