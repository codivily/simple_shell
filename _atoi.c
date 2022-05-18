/**
 *_atoi - convert a string to integer
 *@s: A string
 *
 *Return: An integer
 */
int _atoi(char *s)
{
	int ret = 0;
	int i = 0;
	int sign = 1;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;

	for (; s[i] != '\0'; ++i)
		ret = ret * 10 + s[i] - '0';

	return (ret * sign);
}
