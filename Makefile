#Defining how we want to compile
CFLAGS= -g -Wall
#Defining variables
EXE=find_A2020316
OBJS = find_A2020316.o

#rule all calls exe (this will be all less clean)
all: find_A2020316

#exe calls objs and links the result files
find_A2020316: $(OBJS)
	gcc -o $(EXE) $(OBJS)

#objs looks for exe.c and compiles
find_A2020316.o: find_A2020316.c
	gcc $(CFLAGS) -c find_A2020316.c

#rule for cleaning exe and objs generated files
clean:
	rm -f $(EXE) $(OBJS)

