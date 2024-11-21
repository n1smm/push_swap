/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:46:28 by tjuvan            #+#    #+#             */
/*   Updated: 2024/05/07 14:14:19 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./final_libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

# ifndef CHUNK
#  define CHUNK 5
# endif

typedef struct s_list
{
	int				content;
	int				di;
	struct s_list	*next;
	struct s_list	*previous;
}					t_stack;

typedef struct s_swap
{
	char			**argx;
	int				i;
	int				k;
	int				argcx;
}					t_swap;

/* main function */
long				ft_atoi(const char *nptr);
int					create_list(int arr[], int argc, t_stack **tail,
						t_stack **head);
long				check_input(const char *nptr, long result);
int					fill_array(int *arr, char **argv, int skip, t_swap *swp);
/* make list */
t_stack				*init(int content, t_stack **tail, t_stack **head);
void				deallocate(t_stack **tail, t_stack **head, int **arr,
						t_swap *swp);
void				print_list(t_stack *tail);
int					ft_lstadd_front(int content, t_stack **tail);
int					ft_lstadd_back(int content, t_stack **head);
/* cold start */
int					cold_start(int arr[], t_stack **list_a, int length,
						int success);
void				merge_sort(int arr[], int length);
void				merge_sort_recursion(int arr[], int low, int high);
void				merge_sorted_arrays(int arr[], int low, int middle,
						int high);
int					binary_search(int arr[], int target, int low, int high);
/* fuck norminette */
int					create_arrays(int left, int right, int **temp_left,
						int **temp_right);
int					arg_check(t_swap *swp, char ***argv, t_stack **tail,
						t_stack **head);
int					create_one(int **arr, int argc);
void				fill_right(int arr[], int temp_right[], int right,
						int middle);
void				fill_left(int arr[], int temp_left[], int left, int low);
/* ft_split */
int					word_counter2(char const *word, char c);
char				*word_placer2(char *word, char const *s, int i,
						int word_len);
char				**free_arr2(char **big, int count);
char				**word_splitter2(char const *s, char c, char **s2,
						int num_words);
char				**ft_split2(char const *s, char c);
/* sorting_comms */
char				*push_node(t_stack **tail_a, t_stack **tail_b,
						t_stack **head_b, char *specify);
char				*swap_nodes(t_stack **tail, t_stack **head, char *specify);
char				*rotate_r(t_stack **tail, t_stack **head, char *specify);
char				*rotate(t_stack **tail, t_stack **head, char *specify);
int					splitter(char *tmp, int argc, char ***argv, t_swap *swp);
/* algo */
void				cheat_sort(t_stack **tail_a, t_stack **head_a);
char				*divide(t_stack **t_a, t_stack **h_a, t_stack **t_b,
						t_stack **h_b);
int					counter(t_stack *tail_a);
char				*mini_sort(t_stack **tail, t_stack **head);
char				*rotate_best_memb(t_stack **t, t_stack **h, int di,
						char *mv);
/* di_finder */
int					di_finder(t_stack *tail, t_stack *head, int full_count,
						t_stack *ref_node);
int					di_finder2(t_stack *tail, t_stack *head, t_stack *ref_node);
int					di_finder1(t_stack *tail, t_stack *head, int full_count);
int					di_finder_top(t_stack *tail, int low_di, int high_di,
						int full_count);
int					di_finder_bottom(t_stack *head, int low_di, int high_di,
						int full_count);
/* algo2 */
void				second_move(t_stack **tail_a, t_stack **head_a,
						t_stack **tail_b, int full_count);
char				*top_sort(t_stack **t_a, t_stack **h_a, t_stack **t_b,
						t_stack **h_b);
char				*bottom_sort(t_stack **tail_a, t_stack **tail_b,
						t_stack **head_a);
char				*final_push(t_stack **tail_a, t_stack **tail_b,
						char *specify);
char				*last_spin(t_stack **tail_a, t_stack **head_a,
						t_stack **tail_b, int high_l);
/* print_comms */
void				print_commands(char *comms);
void				comm_checker(char ***command);
char				*comm_holder(char *str);
void				comm_replacer(char ***command, int i, int n);
int					tester(t_stack *tail);
/* push_utils */
int					stack_alloc(t_stack ***tail, t_stack ***head, t_swap *swp,
						int argc);
int					free_argv(char **argv, int i, int success, int skip);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char *s1, char *s2, int free_all);
/* soft landing */
char				*soft_landing(t_stack **tail_b, t_stack **head_b,
						int full_count, t_stack **tail_a);
char				*bottom_landing(t_stack **tail_b, t_stack **head_b,
						int full_count, t_stack **tail_a);
void				check_split(char **argx, long *i);
/* medium_sort */
int					find_highest(t_stack *tail);
char				*medium_high(t_stack **t_a, t_stack **h_a, t_stack **t_b,
						t_stack **h_b);
char				*medium_rot(t_stack **t_a, t_stack **h_a, int full_count,
						int i);
char				*medium_sort(t_stack **t_a, t_stack **h_a, t_stack **t_b,
						t_stack **h_b);
#endif
