
#include "libft.h"

/*
* Write 1 character on the file descriptor
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
