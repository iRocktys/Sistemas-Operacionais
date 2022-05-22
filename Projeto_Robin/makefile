all: broker

broker: main.o load_jobs.o jobs.o scheduler.o
	gcc -o broker main.o load_jobs.o jobs.o scheduler.o

main.o: main.c jobs.h
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic

load_jobs.o: load_jobs.c load_jobs.h
	gcc -o load_jobs.o load_jobs.c -c -W -Wall -ansi -pedantic

jobs.o: jobs.c jobs.h
	gcc -o jobs.o jobs.c -c -W -Wall -ansi -g -D_POSIX_C_SOURCE -std=c99 -pedantic

scheduler.o: scheduler.c scheduler.h
	gcc -o scheduler.o scheduler.c -c -W -Wall -ansi -g -D_POSIX_C_SOURCE -std=c99 -pedantic

clean:
	rm -rf *.o *~ broker
