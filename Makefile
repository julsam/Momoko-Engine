.SUFFIXES:

OBJDIR = obj/
BIN = bin

SRC = src/main.cpp\
	  src/Engine.cpp\
	  src/Config.cpp\
	  src/Config.cpp\
	  src/Window.cpp\
	  src/Event.cpp\
	  src/Input.cpp\
	  src/Vector2.cpp\
	  src/Graphics.cpp\
	  src/LogManager.cpp\
	  src/Utils.cpp\
	  src/Tools.cpp\
	  src/AbstractXml.cpp\
	  src/ConfigFile.cpp\
	  src/LaunchOpt.cpp\
	  src/Asset.cpp\
	  src/Texture.cpp\
	  src/ResourceManager.cpp\
	  src/TextureManager.cpp\
	  src/Sprite.cpp\
	  src/Scene.cpp\
	  src/tests/simple/Simple.cpp

OBJECTS = $(SRC:.cpp=.o)

CXX = g++
TARGET = $(OBJDIR)$(BIN)
CXXFLAGS += -W -Wall -g `sdl-config --cflags` -I./
LDFLAGS += -lGL -lGLU -lILUT `sdl-config --libs` #-lSDL_image

all:$(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $(TARGET) $(LDFLAGS) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY: clean, mrproper

clean:
	rm -f src/*.o

mrproper : clean
	rm -f $(TARGET)
