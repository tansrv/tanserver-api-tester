CC = g++
SRCS := $(patsubst %.cpp,%.o,$(wildcard *.cpp)) $(patsubst %.c,%.o,$(wildcard *.c))
libs = -lssl -lcrypto

apitester: $(SRCS)
	$(CC) -o $@ $^ $(libs)
	rm *.o