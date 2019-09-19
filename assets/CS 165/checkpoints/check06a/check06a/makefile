# CS165 Checkpoint 06A

a.out: robot.o point.o check06a.o
	g++ robot.o point.o check06a.o

robot.o: robot.cpp robot.h point.h
	g++ -c robot.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

check06a.o: check06a.cpp robot.h
	g++ -c check06a.cpp

clean:
	rm *.o
	rm *.out
