CXX	= g++
CXXFLAGS= -Wall -std=c++17
LDFLAGS	= -g
LDLIBS	=

SRC_DIR   = ./
BUILD_DIR = ../build
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

.PHONY: default clean setupDir
default: setupDir prog

prog: $(OBJ_FILES)
	cd $(BUILD_DIR) && g++ $(LDFLAGS) -o $@ $^
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
