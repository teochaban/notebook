all: 
  g++ -std=c++0x $(f).cpp -o $(f) -O2




# TO DEBUG USE THIS:

all:
	./gen > outGen
	cat outGen
	./a < outGen > outTest
	cat outTest
	./tester < outTest
	make all


# srand(time(NULL)) // but this is in seconds

# struct timespec ts;
# clock_gettime(CLOCK_MONOTONIC, &ts);
# srand((time_t)ts.tv_nsec);	// using nano-seconds instead of seconds 