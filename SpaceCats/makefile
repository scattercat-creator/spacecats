#OBJ specifies which files to compile as part of the project
OBJ = gamefiles/main.cpp gamefiles/funcs.cpp gamefiles/textures.cpp gamefiles/dialogue.cpp gamefiles/sceneManager.cpp gamefiles/scriptReader.cpp gamefiles/userInputManager.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifices the additional include paths we'll need
INCLUDE_PATHS = -I src/include 

#LIBRARY_PATHS specifies the additional library paths we'll be including
LIBRARY_PATHS = -L src/lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# COMPILER_FLAGS = -w -Wl, -subsystem, windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

#OBJ_NAME specifies the anme of our executable
OBJ_NAME = main



all: $(OBJ)
	$(CC) $(OBJ) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $(OBJ_NAME)
#	g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2