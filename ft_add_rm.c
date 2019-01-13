#include "ft_ls.h"

void		ft_lstdeltime(struct new_tm **lst) /// Done
{
	if ((*lst) == NULL)
		return ;
	if ((*lst) != NULL)
		ft_strdel(&((*lst)->mon));
	if ((*lst) != NULL)
		ft_strdel(&((*lst)->i_day));
	if ((*lst) != NULL)
		ft_strdel(&((*lst)->hor));
	if ((*lst) != NULL)
		ft_strdel(&((*lst)->min));
	if ((*lst) != NULL)
		ft_strdel(&((*lst)->sec));
	if ((*lst) != NULL)
		ft_strdel(&((*lst)->year));
	free(*lst);
	lst = NULL;
}
void		ft_lstdellst(t_linfo **lst) /// Done
{
	t_linfo *temp;

	if ((*lst) == NULL)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		if ((*lst) != NULL && (*lst)->l_name != NULL)
			ft_strdel(&((*lst)->l_name));
		if ((*lst) != NULL && (*lst)->l_owner != NULL)
			ft_strdel(&((*lst)->l_owner));
		if ((*lst) != NULL && (*lst)->l_groupe != NULL)
			ft_strdel(&((*lst)->l_groupe));
		if ((*lst) != NULL && (*lst)->l_strtm != NULL)
			ft_strdel(&((*lst)->l_strtm));
		if ((*lst) != NULL && (*lst)->l_newtm != NULL)
			ft_lstdeltime(&((*lst)->l_newtm));
		free(*lst);
		*lst = NULL;
		*lst = temp;
	}
	lst = NULL;
}
void		ft_lstdelsub(t_sub **alst) /// Done
{
	t_sub	*temp;

	if ((*alst) == NULL)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		if ((*alst)->dir != NULL)
			free(&((*alst)->dir));
		free(*alst);
		*alst = NULL;
		*alst = temp;
	}
	alst = NULL;
}

t_linfo		*ft_newlst() /// Done
{
	t_linfo	*lst_temp;

	if (!(lst_temp = (t_linfo *)malloc(sizeof(t_linfo))))
	{
		puts("\n!!!!!!!!!!! Error On malloc !!!!!!!!!!!!!!\n");
		return (NULL);
	}
	lst_temp->l_per = NULL;
	lst_temp->l_nbrl = 0;
	lst_temp->l_owner = NULL;
	lst_temp->l_groupe = NULL;
	lst_temp->l_size = 0;
	lst_temp->l_size2 = -1;
	lst_temp->l_strtm = NULL;
	lst_temp->l_newtm = NULL;
	lst_temp->l_name = NULL;
	lst_temp->next = NULL;
	return (lst_temp);
}
t_sub		*ft_newsublst() /// Done
{
	t_sub	*lst_temp;

	if (!(lst_temp = (t_sub *)malloc(sizeof(t_sub))))
	{
		puts("\n!!!!!!!!!!! Error On malloc !!!!!!!!!!!!!!\n");
		return (NULL);
	}
	lst_temp->dir = NULL;
	lst_temp->next = NULL;
	return (lst_temp);
}
