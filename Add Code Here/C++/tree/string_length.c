#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
    {
		printf("You must introduce executable plus the string between quotes (example: ./a.out \"Hello World\")\n");
        exit (0);
    }
    printf("The length of your string is --> %zu\n", ft_strlen(argv[1]));
	return (0);
}