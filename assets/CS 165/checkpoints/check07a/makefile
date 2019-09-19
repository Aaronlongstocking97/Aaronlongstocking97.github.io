# CS165 Checkpoint 07A

a.out : icecream.o check07a.o
	g++ icecream.o check07a.o
	tar cvf check07a.tar makefile *.cpp *.h

icecream.o : icecream.h icecream.cpp
	g++ -c icecream.cpp

check07a.o : icecream.h check07a.cpp
	g++ -c check07a.cpp

clean :
	rm *.o a.out *.tar
