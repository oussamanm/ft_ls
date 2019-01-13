#include "ft_ls.h"

void	ft_printtotal(t_linfo	*lst) /// Done
{
	int total;

	total = 0;
	while (lst != NULL && lst->l_name != NULL)
	{
		total += lst->l_mblock;
		lst = lst->next;
	}
	printf("total %d\n",total);
}
void ft_printlst(t_linfo *lst, int i_rtn) /// Done
{
	if (i_rtn != 1)
		printf("%s  ",lst->l_name);
	else
	{
		printf("%s\t", lst->l_per);
		printf("%d\t", lst->l_nbrl);
		printf("%s  ", lst->l_owner);
		printf("%s\t", lst->l_groupe);
		if (lst->l_size2 == -1)
			printf("%d\t", lst->l_size);
		else
			printf("%d , %d\t", lst->l_size, lst->l_size2);
		printf("%s\t", lst->l_strtm);
		printf("%s  ", lst->l_name);
		printf("\n");
	}
}
int		ft_printres(t_linfo	**lst, t_sub **sub_lst, char *opt , int p_type) /// Done
{
	int				rtn;
	int				i_rtn;
	t_linfo 	*temp_lst;

	if (lst != NULL)
		temp_lst = *lst;
	rtn = 0;
	rtn = ft_applopt(&temp_lst, sub_lst, opt, p_type); //// Apply opt
	i_rtn = ft_checkchar(opt, 'l');
	if (p_type == 1 && i_rtn == 1 && (*lst) != NULL) //// print Total
		ft_printtotal(*lst);
	while (p_type == 1 && temp_lst != NULL && temp_lst->l_name != NULL /*&& rtn != -1*/)
	{
		ft_printlst(temp_lst, i_rtn); //// print result
		temp_lst = temp_lst->next;
	}
	if (p_type == 1 && i_rtn == 0)
		puts("\n");
	return (0);
}
