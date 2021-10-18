all: testElement

CC=gcc
CFLAGS = -g -I header
BINDIR = bin

vpath %.h header
vpath test%.c test
vpath %.c src:test
vpath %.o $(BINDIR)

objects := element.o testElement.o
tests = testElement.o

test%.o: test%.c | $(BINDIR) sda.h
	$(CC) -c $(CFLAGS) -o bin/$@ $^ 

%.o: %.c | $(BINDIR) minunit.h
	$(CC) -c $(CFLAGS) -o bin/$@ $^ 


testElement: testElement.o element.o | minunit.h $(BINDIR)
	$(CC) $(CFLAGS) -o bin/$@ bin/testElement.o bin/element.o
	././bin/testElement

testList: testList.o element.o list.o | minunit.h $(BINDIR)
	$(CC) $(CFLAGS) -o bin/$@ bin/testList.o bin/element.o bin/list.o
	././bin/testList


testFile: testFile.o element.o file.o | minunit.h $(BINDIR)
	$(CC) $(CFLAGS) -o bin/$@ bin/testFile.o bin/element.o bin/file.o
	././bin/testFile

$(BINDIR):
	mkdir $(BINDIR)

.PHONY : clean
clean :
	-rm -r bin