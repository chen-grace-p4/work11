#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>

int rand_num() {
	int in = open("/dev/random", O_RDONLY);
	unsigned int rd = 0;
	read(in, &rd, sizeof(&rd));
	return rd;
}

int main() {
	printf("Generating random numbers:\n");
	int a[10];
	int i;
	for (i = 0; i < 10; i++) {
		int r = rand_num();
		a[i] = r;
	}
	int j;
	for(j = 0; j < 10; j++) {
		printf("\t\t random %u: %u\n", j, a[j]);
	}

	printf("Writing numbers to file...\n");
	int op = open("result.txt", O_CREAT | O_RDWR, 0644);
	//int op = open("result.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	//int op = open("result.txt", O_CREAT, 0);
	write(op, a, sizeof(a));

	printf("Reading numbers to file...\n");
	int result[10];
	read(op, result, sizeof(result));

	printf("Verification that written values were the same:\n");
	for(j = 0; j < 10; j++) {
		printf("\t\t random %u: %u\n", j, result[j]);
	}

}
