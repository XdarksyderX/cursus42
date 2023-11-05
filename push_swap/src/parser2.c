int	ft_exists_in_array(int *array, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == num)
			return (0);
		i++;
	}
	return (1);
}
