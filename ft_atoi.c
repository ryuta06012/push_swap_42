#include "push_swap.h"

static int	ft_isdigit(int num)
{
	if ((num >= '0') && (num <= '9'))
		return (1);
	else
		return (0);
}

static int	ft_strncmp (const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

static int	num_len(const char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(*str++))
		i++;
	return (i);
}

static bool	is_overflow(const char *nptr, int sign)
{
	if (num_len(nptr) > 10)
		return (true);
	if (num_len(nptr) == 10)
	{
		if (sign == -1 && ft_strncmp(nptr, "2147483648", 10) > 0)
			return (true);
		if (sign == 1 && ft_strncmp(nptr, "2147483647 ", 10) > 0)
			return (true);
	}
	return (false);
}

bool	my_atoi(const char *nptr, int *num)
{
	int		sign;

	*num = 0;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	if (is_overflow(nptr, sign))
		return (false);
	while (*nptr)
	{
		if (ft_isdigit(*nptr))
			*num = *num * 10 + (*nptr++ - '0');
		else
			return (false);
	}
	*num *= sign;
	return (true);
}
