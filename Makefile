main.o: main.c
	gcc -c main.c -o main.o

pqueue.o: priorityqueue.c
	gcc -c priorityqueue.c -o pqueue.o

pqueue: main.o pqueue.o
	gcc main.o pqueue.o -o pqueue

run: pqueue
	.\pqueue

clean:
	del *.o pqueue.exe