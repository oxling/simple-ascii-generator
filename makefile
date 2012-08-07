COMPILE=gcc
CFLAGS=-std=gnu99 -c

all: asciigenerator

asciigenerator: main.o bitmap.o letter.o
	${COMPILE} main.o bitmap.o letter.o -o asciigenerator

bitmap.o: bitmap.c
	${COMPILE} ${CFLAGS} bitmap.c

letter.o: letter.c
	${COMPILE} ${CFLAGS} letter.c

main.o: main.c
	${COMPILE} ${CFLAGS} main.c

clean:
	rm -rf *o asciigenerator