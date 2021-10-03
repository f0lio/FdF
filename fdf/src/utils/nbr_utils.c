
#include "fdf.h"


int str_hex_to_int(const char *hex)
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
        {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
		i--;
    }
	return (decimal);
}

int		str_to_int(const char *str)
{
    int		i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
	{
		sign = -1;
		i++;
	}
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		num = num * 10 + (*(str + i++) - '0');
	return (num * sign);
}

int		nbr_len(long i)
{
	int		len;

	if (i <= 9 && i >= -9)
		return (1 + (i < 0));
    len = i < 0;
	i += ((i < 0) * i * -1) || i;
	while (i && ++len)
		i /= 10;
	return (len);
}

float get_max(float a, float b)
{
    if (a > b)
        return a;
    return b;
}
