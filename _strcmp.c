/**
 *_strcmp - case sensitive compare two string
 *@s1: A string
 *@s2: A string
 *
 *Return: 0 if s1 same as s2 else different than zero
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;
	int ret = 0;

	if (!s1 || !s2)
		return (-1);

	while (s1[i] && s2[i])
	{
		ret = s1[i] - s2[i];
		if (ret != 0)
			return (ret);
		i++;
	}

	return (0);
}
