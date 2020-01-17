SORT: SORT.o header.o
		gcc -g -o sort SORT.o header.o
SORT.o: SORT.c header.h
		gcc -g -c SORT.c
header.o: header.c header.h
		gcc -g -c header.c
c:
	rm *.o
