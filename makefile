rov :
	gcc include/rovcore.c include/rovsim.c rovmain.c -o rovmain -g -Wall -Wextra -L. -Iinclude/

test : 
	gcc rovtest.c -o rovtest -g -Wall -Wextra
	./rovtest

clean :
	rm -f ./rovtest
	rm -f ./rovmain

rovmode :
	gcc rovmain.c -o rovmain-rovmode -DDEF=ROVMODE -g -Wall -Wextra -L.

rovmodetest: 
	gcc include/rovcore.c include/rovonly.c rovmain.c -o rovmain -g -Wall -Wextra -L. -Iinclude/ -DROVMODE

upload :
	make rovmode
	scp ./rovmain-rovmode nugget@spacenugget.local:/opt/rovmain

