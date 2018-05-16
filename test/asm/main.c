#include <unistd.h>
#include <fcntl.h>
#include "op.h"
#include <string.h>

typedef union	u_int {
	struct s_int {
		unsigned char B4:8;
		unsigned char B3:8;
		unsigned char B2:8;
		unsigned char B1:8;
	} byte;
	unsigned int value;
} t_int;

void	write_int(int fd, int val)
{
	t_int s;
	s.value = val;
	val = s.byte.B1;
	write(fd, &val, 1);
	val = s.byte.B2;
	write(fd, &val, 1);
	val = s.byte.B3;
	write(fd, &val, 1);
	val = s.byte.B4;
	write(fd, &val, 1);
}

void	write_16(int fd, int val)
{
	t_int s;
	s.value = val;
	val = s.byte.B3;
	write(fd, &val, 1);
	val = s.byte.B4;
	write(fd, &val, 1);
}

int		main_2()
{
	int op = 0x04;

	int fd = open("test.txt", O_CREAT | O_RDWR | O_TRUNC, 0777);
	write(fd, &op, 1);
	write_16(fd, 0x1234);
	close(fd);
	return (0);
}

int		main_1()
{
	int op = 0x04;

	int fd = open("test.txt", O_CREAT | O_RDWR | O_TRUNC, 0777);
	write(fd, &op, 1);
	write_int(fd, 0x12345678);
	close(fd);
	return (0);
}

int		main()
{
	int fd = open("test.txt", O_CREAT | O_RDWR | O_TRUNC, 0777);
	int zero = 0;
	int op = 0x04;
	int data = 0x00010203;
	int size = 5;

	char name[PROG_NAME_LENGTH];
	memset(name, 0, PROG_NAME_LENGTH);
	
	char com[COMMENT_LENGTH];
	memset(com, 0, COMMENT_LENGTH);

	name[0] = '4';
	name[1] = '2';
	com[0] = 'c';
	com[1] = 'o';
	com[2] = 'm';

	/*exec magic 4 octets*/
	write_int(fd, COREWAR_EXEC_MAGIC);
	/*name 128 octets*/
	write(fd, name, PROG_NAME_LENGTH);
	/*padding 4 octets*/
	write(fd, &zero, 4);
	/*size code 4 octets*/
	write_int(fd, size);
	/*comment 2048 octets*/
	write(fd, com, COMMENT_LENGTH);
	/*padding 4 octets*/
	write(fd, &zero, 4);
	/*code : max 686 octets*/
	write(fd, &op, 1);
	write_int(fd, data);

	/*end*/
	close(fd);
	return (0);
}
