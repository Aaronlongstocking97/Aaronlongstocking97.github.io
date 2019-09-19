# CS165 Checkpoint 07B

a.out : voxel.o world.o check07b.o
	g++ voxel.o world.o check07b.o
	tar cvf check07b.tar makefile *.h *.cpp

voxel.o : voxel.h voxel.cpp
	g++ -c voxel.cpp

world.o : world.h voxel.h world.cpp
	g++ -c world.cpp

check07b.o : voxel.h world.h check07b.cpp
	g++ -c check07b.cpp

clean :
	rm *.o a.out *.tar
