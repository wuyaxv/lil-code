#!/usr/bin/make -f

PROJECT_NAME := 96
LANGUAGE := cpp

SHELL := /bin/bash
SRCDIR := .

ifeq ($(LANGUAGE),cpp)
TARGET := $(PROJECT_NAME)
EXEC := ./$(PROJECT_NAME)
CLEAN_TARGET := $(TARGET)
else ifeq ($(LANGUAGE),python)
TARGET := $(PROJECT_NAME).py
EXEC := python3 ./$(PROJECT_NAME)
CLEAN_TARGET :=
endif

CXX := clang++
CXXFLAGS := -std=gnu++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion
DEBUG_CXXFLAGS := -fsanitize=address -fsanitize=undefined -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize-recover=all -fstack-protector-all -D_FORTIFY_SOURCE=2
DEBUG_CXXFLAGS += -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC

# CC_SOURCES := $(wildcard *.cc)
# CPP_SOURCES := $(wildcard *.cpp)
CC_SOURCES := $(PROJECT_NAME).cc
CPP_SOURCES :=
#CPP_SOURCES := $(PROJECT_NAME).cpp
SOURCES := $(CC_SOURCES) $(CPP_SOURCES)
OBJECTS := $(patsubst %.cc, %.o, $(patsubst %.cpp, %.cc, $(SOURCES)))

export TIME=\n  real\t%es\n  user\t%Us\n  sys\t%Ss\n  mem\t%MKB

.PHONY: all clean run rebuild

all: $(TARGET)

clean:
	-rm -rf $(CLEAN_TARGET)
	-rm -rf $(OBJECTS)

run: $(TARGET)
	@$(EXEC)

rebuild: clean all

$(TARGET): $(OBJECTS)
	$(LINK.cc) $(OBJECTS) -o $(TARGET)
