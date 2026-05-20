#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define FILEP "input/input.txt"

int main(int argc, char *argv[])
{
	char buf[32];
	int size, fd, len;

	if(argc != 2) {
		fprintf(stderr, "Usage: %s <length> \n", argv[0]);
		exit(EXIT_FAILURE);
	}	

	size = atoi(argv[1]);
	if((fd = open(FILEP, O_CREAT | O_TRUNC | O_RDWR, 0777)) < 0) {
		perror("open error");
		exit(EXIT_FAILURE);
	}
	
	len = sprintf(buf, "%d\n", size);
	
	write(fd, buf, len); 
	srand(time(NULL));
	for(int i = 0; i < size; i++) {
		len = sprintf(buf, "%d ", (rand() % size) + 1);
		if(write(fd, buf, len) < 0)
			perror("write error");
	}
	fprintf(stderr, "Generated %d random numbers !\n", size);
	close(fd);

	return EXIT_SUCCESS;
}
