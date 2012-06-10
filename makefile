INCLUDES = `mysql_config --include`
LIBS = `mysql_config --libs`

turnActivityOver: main.o
	gcc $(CFLAGS) -o turnActivityOver main.o $(LIBS)
main.o: main.c
	gcc $(CFLAGS) -c $(INCLUDES) main.c
clean:
	rm -f *.o turnActivityOver
