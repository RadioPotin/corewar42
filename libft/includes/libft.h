/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:46:52 by evogel            #+#    #+#             */
/*   Updated: 2019/12/03 12:19:07 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdint.h>

typedef struct	s_lst
{
	int				fd;
	char			*str;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_lists
{
	void			*content;
	size_t			content_size;
	struct s_lists	*next;
}				t_lists;

int				ft_abs(int n);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strisdigit(char *str);

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *haystack, const char *needle);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

void			ft_strclr(char *s);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_striter(char *s, void (*f)(char *));
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2i, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
int				ft_str_nb_of_target(char *str, char const *target);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);

void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

void			ft_lstadd(t_lists **alst, t_lists *nw);
void			ft_lstiter(t_lists *lst, void (*f)(t_lists *elem));
t_lists			*ft_lstmap(t_lists *lst, t_lists *(*f)(t_lists *elem));
t_lists			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdel(t_lists **alst, void (*del)(void*, size_t));
void			ft_lstdelone(t_lists **alst, void (*del)(void*, size_t));

int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_sqrt(int nb);
void			ft_puttab(char **tab);
int				ft_lstlen(t_lists *lst);
void			ft_tabdel(int i, char ***tab);
int				ft_tab_size(char **tab);
void			ft_inttabdel(int i, int ***tab);
t_lists			*ft_lstn(t_lists *lst, size_t n);
void			ft_putlst(t_lists *lst, void (*f)(void*));

unsigned int	quarter(int nb);
char			*ft_strrev(char *str);
size_t			ft_strichr(const char *feed, char c);
char			*ft_itoa_baze(uintmax_t nb, int base);
char			*ft_itoa_base(long nb, int base);
void			ft_putnbr_base(int nbr, char *base);
int				ft_atoi_base(char *str, char *base);
int				ft_base_check_and_strlen(char *base);
char			*ft_strndup(const char *s1, size_t len);
int				get_next_line(const int fd, char **line);
char			ft_strchrsetc(char *tosearch, char *charset);
char			*ft_strchrset(char *tosearch, char *charset);
char			*ft_strrchrset(char *tosearch, char *charset);
int				ft_nonchrseti(const char *str, const char *chrset);
int				ft_nchrchck(const char *str, char *chrset, int len);
int				ft_strichrset(const char *temp, const char *charset);
uintmax_t		ft_atoull_base(char *nb, char *nativebase);
intmax_t		ft_atoll_base(char *nb, char *nativebase);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
char			*ft_strcfill(const char *str, char chr, long int index,
		long int len);
char			*ft_strsfill(const char *str, const char *s, long int index);
char			*ft_strtruncto(char *str, int preci);
char			*uintmaxt_itoa(uintmax_t nb, int fg_negative);
char			*ft_freer(char **tofree, char *tolink);
char			*ft_ldbltoa(long double nb, int preci, int fg);
uintmax_t		ft_recursive_power(uintmax_t nb, int power);
char			*clean_pad(char *fin, char c, unsigned int i, int len);
char			*get_full_file(int fd);
int				ft_count_word(char const *s, char c);
char			**ft_copy_tab(char **tab);
#endif
