# this file should be included to example-XX subprojects
CPPFLAGS := -I../libxpcsc/include
LDFLAGS := ../libxpcsc/libxpcsc.a

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CPPFLAGS += -I/usr/include/PCSC
	LDFLAGS += -lpcsclite
endif
ifeq ($(UNAME_S),Darwin)
	CPPFLAGS +=
	LDFLAGS += -framework PCSC
endif

ifneq ($(DEBUG),)
	CPPFLAGS += -DDEBUG
endif

SIMPLE_BINARIES := dump-mifare-card dump-atr cmd-get-data acr122u

all: libxpcsc $(SIMPLE_BINARIES)

libxpcsc:
	cd ../libxpcsc && make
	
$(SIMPLE_BINARIES): %: %.o
	g++ -g -o $@ $@.o  $(CPPFLAGS) $(LDFLAGS) 

clean:
	rm -f $(SIMPLE_BINARIES) *.o

%.o: %.cpp
	g++ -std=c++11 -Wall -c -o $@ $< $(CPPFLAGS)

.PHONY: libxpcsc
