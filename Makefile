all: project
	./project
project : libmanagement.o xtras.o
	cc libmanagement.o xtras.o -o project
libmanagement.o: libmanagement.c
	cc -c libmanagement.c
xtras.o: xtras.c
	cc -c xtras.c
clean:
	rm -rf *o project 
				
