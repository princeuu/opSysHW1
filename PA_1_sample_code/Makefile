all: mp3

mp3: main.o add.o print.o freeList.o
	gcc -g main.o add.o print.o freeList.o -o mp3

main.o: main.c mp3.h
	gcc -g -c main.c

add.o: add.c mp3.h
	gcc -g -c add.c

print.o: print.c mp3.h
	gcc -g -c print.c

freeList.o: freeList.c mp3.h
	gcc -g -c freeList.c

clean:
	\rm *.o mp3

gcc -g -c delete.c
gcc -g main.o add.o print.o freeList.o delete.o -o mp3
