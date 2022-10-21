/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:45:28 by afonso            #+#    #+#             */
/*   Updated: 2022/10/21 11:33:22 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next_node;
}t_stack;

char		*ft_utoa(unsigned int number);
int			ft_printf(char *string, ...);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int ch);
int			ft_isprint(int ch);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *mem_loc, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_stack		*ft_lstnew(int content);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstdelone(t_stack *lst, void (*del)(void *));
void		ft_lstclear(t_stack **lst, void (*del) (void *));
void		ft_lstiter(t_stack *lst, void (*f) (void*));
t_stack		*ft_lstmap(t_stack *lst, void *(*f) (void *), void (*del) (void *));
void		swap(t_stack **lst, char stack);
void		rotate(t_stack **lst, char stack);
void		reverse_rotate(t_stack **lst, char stack);
void		push(t_stack **stack_receiver, t_stack **stack_giver, char stack);
int			is_stack_complete(t_stack **lst, int flag);
void		free_stack(t_stack **lst);
void		sort_stacks(t_stack **lst, int argc, int *numbers);
int			set_astack(t_stack **lst, int **numbers, int int_num);
int			compare_int(int i, int j);
int			check_repeated_args(int argc, int *numbers);
void		sort_radix(t_stack **lst);
int			find_average(t_stack *stack);
int			check_input(int argc, char **argv, int **numbers);
void		checkif_number(char **argv, int *ret_address, int i, int *j);

#endif
