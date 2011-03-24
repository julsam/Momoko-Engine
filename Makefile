.SUFFIXES:

SRC = main.cpp\
	  Engine.cpp\
	  Config.cpp\
	  Window.cpp\
	  Event.cpp\
	  Input.cpp\
	  Vector2.cpp\
	  Graphics.cpp\
	  LogManager.cpp\
	  Utils.cpp\
	  Tools.cpp\
	  ConfigFile.cpp\
	  LaunchOpt.cpp\

OBJECTS = $(SRC:.cpp=.o)

CXX = g++
TARGET = bin
CXXFLAGS += -W -Wall -g `sdl-config --cflags` -I./
LDFLAGS += -lGL -lGLU -lILUT `sdl-config --libs` -lSDL_image #sdl_image maybe useless, we'll see

all:$(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $(TARGET) $(LDFLAGS) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY: clean, mrproper

clean:
	rm -f *.o

mrproper : clean
	rm -f $(TARGET)
