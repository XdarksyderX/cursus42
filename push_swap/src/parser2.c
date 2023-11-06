/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:18:28 by migarci2          #+#    #+#             */
/*   Updated: 2023/11/06 19:18:30 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
