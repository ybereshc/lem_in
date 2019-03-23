/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:16:24 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 19:16:26 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include "ft_list.h"
# include "ft_array.h"
# include "ft_process.h"

# ifndef __uint128_t
#  define BIG_PIECE uintmax_t
# else
#  define BIG_PIECE __uint128_t
# endif

# define IF(a, b) if (a) b
# define EF(a, b) else if (a) b
# define EL(b) else b

# define OR(a, b) (a ? a : b)

# define SIZE(type, n) sizeof(type) * (n)

# define F ft_format
# define W ft_printf

/*
** Colors
*/
# define COLOR(color, string) "\e[" color "m" string "\e[0m"
# define RED(string) "\e[31m" string "\e[0m"
# define GREEN(string) "\e[32m" string "\e[0m"
# define YELLOW(string) "\e[33m" string "\e[0m"
# define BLUE(string) "\e[34m" string "\e[0m"
# define PURPLE(string) "\e[35m" string "\e[0m"
# define CYAN(string) "\e[36m" string "\e[0m"
# define BLACK(string) "\e[30m" string "\e[0m"

void		ft_init(int argc, char **argv, intmax_t options);

size_t		ft_strlen(char *str);

char		*ft_strdup(char *str);
char		*ft_strndup(char *str, size_t n);

char		*ft_strcat(char *str1, char *str2);
char		*ft_strncat(char *str1, char *str2, size_t n);
char		*ft_strfcat(char *str1, char *str2);
char		*ft_strjoin(char *str1, char *str2);
char		*ft_strfjoin(char *str1, char *str2, uint8_t f);
char		*ft_strconcat(int n, ...);

int8_t		ft_isnumeric(char *str);

char		*ft_strchr(char *str, char chr);
char		*ft_strrchr(char *str, char chr);
intptr_t	ft_strchri(char *str, char chr);
intptr_t	ft_strrchri(char *str, char chr);
size_t		ft_strchrcount(char *str, char chr);
char		**ft_strsplit(char *str, char chr);
char		**ft_strfsplit(char *str, char chr);
void		ft_free_strary(char **strary);

int8_t		ft_strncmp(char *s1, char *s2, size_t n);
int8_t		ft_strcmp(char *s1, char *s2);
int8_t		ft_strnequ(char *str1, char *str2, size_t n);
int8_t		ft_strequ(char *str1, char *str2);

char		*ft_strupper(char *str);
char		*ft_strlower(char *str);

intmax_t	ft_atoi(char *str);
intmax_t	ft_str_to_int(char *str);
uintmax_t	ft_str_to_uint(char *str, uint8_t base);

char		*ft_dint_to_str(intmax_t num);
char		*ft_uint_to_str(uintmax_t num, uint8_t base);

size_t		ft_intlen(intmax_t num);
size_t		ft_uintlen(uintmax_t num, uint8_t base);

void		ft_print_memory(void *ptr, size_t size);
void		ft_print_strary(char **strary);
char		*ft_unichr(int chr);

ssize_t		ft_gnl(int fd, char **line);

void		ft_separator(char *str);

/*
** Memory
*/
void		*ft_bzero(void *ptr, size_t n);
void		*ft_memset(void *ptr, uint8_t byte, size_t n);
void		*ft_memcpy(void *dst, void *src, size_t n);

/*
** Malloc
*/
void		*ft_mlc(size_t n);
void		*ft_memalloc(size_t n);
void		*ft_free(int n, ...);

/*
** Math
*/
intmax_t	ft_pow(intmax_t nb, uintmax_t pow);
uintmax_t	ft_upow(uintmax_t nb, uintmax_t pow);
uintmax_t	ft_abs(intmax_t n);
uint8_t		ft_odd(intmax_t n);
uint8_t		ft_even(intmax_t n);
uint8_t		ft_negative(intmax_t n);
uint8_t		ft_positive(intmax_t n);

/*
** List
*/
t_list		*ft_list(void);
t_el		*ft_list_push(t_list *list, void *ptr);
t_el		*ft_list_remove(t_list *list, void *ptr);
void		ft_list_free(t_list *list);
void		**ft_list_to_array(t_list *list);

/*
** Array
*/
void		*ft_array(size_t n);
void		*ft_any_array(size_t count, size_t n);
void		*ft_array_push(void *ary, void *ptr);
void		*ft_array_free(void *ary);

/*
** Printf
*/
ssize_t		ft_printf(char *format, ...);
ssize_t		ft_dprintf(int fd, char *format, ...);
char		*ft_format(char *format, ...);
ssize_t		ft_sformat(char **dest, char *format, ...);

#endif
