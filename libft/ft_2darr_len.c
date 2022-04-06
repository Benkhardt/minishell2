
int	ft_2darr_len(char **arr2d)
{
	int	i;

	i = 0;
	while (arr2d[i])
		i++;
	return (i);
}
