rov :
	gcc rov-util.c rovmain.c -o rovmain -g -Wall -Wextra -L. -I.

test : 
	gcc rovtest.c -o rovtest -g -Wall -Wextra
	./rovtest

clean :
	rm -f ./rovtest
	rm -f ./rovmain

rovmode :
	gcc include/rovcore.c include/rovonly.c rovmain.c -o rovmain_rovmode -DDEF=ROVMODE -g -Wall -Wextra -L. -march=armv6

rovmodetest: 
	gcc include/rovcore.c include/rovonly.c rovmain.c -o rovmain -g -Wall -Wextra -L. -Iinclude/ -DROVMODE

upload :
	make rovmode
	scp ./rovmain-rovmode nugget@spacenugget.local:/opt/rovmain
	ssh nugget@spacenugget.local 'systemctl restart nugget'


