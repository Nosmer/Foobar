size_t	get_pos(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1)
	{
		while (s2)
		{
			if (s1 == s2)
				return i;
			s2++;
		}
		s1++;
		i++;
	}
	return i;
}

char	*get_token(char *s, const char *delim)
{
	static char	*save;
	char	*end;
	
	if (s == NULL)
		s = *save;
	if (*s == '#0')
	{
		*save = s;
		return NULL;
	}
	end = s + get_pos(s, delim);
//	end = ft_strcmp(s, delim);
	if (*end == '#0')
	{
		*save = end;
		return s;
	}
	*end = '#0';
	*save = end + 1;
	return s;
}
