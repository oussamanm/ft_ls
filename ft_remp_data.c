#include "ft_ls.h"

int     ft_remplst(t_linfo *lst, struct stat *sta, char *d_name) /// Done
{
	struct new_tm	*s_time;

	if ((s_time = (struct new_tm *)malloc(sizeof(struct new_tm))) == NULL)
	{
		ft_putstr("\n!!!!!!!!!!! Error On malloc s_time !!!!!!!!!!!!!!\n");
		return (-1);
	}
	lst->l_name = ft_strnew(250);
	ft_strcpy(lst->l_name, d_name);
	lst->l_strtm = ft_gettime_m(sta->st_mtime, s_time, ctime(&sta->st_mtime));
	lst->l_newtm = s_time;
	lst->l_per = ft_strnew(1);
	lst->l_per[0] = ft_gettype(sta->st_mode);
	return (0);
}
int     ft_remplstall(t_linfo *lst, struct stat *sta, char *d_name, char * p_path) /// Done
{
	struct passwd	*s_psw;
	struct group	*s_grp;
	struct new_tm	*s_time;

	if ((s_time = (struct new_tm *)malloc(sizeof(struct new_tm))) == NULL)
		return (-1);
	s_psw = getpwuid(sta->st_uid);
	s_grp = getgrgid(sta->st_gid);
	lst->l_strtm = ft_gettime_m(sta->st_mtime, s_time, ctime(&sta->st_mtime));
	lst->l_newtm = s_time;
	lst->l_per = ft_getmode(sta->st_mode);
	lst->l_nbrl = sta->st_nlink;
	lst->l_owner = ft_strnew(25);
	lst->l_groupe = ft_strnew(25);
	ft_strcpy(lst->l_owner, s_psw->pw_name);
	ft_strcpy(lst->l_groupe, s_grp->gr_name);
	lst->l_name = ft_strnew(250);
	ft_strcpy(lst->l_name, d_name);
	lst->l_mblock = sta->st_blocks;
	ft_fillsize(sta, &(lst->l_size), &(lst->l_size2)); ///// size
	if ((sta->st_mode & S_IFMT) == S_IFLNK)
		ft_addlinkname(p_path,d_name,&(lst->l_name)); ///// Link
	return (0);
}

int 		ft_rempfile(char *p_path, char *p_opt, int is_lnk)  /// Done
{
	struct stat		sta;
	t_linfo				*lst;
	int						rtn_optl;

	rtn_optl = ft_checkchar(p_opt, 'l');
	lst = ft_newlst();
	if (is_lnk == 0)
		stat(p_path, &sta);
	else
		lstat(p_path, &sta);
	if (rtn_optl == 1)
		ft_remplstall(lst, &sta, p_path, p_path);
	else
		ft_remplst(lst, &sta, p_path);
	ft_printlst(lst, rtn_optl);
	if (rtn_optl == 0)
		printf("\n");
	return (0);
}

void		*ft_remp(char *p_path,char *p_opt) /// Done
{
	DIR			*dr;
	t_linfo	*lst;
	t_sub		*sub_lst = NULL;
	int			j;

	j = 0;
	if ((dr = opendir(p_path)) == NULL) 			///// Open Dir
		return (ft_perror(p_path, p_opt));
	p_path = ft_strjoinch(p_path, '/');
  lst = ft_read(dr, p_path, p_opt);   		 ///// Remp lst
	ft_sortlist(&lst); 											///// Sort : lst and sublst
	if (ft_checkchar(p_opt, 'R') == 1)
		j = ft_remp_sublst(lst, &sub_lst );    //// Remp sub_lst
  //if (j != 0/*&& headsublst != NULL && headsublst->dir != NULL*/)
	//	ft_sortsublist(&sub_lst);
	//printf("fin sort and sortsub \n");
  if (j != 0)															///// print resu
		ft_printres(NULL, &sub_lst, p_opt, 0);
	ft_printres(&lst, NULL, p_opt, 1);
	if (closedir(dr) == -1)
	{
		perror("error ");
		return (NULL);
	}
	ft_looprec(j,sub_lst,p_path, p_opt); /////Recu && Free memo
	ft_free(lst,p_path);
	return (NULL);
}
void    ft_looprec(int j, t_sub *sub_lst, char *p_path,char *p_opt) //// Done ?
{
    char *new_path;

		if (j == 0)
			return ;
		while(j != 0 && sub_lst != NULL && sub_lst->dir != NULL)
		{
			new_path = ft_strjoir(p_path, sub_lst->dir->l_name, -1);
			printf("\n%s:\n", new_path);
			ft_remp(new_path, p_opt);
			if (sub_lst->next == NULL)
				  break ;
			else
					sub_lst = sub_lst->next;
		}
		//if (new_path != NULL)
    //	ft_strdel(&new_path);
}

t_linfo    *ft_read(DIR *dr, char *p_path, char *p_opt) /// Do 5 decl
{
  char					*new_path;
  struct dirent	*dr_r;
  t_linfo				*lst;
	t_linfo				*head_lst;
	struct stat		sta;

  lst = ft_newlst();
	head_lst = lst;
  while ((dr_r = readdir(dr)) != NULL)
	{
		new_path = ft_strjoir(p_path, dr_r->d_name, -1);
		if ((ft_getstat(&sta, dr_r, new_path)) == -1)
			exit(0);
		if (ft_checkchar(p_opt, 'l') == 1)
			ft_remplstall(lst, &sta, dr_r->d_name, p_path);
		else
			ft_remplst(lst, &sta, dr_r->d_name);
		lst->next = ft_newlst();
		lst = lst->next;
	}
	if (new_path)
  	ft_strdel(&new_path);
  return (head_lst);
}

int   ft_remp_sublst(t_linfo *lst,t_sub **sub_lst) //// Do
{
  int				j;
  t_linfo		*tmp_lst;
  t_sub			*temp_sublst;

  tmp_lst = lst;
  j = 0;
  while (tmp_lst != NULL && tmp_lst->l_name != NULL)
  {
    if (tmp_lst->l_per[0] == 'd' && strcmp(tmp_lst->l_name, ".") != 0 &&
		 strncmp(tmp_lst->l_name, "..", 2) != 0)
    {
      if (j++ == 0)
      {
        *sub_lst = ft_newsublst();
        temp_sublst = *sub_lst;
      }
      else
      {
        (*sub_lst)->next = ft_newsublst();
        *sub_lst = (*sub_lst)->next;
      }
			(*sub_lst)->dir = tmp_lst;
    }
    tmp_lst = tmp_lst->next;
  }
	*sub_lst = temp_sublst;
  return (j);
}
