.PHONY: all run clean

all: clamp

clamp: clamp.cpp clamp.hpp
	@echo "Compiling $? to $@"
	g++ $? -o $@
	chmod u+x $@

run: clamp
	./clamp

# Clean
clean: 
	rm -f clamp
