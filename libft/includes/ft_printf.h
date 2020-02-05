/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:13:31 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/21 11:52:48 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFFSIZE 4096
# define OPT "#-+ '0123456789.hlLjzcCsSpDdioUueEfFgGxX"
# define CONVTYPE "CcSspDdioUufFxX"
# define INTEGERS "dDiUuoxX"
# define PRCNT " #'*-+0123456789%."
# define FLAG "#+- '0"
# define SIZE "hlLjz"
# define PREC ".0123456789"
# define B_HEXL "0123456789abcdef"
# define B_HEXC "0123456789ABCDEF"
# define B_TENT "0123456789"
# define B_OCTA "01234567"
# define B_BINA "01"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <sys/types.h>
# include "libft.h"

char	g_buff[BUFFSIZE];
int		g_buffi;

typedef union	u_varpkg {
	void			*vptr;
	char			car;
	wint_t			carc;
	char			*str;
	wchar_t			*strs;
	intmax_t		intmaxt;
	uintmax_t		uintmaxt;
	long double		ldble;
}				t_var;

typedef struct	s_flags {
	char		fg_prefi;
	char		fg_apost;
	char		fg_signs;
	char		fg_justi;
	int			fg_zfill;
	int			fg_width;
	int			fg_preci;
	char		*fg_fsize;
	char		type;
}				t_flags;

typedef struct	s_formats {
	t_flags		arg_fg;
	t_var		va_holder;
	int			native_index;
	int			fg_va_holder;
	int			negative;
	char		*native_form;
	char		*final_form;
	int			finfg;
}				t_form;

int				ft_printf(const char *format, ...);
int				prct(const char *ptr);
int				iupdate(const char *ptr);
int				isprcnt(const char *ptr);
int				init_form_pkg(t_form *form_pkg);
void			init_gvars(void);
int				init_fg(t_flags *fg);
void			t_form_freer(t_form *form);
int				buff_print(void);
int				securebuffer(char c);
int				print_flush(char *form);
int				print_dispatch(t_form *fin);
int				check_set_form(const char *temp_form, va_list arg);
int				parse_set_fg_flags(t_form *form, char *nat);
int				parse_set_fg_pre(t_form **fg, char *format);
int				parse_set_fg_siz(t_form **fg, char *format);
int				parse_set_fg_pad(t_form **form, char *format);
int				parse_set_fg_wid(t_form **fg, char *format);
int				va_select(t_form *form, va_list arg);
int				cva(t_form **form, va_list arg);
int				sva(t_form **form, va_list arg);
int				diva(t_form **form, va_list arg);
int				uva(t_form **form, va_list arg);
int				fva(t_form **form, va_list arg);
int				tostrdispatch(t_form *form);
char			*str_renderer(t_form **fm);
char			*c_renderer(t_form **fm);
char			*p_renderer(t_form **fm);
char			*lc_renderer(t_form **fm);
char			*ls_renderer(t_form **fm);
char			*int_renderer(t_form **fm);
char			*f_renderer(t_form **fm);
char			*padrenderer(char *fin, t_form *fm, int len);
#endif
