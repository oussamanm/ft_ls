/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:07:37 by onouaman          #+#    #+#             */
/*   Updated: 2019/01/06 16:04:32 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include "src/libft/libft.h"
#include <fcntl.h>
#include <string.h>

struct new_tm
{
	char	*day;
	char	*mon;
	char	*i_day;
	char	*hor;
	char	*min;
	char	*sec;
	char	*year;
	int		times;
};

typedef struct opt_lifo_sub
{
	struct opt_linfo *dir;
	struct opt_lifo_sub *next;
}			t_sub;

typedef struct opt_linfo
{
	char	*l_per;
	nlink_t	l_nbrl;
	char	*l_owner;
	char	*l_groupe;
	int		l_size;
	int		l_size2;
	char *l_strtm;
	struct	new_tm *l_newtm;
	char	*l_name;
	int 	l_mblock;
	struct opt_linfo *next;
}			t_linfo;

typedef	struct s_glst
{
		t_linfo *s_lst;
		t_sub *s_sublst;
}			t_glst;

void		*ft_remp(char *p_path,char *p_opt);
//void    ft_looprec(int j, t_sub **sub_lst, char **p_path,char **p_opt)
//void ft_free(t_linfo **headlst,char **new_path, char **p_path);

///// *** Function Helps
char			*ft_strjoinch(char const *s1, char c);
char			*ft_strjoir(char *s1, char *s2, size_t i);
int				ft_checkchar(char *str, char c);
void			*ft_perror(char *p_path, char *p_opt);
int				ft_getstat(struct stat *sta, struct dirent *dr_r, char *new_path);

///// *** Add && rm lst
void			ft_lstdeltime(struct new_tm **lst);
void			ft_lstdellst(t_linfo **lst);
void			ft_lstdelsub(t_sub **alst);
t_linfo		*ft_newlst();
t_sub			*ft_newsublst();

///// *** Function get Results
char		ft_gettype(mode_t mod);
char		*ft_getmode(mode_t mod);
char		*ft_gettime_m(int tmsec, struct new_tm *f_time, char *str_time);
int			ft_addlinkname(char *p_path, char *d_name, char **l_name);
void		ft_fillsize(struct stat *sta, int *l_s1, int *l_s2);


///// *** Function Sort
t_linfo 	*ft_sortlist(t_linfo **lst);
t_sub 	*ft_sortsublist(t_sub **lst);
int		ft_sortargv(int argc, char **argv);

///// **** Remp Data
int		ft_remplst(t_linfo *lst, struct stat *sta, char *d_name);
int 	ft_remplstall(t_linfo *lst, struct stat *sta, char *d_name, char * p_path);
void		*ft_remp(char *p_path,char *p_opt);
void    ft_looprec(int j, t_sub *sub_lst, char *p_path,char *p_opt);
int 		ft_rempfile(char *p_path, char *p_opt, int is_lnk);

///// **** Print Resu
void	ft_printtotal(t_linfo	*lst);
void ft_printlst(t_linfo *lst, int i_rtn);
int		ft_printres(t_linfo	**lst, t_sub **sub_lst, char *opt , int p_type);

///// ***** Option ls
int 	ft_opta(t_linfo **lst, t_sub **sub_lst, int p_type);
int 	ft_optr(t_linfo **lst);
int 	ft_optrdir(t_sub **sub_lst);
int 	ft_optt(t_linfo **lst , int i, int j);
int 	ft_opttdir(t_sub **lst);

///// ***** main Funct && Other

int 	ft_applopt(t_linfo	**lst, t_sub **sub_lst, char *opt , int p_type);
void ft_free(t_linfo *headlst, char *p_path);
void		ft_ls(int p_type, char *p_opt, char **p_file, int argc);
int		main(int argc,char **argv);

t_linfo    *ft_read(DIR *dr, char *p_path, char *p_opt);
int ft_remp_sublst(t_linfo *lst,t_sub **sub_lst);
