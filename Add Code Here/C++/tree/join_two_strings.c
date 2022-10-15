#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = strlen(s1) + strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		str[a] = s1[a];
		a++;
	}
	b = 0;
	while (s2[b] != '\0')
	{
		str[a] = s2[b];
		a++;
		b++;
	}
	str[a] = '\0';
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
    {
		printf("You must introduce executable plus two strings between quotes and separate by a space (example: ./a.out \"Hello World\" \"from here\")\n");
        exit (0);
    }
    printf("Lets join the two strings --> %s\n", ft_strjoin(argv[1], argv[2]));
	return (0);
}
