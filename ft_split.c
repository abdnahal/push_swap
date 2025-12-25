
#include "push_swap.h"

int	is_set(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_set(str[i], charset))
		{
			i++;
		}
		if (str[i] && !is_set(str[i], charset))
		{
			count++;
		}
		while (str[i] && !is_set(str[i], charset))
		{
			i++;
		}
	}
	return (count);
}

int	count_all(char **arr, char *str, char *charset)
{
	int i, (k), (count);
	i = 0;
	k = 0;
	while (str[i])
	{
		while (is_set(str[i], charset))
		{
			i++;
		}
		count = 0;
		while (str[i] && !is_set(str[i], charset))
		{
			count++;
			i++;
		}
		arr[k] = malloc(sizeof(char) * (count + 1));
		if (arr[k] == NULL)
		{
			return (0);
		}
		k++;
	}
	return (1);
}

void	fill_arr(char **arr, char *str, char *charset)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && is_set(str[i], charset))
		{
			i++;
		}
		j = 0;
		while (str[i] && !is_set(str[i], charset))
		{
			arr[k][j] = str[i];
			i++;
			j++;
		}
		arr[k][j] = '\0';
		if (j != 0)
			k++;
	}
	arr[k] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	int		count;
	char	**arr;

	count = count_words(str, charset);
	arr = malloc((count + 1) * sizeof(char *));
	if (arr == NULL)
	{
		return (NULL);
	}
	count_all(arr, str, charset);
	fill_arr(arr, str, charset);
	return (arr);
}
