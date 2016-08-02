#RECUV Airserver
CROSS_ARCH := arm-openwrt-linux
NATIVE_CXX := g++
CROSS_CXX := $(CROSS_ARCH)-g++
CXXFLAGS := -c -g -Wall $(CXXFLAGS)
LIBS :=
CROSS_DIR := /home/tom/Desktop/OpenWrt-Toolchain-brcm2708-bcm2708_gcc-4.8-linaro_glibc-2.21_eabi.Linux-x86_64/toolchain-arm_arm1176jzf-s+vfp_gcc-4.8-linaro_glibc-2.21_eabi/usr/
LIB_DIR :=
INCLUDE_DIR := 
SOURCES :=  \
	$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
PROGRAM := airserver
#all:
#	$(CXX) $(CXXFLAGS) $(INCLUDE_DIR) $(INCLUDE_DIR) -o $(PROGRAM) $(SOURCES) $(LIBS)
all: $(SOURCES) $(PROGRAM)

$(PROGRAM): $(OBJECTS) 
	$(NATIVE_CXX) $(LIBS) $(OBJECTS) -o $@ -lpthread

.cpp.o:
	$(NATIVE_CXX) $(CXXFLAGS) $< -o $@

cross_update: 
	$(CROSS_CXX) $(CXXFLAGS) -I$(PKG_STAGING_DIR)/usr/include/Poco -L$(PKG_STAGING_DIR)/usr/lib/libPoco{Foundation,XML,Net,Util}.so* -o cross_build/$(PROGRAM) $(SOURCES) $(LIBS)
	./cross_build/update.sh
cross: 
	$(CROSS_CXX) $(CXXFLAGS) -I$(PKG_STAGING_DIR)/usr/include/Poco -L$(PKG_STAGING_DIR)/usr/lib/libPoco{Foundation,XML,Net,Util}.so* -o $(PROGRAM) $(SOURCES) $(LIBS)
	scp $(PROGRAM) root@192.168.4.1:/root/airserver
clean:
	rm -rf *.o src/*.o $(PROGRAM)

