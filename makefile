all: work11.o
	gcc -o work11 work11.o
work09.o: work11.c
	gcc -c work11.c
run:
	./work11
clean:
	rm *.o
	rm result.txt
	rm work11
