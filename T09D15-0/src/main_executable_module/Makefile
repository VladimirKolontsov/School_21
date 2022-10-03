CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = data_io.c data_stat.c data_process.c sort.c decision.c main_executable_module.c
OBJECTS = $(SOURCES: .c = .o)
TARGET = Quest_3
DLIB = ../data_libs/
DMOD = ../data_module/
DYET = ../yet_another_decision_module/
DBLD = ../../build/

all: Quest_3

Quest_3 : data_io.o data_stat.o data_process.o sort.o decision.o main_executable_module.o
	$(CC) $(CFLAGS) data_io.o data_stat.o data_process.o sort.o decision.o main_executable_module.o -o $(DBLD)$(TARGET)

build_with_static: data_io.o data_stat.a data_process.o sort.o decision.o main_executable_module.o
	$(CC) $(CFLAGS) data_io.o data_stat.a data_process.o sort.o decision.o main_executable_module.o -o $(DBLD)Quest_5

build_with_dynamic: data_io.o data_stat.o data_process.so sort.o decision.o main_executable_module.o
	$(CC) $(CFLAGS) data_io.o data_stat.o data_process.so sort.o decision.o main_executable_module.o -o $(DBLD)Quest_6
	mv data_process.so $(DBLD)

data_process.so: data_stat.o data_process.o
	$(CC) $(CFLAGS) -shared data_process.o data_stat.o -o data_process.so

data_io.o:
	$(CC) $(CFLAGS) -c $(DLIB)data_io.c -o data_io.o

data_stat.o:
	$(CC) $(CFLAGS) -c $(DLIB)data_stat.c -o data_stat.o

data_stat.a: data_stat.o
	ar rcs data_stat.a data_stat.o

data_process.o:
	$(CC) $(CFLAGS) -c $(DMOD)data_process.c -o data_process.o

sort.o:
	$(CC) $(CFLAGS) -c sort.c -o sort.o

decision.o:
	$(CC) $(CFLAGS) -c $(DYET)decision.c -o decision.o

main_executable_module.o: 
	$(CC) $(CFLAGS) -c main_executable_module.c -o main_executable_module.o

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf ../../build/*.so
	rm -rf $(DBLD)Quest_3
	rm -rf $(DBLD)Quest_5
	rm -rf $(DBLD)Quest_6

rebuild: clean all