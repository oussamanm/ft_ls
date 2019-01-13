/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:06:43 by onouaman          #+#    #+#             */
/*   Updated: 2019/01/04 16:16:32 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

////////******** Mains Function && Others *********///////////

int 	ft_applopt(t_linfo	**lst, t_sub **sub_lst, char *opt , int p_type) /// Done
{
	int rtn;

	rtn = 0;
	if (ft_checkchar(opt, 'a') != 1)
		rtn = ft_opta(lst, sub_lst, p_type);
	if (p_type == 0 && ft_checkchar(opt, 't') == 1)
		ft_opttdir(sub_lst);
	else if (p_type == 1 && ft_checkchar(opt, 't') == 1)
		ft_optt(lst, 0, 0);
	if (p_type == 0 && ft_checkchar(opt, 'r') == 1)
		ft_optrdir(sub_lst);
	else if (p_type == 1 && ft_checkchar(opt, 'r') == 1)
		ft_optr(lst);
	return (rtn);
}

void	ft_free(t_linfo *headlst, char *p_path) /// Done
{
	if (headlst != NULL)
		ft_lstdellst(&headlst);
	if (p_path != NULL)
		ft_strdel(&p_path);
}

void		ft_ls(int p_type, char *p_opt, char **p_file, int argc) /// Done
{
	int i;

	i = 0;
	if (p_type == 0) /// ls
		ft_remp(".", "");
	else //// ls p_type = 1 && 2
	{
		if (argc == 0)
			ft_remp(".", p_opt);
		else
		{
			while (i < argc)
			{
				if (i > 0)
					ft_putstr("\n");
				if (argc > 1)
					printf("%s:\n", p_file[i]);
				p_opt = (p_opt == NULL) ? "" : p_opt;
				ft_remp(p_file[i], p_opt);
				i++;
			}
		}
	}
}

int		main(int argc,char **argv)  /// Done
{
	int i;
	char *opt;

	i = 1;
	opt = ft_strnew(1);
	if (argc == 1)
		ft_ls(0, NULL, NULL, 0);
	else if (argc > 1)
	{
		while (argv[i] && argv[i][0] == '-')
			opt = ft_strjoir(opt, argv[i++], 0);
		argc = argc - i;
		if (argc > 1)
			ft_sortargv(argc, &argv[i]);
		if (i == 1)
			ft_ls(1, NULL, &argv[1], argc);
		else
			ft_ls(2, opt, &argv[i], argc);
	}
	exit(1);
}
