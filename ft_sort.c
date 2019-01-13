#include "ft_ls.h"

/*void    ft_subswap(t_sub **head, t_sub *xlst, t_sub *ylst)
{
            printf("wayli\n");
    t_sub *plst;
    t_sub *lst;

    lst = *head;
    while (lst)
    {
        if (lst->dir == NULL || xlst == NULL || ylst == NULL)
            return ;
        if (lst == *head)
            plst = NULL;
        printf("if (lst == xlst) => %s \n",lst->dir->l_name);
        if (lst == xlst)
        {
            xlst->next = ylst->next;
            if (plst == NULL && lst == *head)
              *head = ylst;
            else
              plst->next = ylst;
            ylst->next = xlst;
            return ;
        }
        plst = lst;
        lst = lst->next;
    }
}*/

void    ft_swap(t_linfo **head, t_linfo *xlst, t_linfo *ylst)
{
    t_linfo *plst;
    t_linfo *lst;

    lst = *head;
    while (lst)
    {
        if (lst == NULL || xlst == NULL || ylst == NULL)
            return ;
        if (lst == *head)
            plst = NULL;
        if (lst == xlst)
        {
            xlst->next = ylst->next;
            if (plst == NULL && lst == *head)
              *head = ylst;
            else
              plst->next = ylst;
            ylst->next = xlst;
            return ;
        }
        plst = lst;
        lst = lst->next;
    }
}

t_linfo 	*ft_sortlist(t_linfo **lst)
{
  t_linfo  *head;
	int      i;

	i = 0;
	while (i++ < 1)
	{
			head = *lst;
			while (head != NULL && head->next != NULL && head->next->l_name != NULL)
			{
					if (ft_strcmp(head->l_name , head->next->l_name) > 0)
					{
							i = 0;
							ft_swap(lst, head, head->next);
							//break;
					}
					if (head->next != NULL)
            head = head->next;
			}
	}
	return (*lst);
}

/*t_sub 	*ft_sortsublist(t_sub **lst)
{
  t_sub  *head;
	int    i;
  printf("in sortsublist \n");
	if ((*lst) == NULL || (*lst)->dir == NULL || (*lst)->next == NULL)
    	return (NULL);

  i = 0;
	while (i++ < 1 && (*lst)->dir != NULL)
	{
      head = *lst;
			while(head != NULL && head->next != NULL && head->dir->l_name != NULL)
			{

        if (ft_strcmp(head->dir->l_name , head->dir->next->l_name) > 0)
        {
            i = 0;
            printf("befor enter ot  ft_subswap\n");
            ft_subswap(lst, head, head->next);
            break;
        }
        if (head->next != NULL)
          head = head->next;
			}
  }
  return (*lst);
}*/

int		ft_sortargv(int argc, char **argv) /// Done
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (0);
}
