#include "ft_ls.h"

char		ft_gettype(mode_t mod) /// Done
{
	if (!mod)
		return (' ');
	mod = mod & S_IFMT;
	if (mod == S_IFDIR)
		return('d');
	else if (mod == S_IFBLK)
		return('b');
	else if (mod == S_IFCHR)
		return('c');
	else if (mod == S_IFIFO)
		return('p');
	else if (mod == S_IFLNK)
		return('l');
	else if (mod == S_IFREG)
		return('-');
	else if (mod == S_IFSOCK)
		return('s');
	else
		return('-');
}
char		*ft_getmode(mode_t mod) /// Done
{
	char *resu;

	resu = ft_strnew(12);
	resu[0] = ft_gettype(mod);
	resu[1] = (((mod & S_IRUSR)  ? 'r' : '-'));
	resu[2] = ((mod & S_IWUSR) ? 'w' : '-');
	resu[3] = ((mod & S_IXUSR) ? 'x' : '-');
	resu[4] = (((mod & S_IRGRP)  ? 'r' : '-'));
	resu[5] = ((mod & S_IWGRP) ? 'w' : '-');
	resu[6] = ((mod & S_IXGRP) ? 'x' : '-');
	resu[7] = (((mod & S_IROTH)  ? 'r' : '-'));
	resu[8] = ((mod & S_IWOTH) ? 'w' : '-');
	resu[9] = ((mod & S_IXOTH) ? 'x' : '-');
	resu[10] = '\0';
	if (resu != NULL)
		return (resu);
	else
		return (NULL);
}
char		*ft_gettime_m(int tmsec, struct new_tm *f_time, char *str_time) /// Done
{
	char	*s;

	s = ft_strnew(14);
	if (strlen(str_time) > 24)
	{
		f_time->mon = ft_strnew(5);
		f_time->i_day = ft_strnew(4);
		f_time->hor = ft_strnew(4);
		f_time->min = ft_strnew(4);
		f_time->sec = ft_strnew(4);
		f_time->year = ft_strnew(5);
		ft_strcat(s, ft_strncpy(f_time->mon, &str_time[4], 4));
		ft_strcat(s, ft_strncpy(f_time->i_day, &str_time[8], 3));
		ft_strcat(s, ft_strncpy(f_time->hor, &str_time[11], 3));
		ft_strcat(s, ft_strncpy(f_time->min, &str_time[14], 3));
		ft_strncpy(f_time->sec, &str_time[17], 3);
		ft_strncpy(f_time->year, &str_time[20], 4);
		f_time->times = tmsec;
	}
	s[12] = '\0';
	return (s);
}
int			ft_addlinkname(char *p_path, char *d_name, char **l_name) /// Done
{
	ssize_t		i;

	ft_strcat(*l_name, " -> ");
	i = readlink(ft_strjoir(p_path, d_name, -1), &(*l_name)[ft_strlen(*l_name)], 250);
	if (i < 0)
	{
		perror("error in readlink \n");
		return (-1);
	}
	else
		return (0);
}
void		ft_fillsize(struct stat *sta, int *l_s1, int *l_s2) /// Done
{
	if ((sta->st_mode & S_IFMT) == S_IFCHR || (sta->st_mode & S_IFMT) == S_IFCHR)
	{
		*l_s1 = major(sta->st_rdev);
		*l_s2 = minor(sta->st_rdev);
	}
	else
		*l_s1 = sta->st_size;
}
