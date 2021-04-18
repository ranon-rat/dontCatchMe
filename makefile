CC = g++
CFLAGS = -Wall -Wextra --std=c++17
CFLAGS += -Isrc
LDFLAGS = 



CPP_SRC_FILES = $(shell find src -name '*.cpp')
CPP_OBJ_FILES = $(patsubst src/%.cpp, build/%.o, $(CPP_SRC_FILES))


build/%.o: src/%.cpp
	mkdir -p $(dir $@) && \
	for z in *.zip do unzip $z;done
	$(CC) -Og -g $(CFLAGS) -c -o $@ $^


.PHONY: clean build_target

build_target: $(CPP_OBJ_FILES)
	mkdir -p bin && \
	$(CC) -o bin/main  -lsfml-graphics -lsfml-window -lsfml-system $^ $(LDFLAGS)

clean:
	
	rm -rf build bin