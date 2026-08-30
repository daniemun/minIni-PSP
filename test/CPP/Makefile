TARGET = build/minIniPSPTestCPP
OBJS = ../../src/minIni.o test.o callback.o
LIBS = -lstdc++

INCDIR =
CFLAGS = -Wall -O2
CXXFLAGS = $(CFLAGS) -fno-rtti -fexceptions --std=c++98
ASFLAGS = $(CFLAGS)

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = minIini PSP Test C++

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak