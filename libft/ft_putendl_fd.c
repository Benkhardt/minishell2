
#include "libft.h"

/*
* Write 1 character + 1 return on the file descriptor
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}
