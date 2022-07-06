/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 05:53:42 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/06/09 05:45:57 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define  LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <errno.h>

	//exit>>
void		ft_exit_strerror(int errnum);
void		ft_exit_perror(char *str);
	//put>>
void		ft_putchar_fd(char c, int fd);
int			ft_putchar(char c);
void		ft_putstr_fd(char *s, int fd);
int			ft_putstr(char *s);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putnbr(long n);
int			ft_puthex(unsigned int n, int cap);

	//len>>>

size_t		ft_strlen(const char *maxlen);
int			ft_str_len(char *s);
int			ft_nbrlen(long n);
int			ft_memlen(unsigned long n);
int			ft_hexlen(unsigned int n);

	//check_value

int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_check_limit_int(long long stk);
int			ft_check_extension(char *str, char *extension);

	//change_value

int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
long long	ft_atol(const char *str);

	//maloc

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_realloc(char *ptr, size_t new_size);
void		*ft_calloc(size_t count, size_t size_t);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
void		ft_free_pp(char **argv);

	//str>>

void		*ft_memset(void *b, int c, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_bzero(void *s, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

	//link list simple

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

	//link list circulaire double

typedef struct link_list
{
	void				*content;
	struct link_list	*prev;
	struct link_list	*next;
}					t_struct;

t_struct	*ft_lst_new(void *content);
void		ft_lst_add(t_struct *l_lst, t_struct *l_lst_t);
void		ft_free_l_lst(t_struct *l_lst, int index);
int			ft_lst_check_double(void *content, t_struct *l_lst, int index);
void		ft_put_l_lst(t_struct *l_lst, int index);
void		ft_swap(t_struct *l_lst, t_struct *l_lst_n);
void		ft_rotate(t_struct **l_lst);
void		ft_rev_rotate(t_struct **l_lst);

	//get_next_line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
int			ft_getchar(const char *str, int c);
char		*ft_return(char **s_buff);
char		*ft_save(char **s_buff);

	//ft_printf

struct	s_flgs
{
	int	minus;
	int	zero;
	int	dot;
	int	precision;
	int	width;
	int	htag;
	int	plus;
	int	space;
};

int			ft_putchar_wid_min(char c, int width);
int			ft_putchar_wid_zero(char c, int width);
int			ft_putchar_wid(char c, int width);

int			ft_putstr_wid_pre(char *s, struct s_flgs flags,
				int pre_si, int wid_si);
int			ft_putstr_wid(char *s, struct s_flgs flags);
int			ft_putstr_pre(char *s, int prec);

int			ft_putmem_prewid(unsigned long n, struct s_flgs flags);
int			ft_putmem_wid(unsigned long n, struct s_flgs flags);
int			ft_putmem_pre(unsigned long n, struct s_flgs flags);
int			ft_putmem(unsigned long n, int start);

int			ft_putnbr_prewid(long n, struct s_flgs flags);
int			ft_putnbr_pre(long n, struct s_flgs flags);
int			ft_putnbr_wid(long n, struct s_flgs flags);

int			ft_puthex_prewid(unsigned int n, struct s_flgs flags, int cap);
int			ft_puthex_pre(unsigned int n, struct s_flgs flags, int cap);
int			ft_puthex_wid(unsigned int n, struct s_flgs flags, int cap);

int			ft_print_char(char c, struct s_flgs flags);
int			ft_print_str(char *s, struct s_flgs flags);
int			ft_print_mem(unsigned long n, struct s_flgs flags);
int			ft_print_nbr(long n, struct s_flgs flags);
int			ft_print_hex(unsigned int n, struct s_flgs flags, char c);
int			ft_print_htag(int cas);
void		ft_printf_flag_app(int ft, int *flag);
void		ft_printf_flag_app_2(int ft, int *flag, long n);
int			ft_print_other(char c, struct s_flgs flags);

int			ft_is_conversion_specifiers(const char c);
int			is_valid_flag(const char c);
int			ft_atoi_star(const char *s, int *i, va_list args);
void		ft_neg_star(struct s_flgs *flags);
void		flag(const char *s, int *i, struct s_flgs *flags, va_list args);
void		flag2(const char *s, int *i, struct s_flgs *flags, va_list args);

int			ft_dispatch(const char *str, int *i, va_list args);
int			ft_printf(const char *str, ...);

#endif
