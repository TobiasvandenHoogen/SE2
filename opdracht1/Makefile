GXX := g++ --std=c++17
MAINFLAGS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

HEADERS := drawable.hpp ball.hpp boundary.hpp beam.hpp

OBJECTS := $(SOURCES:%.cpp=%.o)

main: main.o $(OBJECTS) $(HEADERS)
	$(GXX) main.o $(OBJECTS) $(MAINFLAGS) -o main.exe

main.o: main.cpp
	$(GXX) -c main.cpp -o main.o

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(GXX) -c $< -o $@

.PHONY: clean build run

clean:
	@echo "Cleaning up files"
	rm $(OBJECTS) main.o main.exe

build: main

run: main
	@echo "Running application"
	@./main.exe