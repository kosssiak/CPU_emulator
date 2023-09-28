CC = g++

CFLAGS = -Werror -Wpedantic -Wextra

SRC_CPU = CPU/CPU.cpp CPU/service.cpp lib/cmdslib.cpp lib/stack.cpp lib/verificator.cpp 

Processor = cpu

all: $(Processor) $(SRC_CPU)

$(Processor): $(SRC_CPU)
	$(CC) $(SRC_CPU) $(CFLAGS) -o $(Processor)

clean:
	rm -rf $(Processor) *.o
