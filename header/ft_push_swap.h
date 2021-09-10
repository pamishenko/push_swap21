/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:34:23 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/10 23:17:45 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_stack
{
	struct s_stack	*previous_element;
	struct s_stack	*next_element;
	int				value;
	int				step;
	int				is_base;
	int				*min;
	int				*max;
	int				*min_b;
	int				*max_b;
	int				is_const;
	int				*count;
}	t_stack;

typedef struct s_instruction
{
	struct s_instruction	*next_instruction;
	char					instr[4];
}	t_instruction;

typedef struct s_stacks
{
	t_stack			*stack_a;
	int				count_a;
	int				min;
	int				max;
	int				min_b;
	int				max_b;
	int				med;
	int				base;
	t_stack			*stack_b;
	int				count_b;
	t_instruction	*instruct;
}	t_stacks;

int			ft_atoi(const char *str);
int			ft_base_sort(t_stacks *stacks);
void		*ft_calloc(size_t count, size_t size);
int			ft_close_instructions(t_instruction *instruct);
int			ft_close_stack(t_stack *stack);
int			ft_close_stacks(t_stacks *stacks);
int			ft_double_checker(int count, char *arr[]);
void		ft_fill_stack_a(t_stacks *stacks, int argc, char *argv[]);
int			ft_get_all_instructions(t_stacks *stacks);
t_stack		*ft_get_first_element_stack(t_stack *stack);
t_stack		*ft_get_last_element(t_stack *stack);
t_stack		*ft_get_last_element_stack(t_stack *stack);
void		ft_init_base(t_stacks *stacks);
t_stacks	*ft_init_stacks(int argc, char *argv[]);
t_stack		*ft_init_stack_b(t_stacks *stacks);
int			ft_is_sorted(t_stacks *stacks);
int			ft_maxsort_step(t_stacks *stacks);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_minusbase(t_stacks *stacks);
void		ft_move_a2b_element(t_stacks *stacks);
void		ft_move_for_push_b(t_stacks *stacks);
void		ft_move_for_push_a(t_stacks *stacks);
int			ft_push_a(t_stacks *stacks);
int			ft_push_b(t_stacks *stacks);
int			ft_push_a2(t_stacks *stacks);
int			ft_push_b2(t_stacks *stacks);
int			ft_push_swap(int a, ...);
int			ft_push_swap_utils(void);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_print_stack(t_stack *stack);
int			ft_reverse_rotate_a(t_stacks *stacks);
int			ft_reverse_rotate_ab(t_stacks *stacks);
int			ft_reverse_rotate_b(t_stacks *stacks);
int			ft_rotate_a(t_stacks *stacks);
int			ft_rotate_ab(t_stacks *stacks);
int			ft_rotate_b(t_stacks *stacks);
int			ft_search_top_count(t_stack *stack, int value);
void		ft_set_base(t_stacks *stacks);
int			ft_set_instruction(t_stacks *stack, char *str);
void		ft_set_med(t_stacks *stacks);
void		ft_set_new_min_max_a(t_stacks *stacks);
void		ft_set_new_min_max_b(t_stacks *stacks);
int			ft_sort(t_stacks *stacks);
size_t		ft_strlen(const char *s);
int			ft_swap_a(t_stacks *stacks);
int			ft_swab_ab(t_stacks *stacks);
int			ft_swap_b(t_stacks *stacks);

#endif
