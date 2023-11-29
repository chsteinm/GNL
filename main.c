#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	//int fd = open("test", O_RDONLY);
	//int fd = open("/home/chrstein/francinette/tests/get_next_line/fsoares/read_error.txt", O_RDONLY);
	int fd = open("gnlTester/files/multiple_nlx5", O_RDONLY);
	// int fd = open("test", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	free (str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free (str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free (str);


	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	

	for (int n = 0; n < 3; n++)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
	}
	// while (str)
	// {
	// 	str = get_next_line(fd);
	// 	printf("%s", str);
	// 	free (str);
	// }
	// str = get_next_line(fd);
	// printf("%s", str);
	// free (str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free (str);
	close(fd);
	return (0);
}