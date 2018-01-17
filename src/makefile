CXX	= g++
CXXFLAGS= -Wall
LDFLAGS	= -g
LDLIBS	=

FILES	= main
BUILD_DIR = ../build

.PHONY: default clean setupDir
default: prog

prog: setupDir $(FILES).o
	cd $(BUILD_DIR) && $(CXX) $(LDFLAGS) $(FILES).o -o prog $(LDLIBS)
	mv $(BUILD_DIR)/prog ../prog

$(FILES).o: $(FILES).cpp
	$(CXX) $(CXXFLAGS) -c $(FILES).cpp && mv $(FILES).o $(BUILD_DIR)/$(FILES).o

setupDir:
	if [ ! -d $(BUILD_DIR) ]; then mkdir ../build; fi

clean:
	cd ../build && rm -rf *.o
	rmdir ../build
