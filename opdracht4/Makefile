

#Example:  HEADERS := include/gamepad.hpp
HEADERS := 

#Example: SOURCE := gamepad
SOURCE :=

CC = g++
CFLAGS = -std=c++17 -DSFML_STATIC -ID:\TI-software\SFML-2.5.1\include

LFLAGS = -LD:\TI-software\SFML-2.5.1\lib
LFLAGS += -std=c++17
LFLAGS += -DSFML_STATIC

LFLAGS += -lXInput

LFLAGS += -lsfml-graphics-s
LFLAGS += -lfreetype

LFLAGS += -lsfml-window-s
LFLAGS += -lgdi32
LFLAGS += -lopengl32

LFLAGS += -lsfml-audio-s

LFLAGS += -lFLAC
LFLAGS += -lvorbisenc
LFLAGS += -lvorbisfile
LFLAGS += -lvorbis
LFLAGS += -logg
LFLAGS += -lopenal32

LFLAGS += -lsfml-network-s
LFLAGS += -lws2_32

LFLAGS += -lsfml-system-s
LFLAGS += -lwinmm

.PHONY: run, clean, debug, build

debug: CFLAGS = -std=c++17 -ggdb -ID:\TI-software\SFML-2.5.1\include
debug: LFLAGS = -LD:\TI-software\SFML-2.5.1\lib -std=c++17 -shared-libgcc -lsfml-graphics-d -lsfml-window-d -lsfml-network-d -lsfml-system-d -lsfml-main-d -lXInput
debug: obj/main.exe

run: build
	@echo Running main.exe
	@./obj/main.exe

build: obj/main.exe
	@echo Succesvol build

#LINKING
obj/main.exe: obj/main.o # obj/$(SOURCE).o
	@echo Linking main.o, $(SOURCE).o to main.exe
	@$(CC) obj/main.o $(LFLAGS) -o obj/main.exe
# @$(CC) obj/main.o obj/$(SOURCE).o $(LFLAGS) -o obj/main.exe 

#COMPILING
obj/main.o: main.cpp $(HEADERS)
	@echo Compiling main.cpp to main.o
	@$(CC) -c main.cpp $(CFLAGS) -o obj/main.o

obj/%.o: %.cpp %.hpp
	@echo Compiling $< to $@
	@$(CC) -c $< $(CFLAGS) -o $@

clean:
	@del obj\*.o obj\*.exe
	@echo removed all .o and .exe files in obj\ directory