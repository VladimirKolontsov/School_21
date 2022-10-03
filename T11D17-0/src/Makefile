CC_CFLAGS = gcc -Wall -Wextra -Werror
DBLD = ../build/

all: Quest_1

Quest_1: dmanager_module.o
	$(CC_CFLAGS) dmanager_module.o -o $(DBLD)Quest_1

list_test: list.o list_test.o
	$(CC_CFLAGS) list.o list_test.o -o $(DBLD)Quest_2

list_test.o: list_test.c
	$(CC_CFLAGS) -c list_test.c -o list_test.o

list.o: list.c
	$(CC_CFLAGS) -c list.c -o list.o

dmanager_module.o:
	$(CC_CFLAGS) -c dmanager_module.c -o dmanager_module.o

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf $(DBLD)Quest_1

rebuild: clean all