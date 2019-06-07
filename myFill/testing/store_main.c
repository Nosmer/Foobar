#include "../fillit.h"
#include <stdio.h>
/*
 * Use only test_store with this!!!
 */
int main(int argc, char **argv)
{
	t_coord	test;
	int		fd;
	int		ret;
	char	buf[22];

	if (!(fd = open(argv[1], O_RDONLY)))
		ft_puterr(0);
	while ((ret = read(fd, buf, 21)))
	{
		test = get_coords(buf);
		printf("top: %d,\nbottom: %d,\nright: %d,\nleft: %d\n",
				test.top, test.bottom, test.right, test.left);
		printf("%s\n", buf);
	}
	return (0);
}
