/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:22:25 by ebucheit          #+#    #+#             */
/*   Updated: 2016/11/15 17:24:02 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>

# define MAX_INT 2147483647
# define BUFF_SIZE 128

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_flags
{
	int hash;
	int zero_spacer;
	int neg;
	int width;
	int plus_sign;
	int space;
	int modula;
	int precision;
	int hh;
	int h;
	int l;
	int ll;
	int j;
	int z;
}					t_flags;

void				free_2d_char(char **data, int length);
int					error_master5000(char *message);
char				*ft_strmake(char *string);
char				**malloc_list(char *string);
char				**ft_addstr(char **list, char *string, int size);
char				**ft_paragraph(char **list, char *string, int size);
t_list				*ft_lstmap(t_list*lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_strncmp(const char *str, const char *str2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strdup(const char *s1);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *dst, int c, size_t len);
char				*ft_strcpy(char *s1, const char *s2);
int					ft_isalpha(int c);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
void				ft_putstr(char *str);
int					ft_strcmp(const char *str, const char *str2);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
int					ft_isalnum(int c);
int					ft_isspace(int c);
void				ft_last_word(char *str);
void				ft_isneg(int *n, int *negative);
char				*ft_search_and_replace(char *str, int search, int new);
int					ft_isupper(int c);
int					get_next_line(int fd, char **line);
int					ft_printf(char *fmt, ...);
void				check_spec(char *fmt, t_flags flags, va_list ap);
int					setup(char *fmt, va_list ap);
t_flags				init_flags(t_flags flags);
t_flags				check_wid(char *fmt, t_flags flags, va_list ap);
t_flags				check_precis(char *fmt, t_flags flags, va_list ap);
t_flags				check_flags(char *fmt, t_flags flags, va_list ap);
t_flags				check_mod(char *fmt, t_flags flags);
void				prepend_width(t_flags flags, int width);
void				print_char(va_list ap, t_flags flags);
void				putwide(wchar_t chr);
void				chars(va_list ap, t_flags flags, char specifier);
char				*wide_to_s(wint_t w);
void				limit_print(char *str, int len);
void				make_string(char *s, t_flags flags);
void				l_str(wchar_t *ws, t_flags flags);
void				str_parse(va_list ap, t_flags flags, char c);
int					get_size(uintmax_t num, int base);
void				print_num(char *str, t_flags flags);
void				num_to_s(uintmax_t number, t_flags flags, char before);
intmax_t			promo_check(va_list ap, t_flags flags, char *fmt);
void				num_parse(va_list ap, t_flags flags, char *fmt);
void				u_to_s(uintmax_t num, t_flags flags);
uintmax_t			promoting_u(va_list ap, t_flags flags, char *fmt);
void				unum_parse(va_list ap, t_flags flags, char *fmt);
void				x_mod(t_flags flags, char *fmt, char *new);
void				x_to_s(uintmax_t n, t_flags flags, char *fmt, int size);
uintmax_t			promoting_x(va_list ap, t_flags flags);
void				xnum_parse(va_list ap, t_flags flags, char *fmt);
void				o_to_s(uintmax_t num, t_flags flags);
uintmax_t			promoting_o(va_list ap, t_flags flags, char *fmt);
void				onum_parse(va_list ap, t_flags flags, char *fmt);
char				*cp_pointer(long n, int len);
void				p_to_s(void *pointer, t_flags flags);

#endif
