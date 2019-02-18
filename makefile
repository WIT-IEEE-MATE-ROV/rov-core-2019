objects = ../comms/nugget-api.o ../rov-core/rov-util.o ../rovlog/rovlog.o 
objects2 = ../comms/nugget-api.o ../rovlog/rovlog.o 
stdflag = -g -Wall -Wextra -L. -I. -lm -Wl,-unresolved-symbols=ignore-in-shared-libs

master :
	gcc rovmain.c -o rovmain $(objects) $(stdflag)

rovutil :
	gcc -c rov-util.c $(objects)  $(stdflag)

spawntest :
	gcc test-child.c rov-util.c -o test-child $(objects2) $(stdflag)
	gcc test-parent.c rov-util.c -o test-parent $(objects2) $(stdflag)
	
	./test-parent
