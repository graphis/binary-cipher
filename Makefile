CPP = g++
CPP_FLAGS = -Wall
OBJS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

all: binary-cipher
	@echo "\n ===== Done! =====\n"

binary-cipher: $(OBJS)
	$(CPP) $(CPP_FLAGS) $^ -o $@

%.o: %.cpp $(wildcard *.hpp)
	$(CPP) $(CPP_FLAGS) -c $< -o $@
	
clean:
	rm -v *.o

.PHONY: all
.PHONY: clean
