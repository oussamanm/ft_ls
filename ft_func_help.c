#include "ft_ls.h"

char		*ft_strjoinch(char const *s1, char c) /// Done
{
	char		*new_str;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}

char		*ft_strjoir(char *s1, char *s2, size_t i) /// Done
{
	char		*new_str;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = ft_strnew(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
			*(new_str + i) = *(s1 + i);
	while (++j < s2_len)
		*(new_str + i++) = *(s2 + j);
	return (new_str);
}

int			ft_checkchar(char *str, char c) /// Done
{
	if (!str || !c)
		return (-1);
	while(*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	*ft_perror(char *p_path, char *p_opt)
{
	struct stat sta;

	if (stat(p_path,&sta) != 0)
	{
		perror("./ft_ls  ");
		return (NULL);
	}
	if ((sta.st_mode & S_IFMT) == S_IFLNK)
		ft_rempfile(p_path, p_opt,0);
	else
		ft_rempfile(p_path, p_opt,1);

	return (NULL);
}

int			ft_getstat(struct stat *sta, struct dirent *dr_r, char *new_path) //// Done
{
	int j;

	j = 0;
	if (dr_r->d_type == DT_LNK)
	{
		if (lstat(new_path, sta) != 0)
		{
				perror("error on lstat");
				return (-1);
		}
	}
	else if (stat(new_path, sta) != 0)
	{
		perror("error on stat");
		return (-1);
	}
	return (0);
}
