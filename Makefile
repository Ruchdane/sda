all: testElement

CC=gcc
CFLAGS = -g -I header
BINDIR = bin
DISTDIR = dist
OBJECT = element.c file.c list.c
vpath %.h header
vpath test%.c test
vpath %.c src:test
vpath %.o $(BINDIR)


test%.o: test%.c | $(BINDIR) sda.h
	$(CC) -c $(CFLAGS) -o bin/$@ $^ 

%.o: %.c | $(BINDIRminunit.h )
	$(CC) -c $(CFLAGS) -o bin/$@ $^ 

distribution: | $(DISTDIR)
	$(CC) -fPIC -c -g -I ../header  ../src/element.c ../src/file.c ../src/list.c
	gcc -shared -o libsda.so *.o
	sudo cp libsda.so /usr/local/lib/
	sudo cp header/sda.h /usr/local/include/

testElement: testElement.o element.o minunit.h | $(BINDIR)
	$(CC) $(CFLAGS) -o bin/$@ bin/testElement.o bin/element.o
# ././bin/testElement

testList: testList.o element.o list.o minunit.h | $(BINDIR)
	$(CC) $(CFLAGS) -o bin/$@ bin/testList.o bin/element.o bin/list.o
# ././bin/testList


testFile: testFile.o element.o file.o minunit.h | $(BINDIR)
	$(CC) $(CFLAGS) -o bin/$@ bin/testFile.o bin/element.o bin/file.o
# ././bin/testFile

testPile: testPile.o element.o pile.o minunit.h | $(BINDIR)
	$(CC) $(CFLAGS) -o bin/$@ bin/testPile.o bin/element.o bin/pile.o
# ././bin/testPile

$(BINDIR):
	mkdir $(BINDIR)
$(DISTDIR):
	mkdir $(DISTDIR)
	
.PHONY : clean
clean :
	-rm -r bin