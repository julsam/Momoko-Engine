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
	  AbstractXml.cpp\
	  ConfigFile.cpp\
	  LaunchOpt.cpp\
	  Asset.cpp\
	  Texture.cpp\
	  ResourceManager.cpp\
	  TextureManager.cpp\
	  Sprite.cpp\
	  Scene.cpp\
	  tests/simple/Simple.cpp

OBJECTS = $(SRC:.cpp=.o)

CXX = g++
TARGET = bin
CXXFLAGS += -W -Wall -g `sdl-config --cflags` -I./
LDFLAGS += -lGL -lGLU -lILUT `sdl-config --libs` #-lSDL_image

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
