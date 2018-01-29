CXX	= g++
CXXFLAGS= -Wall -std=c++17
LDFLAGS	= -g -pthread
LDLIBS	= -lrt -I/usr/include/allegro5 -L/usr/lib -lallegro -lallegro_image -lallegro_primitives -lallegro_font#`pkg-config --libs allegro-5.0 allegro_image-5.0 allegro_primitives-5.0 allegro_font-5.0`

SRC_DIR   = ./
BUILD_DIR = ../build
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

.PHONY: default clean setupDir
default: setupDir prog

prog: $(OBJ_FILES)
	cd $(BUILD_DIR) && g++ $(LDFLAGS) -o $@ $^ $(LDLIBS)
	mv $(BUILD_DIR)/prog ../prog

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CXXFLAGS) $(CXXFLAGS) -c -o $@ $<

setupDir:
	if [ ! -d $(BUILD_DIR) ]; then \
		mkdir ../build; \
	fi

clean:
	if [ -d $(BUILD_DIR) ]; then \
		cd $(BUILD_DIR) && rm -rf *.o \
		rmdir $(BUILD_DIR); \
	fi
	cd ./include && rm -rf *.gch
