/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:34:01 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/03 18:45:10 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_flags
{
	int	left_justify;
	int	zeros;
	int	plus;
	int	blank;
	int	hash;
	int	width;
	int	precision;
	int	precision_is_zero;
	int	nbr_len;
	int	is_null;
}	t_flags;

char	*get_next_line(int fd);
int		add_to_stash(char **stash, char *buffer, int size);
int		new_line_char(char *stash);
int		reduce_stash(char **stash, int line_len);
int		init_stash(char **stash);
int		init_buffer(char **buffer);
char	*free_all(char **stash, char **buffer);
char	*get_return_line(char **stash);
int		ft_printf(const char *format, ...);
int		ft_handle_conversion(const char c, va_list args, t_flags flags);
int		ft_putptr(void *ptr, t_flags flags);
int		ft_putnbr(int nbr, t_flags flags);
int		ft_putunsignednbr(unsigned int nbr, t_flags flags);
int		ft_putlowerx(unsigned int hexa, t_flags flags);
int		ft_putupperx(unsigned int hexa, t_flags flags);
int		ft_putchar(char c);
int		ft_putchar_flags(char c, t_flags flags);
int		ft_putstr(char *s, t_flags *flags);
int		ft_nbrlen(int nbr);
int		ft_add_char_hexa(unsigned long hexa, t_flags *flags, char c);
int		ft_unsignednbrlen(unsigned int nbr);
int		ft_hexalen(unsigned long nbr);
int		ft_add_left_justify(int len, t_flags flags);
void	ft_check_plus(t_flags *flags);
t_flags	ft_check_flags(const char *format, int *i);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t siz);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

// BONUS
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

#endif
