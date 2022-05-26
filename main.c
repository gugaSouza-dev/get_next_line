#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int    main(void)
{
    int     fd;

    // Pedir ao sistema um identificador númerico(fd) que representa o arquivo
    fd = open("./file.txt", O_RDONLY);
    printf("fd = %d\n", fd);
	for (int i=0; i < 5; ++i)
	{
		printf("final return = %s", get_next_line(fd));
	}
	return (0);
}