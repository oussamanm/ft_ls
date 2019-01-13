#include "ft_ls.h"

////////******** Options Function *********///////////
int 	ft_opta(t_linfo **lst, t_sub **sub_lst, int p_type)
{
	if (p_type == 0 && sub_lst == NULL)
		return (-1);
	else if (p_type == 1 && lst == NULL)
		return (-1);
	if (p_type == 0)
	{
		while ((*sub_lst)->dir->l_name[0] == '.')
		{
			if ((*sub_lst)->next != NULL  && (*sub_lst)->next->dir->l_name != NULL)
				*sub_lst = (*sub_lst)->next;
			else
			{
				*sub_lst = NULL;
				break ;
			}
		}
	}
	else
	{
		while ((*lst) != NULL && (*lst)->l_name[0] == '.')
		{
			if ((*lst)->next != NULL && (*lst)->next->l_name != NULL)
				(*lst) = (*lst)->next;
			else
			{
				*lst = NULL;
				break ;
			}
		}
	}
	return (0);
}
int 	ft_optr(t_linfo **lst) /// Done
{
	t_linfo *prev_lst;
	t_linfo *curr_lst;
	t_linfo *next_lst;

	if (*lst == NULL)
		return (-1);
	prev_lst = NULL;
	curr_lst = NULL;
	next_lst = NULL;
	curr_lst = *lst;
	while (curr_lst->l_name != NULL)
	{
		next_lst = curr_lst->next;
		curr_lst->next = prev_lst;
		prev_lst = curr_lst;
		curr_lst = next_lst;
	}
	*lst = prev_lst;
	return (0);
}
int 	ft_optrdir(t_sub **sub_lst) /// Done
{
	t_sub *prev_lst;
	t_sub *curr_lst;
	t_sub *next_lst;

	prev_lst = NULL;
	curr_lst = NULL;
	next_lst = NULL;
	curr_lst = *sub_lst;
	while (curr_lst != NULL)
	{
		next_lst = curr_lst->next;
		curr_lst->next = prev_lst;
		prev_lst = curr_lst;
		curr_lst = next_lst;
	}
	*sub_lst = prev_lst;
	return (0);
}
int 	ft_optt(t_linfo **lst , int i, int j)
{
	t_linfo *pp;
	t_linfo *p;
	t_linfo *c;
	t_linfo *n;

	while (i++ < 1 && *lst != NULL)
	{
			j = 0;
			pp = *lst;
			p = *lst;
			c = (*lst)->next;
			n = c->next;
			while(p->next != NULL && p->next->l_newtm != NULL)
			{
					if (p->l_newtm->times < p->next->l_newtm->times)
					{
						c->next = p;
						p->next = n;
						pp = (j == 0) ? c : pp;
						*lst = (j == 0) ? c : *lst;
						pp->next = (j != 0) ? c : pp->next;
						pp = (j != 0 ) ? pp->next : pp;
						j++;
						i = 0;
					}
					else
					{
							pp = (j >= 1) ? pp->next : pp;
							p = p->next;
					}
					c = (n != NULL) ? n : c;
					n = (n != NULL) ? n->next : n;
					j++;
			}
	}
	return (0);
}
int 	ft_opttdir(t_sub **lst)
{
	int i;
	int j;
	t_sub *pp;
	t_sub *p;
	t_sub *c;
	t_sub *n;

	i = 0;
	while (i++ < 1 && (*lst) != NULL && (*lst)->next != NULL)
	{
			j = 0;
			pp = *lst;
			p = *lst;
			c = (*lst)->next;
			n = c->next;
			while(p->next != NULL)
			{
					if (p->dir->l_newtm->times < p->next->dir->l_newtm->times)
					{
							c->next = p;
							p->next = n;
							pp = (j == 0) ? c : pp;
							*lst = (j == 0) ? c : *lst;
							pp->next = (j != 0) ? c : pp->next;
							pp = (j != 0) ? pp->next : pp;
							j++;
							c = n;
							i = 0;
					}
					else
					{
							pp = (j >= 1) ? pp->next : pp;
							c = c->next;
							p = p->next;
					}
					n = (n != NULL) ? n->next : n;
					j++;
			}
	}
	return (0);
}
