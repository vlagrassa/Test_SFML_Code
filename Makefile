#MAKEFLAGS += --warn-undefined-variables

#CXX = c++

ROOT:=$(dir $(realpath $(lastword $(MAKEFILE_LIST))))
	
RM+=-r

CXXFLAGS:=$(shell pkg-config sfml-all --cflags)
LDLIBS:=$(shell pkg-config sfml-all --libs)

#SRCS:=$(addprefix $(ROOT),$(wildcard src/*))
SRCDIR = src/
SRCS:=$(wildcard $(SRCDIR)/*.c*)
HDRS:=$(wildcard $(SRCDIR)/*.h)

OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.cpp=.o)))

#HDRDIR = hdr/
#HDRS:=$(wildcard $(HDRDIR)/*)

MAIN = main

run: $(MAIN)
	./$(MAIN)

$(MAIN): $(OBJS)
	echo $(OBJS)
	$(CXX) -o $(MAIN) $(OBJS) $(LDLIBS)
	

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CXX) -c $< $(CXXFLAGS) -o $@
	

$(OBJDIR):
	mkdir $@

ball.cpp: ball.h

test:
	echo $(SRCS)
	echo $(CXXC)

.PHONY: clean
clean:
	$(RM) $(MAIN) $(OBJDIR)
