#include "fdf.h"

int	should_multiply(char c)
{
	if ((c >= 'A' && c <= 'F')
		|| (c >= 'a' && c <= 'f')
		|| (c >= '0' && c <= '9'))
		return (16);
	return (1);
}

int	str_hex_to_int(const char *hex)
{
	int		i;
	int		base;
	int		decimal;

	decimal = 0;
	base = 1;
	i = str_len(hex);
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			decimal += (hex[i] - 48) * base;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			decimal += (hex[i] - 55) * base;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			decimal += (hex[i] - 87) * base;
		base *= should_multiply(hex[i]);
		i--;
	}
	return (decimal);
}

int	str_to_int(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == ' ' || *(str + i) == '\t')
		i++;
	if (*(str + i) == '-')
	{
		sign = -1;
		i++;
	}
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		num = num * 10 + (*(str + i) - '0');
		i++;
	}
	return (num * sign);
}

int	nbr_len(long i)
{
	int		len;

	if (i <= 9 && i >= -9)
		return (1 + (i < 0));
	len = 0;
	if (i < 0)
	{
		len = 1;
		i = -i;
	}
	while (i && ++len)
		i /= 10;
	return (len);
}
