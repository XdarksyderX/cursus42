#include "../../inc/helpers.h"

int	ft_strlen_protected(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && (str[i] == '1' || str[i] == '0' || str[i] == 'P'
			|| str[i] == 'E' || str[i] == 'C'))
		i++;
	return (i);
}
