
#include "libft.h"

/*
* Write a string on the file descriptor
*/

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
