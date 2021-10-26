#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>

int rand_num() {
	int in = open("/dev/random", O_RDONLY);
	int rd = 0;
	read(in, &rd, 4);
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
		printf("\t\t random %d: %d\n", j, a[j]);
	}
	
	printf("Writing numbers to file...\n");
	int op = open("result.txt", O_CREAT | O_RDWR, 0644);
	write(op, a, 40);
	
	printf("Reading numbers to file...\n");
	int result[10];
	read(op, result, 40);
	
	printf("Verification that written values were the same:\n");
	for(j = 0; j < 10; j++) {
		printf("\t\t random %d: %d\n", j, result[j]);
	}
	
}
