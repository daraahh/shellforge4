/* 
 * ShellForge example: list a directory
 * It uses the deprecated readdir syscall not supported by a lot of architectures.
 * If you want more details you can check: https://github.com/whatsbcn/shellforge4/issues/5
 * $Id$
 */


#define DIRECTORY "/"

int main(void)
{
	int fd;
	struct dirent d;
	int l;

	write(1,"go[",3);

	fd = open(DIRECTORY, O_RDONLY, 0);
	if (fd < 0) 
		write(1,"error",5);
	else {
		while (readdir(fd, &d, 1)) {
			for(l = 0; d.d_name[l]; l++);
			write(1, d.d_name, l);
			write(1, "\r\n", 2);
		}
	}
	write(1,"]og",4);

	exit(0);
}
