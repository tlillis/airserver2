#RECUV Airserver
CROSS_ARCH := arm-openwrt-linux
NATIVE_CXX := g++
CROSS_CXX := $(CROSS_ARCH)-g++
CXXFLAGS := -c -g -Wall $(CXXFLAGS)
LIBS :=
LIB_DIR :=
INCLUDE_DIR := 
SOURCES :=  \
	$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
PROGRAM := airserver

all: $(SOURCES) $(PROGRAM)

$(PROGRAM): $(OBJECTS) 
	$(NATIVE_CXX) $(LIBS) $(OBJECTS) -o $@ -lpthread

.cpp.o:
	$(NATIVE_CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf *.o src/*.o $(PROGRAM)

