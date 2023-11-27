#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int fd = open("test", O_RDONLY);
	// int fd = open("test", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	free (str);
	// for (int n = 0; n < 1; n++)
	// {
	// 	str = get_next_line(fd);
	// 	printf("%s", str);
	// 	free (str);
	// }
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	return (0);
}