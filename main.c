#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int    main(void)
{
    int     fd;
	char	*str = "";
	// int		repeat = -1;

    // PRECISO DAR FREE NA STATIC?
	fd = open("./file.txt", O_RDONLY);
    printf("fd = %d\n", fd);
	// while (repeat++ <= 10)
	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}