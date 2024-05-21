#include "fractol.h"
double atof(const char *nptr)
{
    double res;
    double sign;
    double dec;
    int i;
    double j;

    res = 0;
    sign = 1;
    dec = 0;
    i = 0;
    j = 0;
    while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
        i++;
    if (nptr[i] == '-')
        sign = -1;
    if (nptr[i] == '-' || nptr[i] == '+')
        i++;
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        res = res * 10 + nptr[i] - '0';
        i++;
    }
    if (nptr[i] == '.')
        i++;
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        dec = dec * 10 + nptr[i] - '0';
        i++;
        j++;
    }
    while (j > 0)
    {
        dec = dec / 10;
        j--;
    }
    return (sign * (res + dec));
}
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}