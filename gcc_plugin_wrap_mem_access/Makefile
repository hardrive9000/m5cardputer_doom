# Where we installed gcc and its headers
INSTALLDIR=/home/rl/gcc/gcc-install/


PLUGIN=wrap_memaccess.so
SOURCES=\
        wrap_memaccess.cc \
		$(END)



CC=$(INSTALLDIR)/bin/gcc
CXX=$(INSTALLDIR)/bin/g++
PLUGINDIR=$(shell $(CC) -print-file-name=plugin)

CXXFLAGS=-std=gnu++11 -fPIC -Wall -g -fno-rtti -I$(PLUGINDIR)/include
# This is a side effect of using C++11
CXXFLAGS+=-Wno-literal-suffix

LDFLAGS=
LDADD=

END=
OBJECTS=$(patsubst %.cc,%.o,$(SOURCES))

all: $(PLUGIN)

$(PLUGIN): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ -shared $+ $(LDADD)

%.o: %.cc
	$(CXX) -c -o $@ $(CXXFLAGS) $<

PLUGINFLAG=-fplugin=./$(PLUGIN)

CCPLUGIN=$(CC) $(PLUGINFLAG)
CXXPLUGIN=$(CXX)  $(PLUGINFLAG)

.PHONY: all clean test
clean:
	rm -f $(OBJECTS) $(PLUGIN)

.PHONY: test
test: $(PLUGIN)
	$(CCPLUGIN) -c -o /dev/null test.c 2> test.dot
	xdot test.dot
