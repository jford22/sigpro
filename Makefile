CXX			:= -g++
CXXFLAGS	:= -pedantic-errors -Wall -Wextra -Werror
LDFLAGS		:= -L/usr/lib -lstdc++ -lm
BUILD		:= .
OBJ_DIR		:= $(BUILD)/obj
BIN_DIR		:= $(BUILD)/bin
LIB_DIR		:= $(BUILD)/lib
SRC_DIR		:= $(BUILD)/src
INC_DIR		:= $(BUILD)/include
TARGET		:= sigpro
INCLUDE		:= -I$(INC_DIR)/
SRC			:= \
	$(wildcard src/*.cc)

CLEANSRC	:= $(patsubst src/%,%,$(SRC))

OBJECTS		:= $(CLEANSRC:%.cc=$(OBJ_DIR)/%.o)

all: build $(BIN_DIR)/$(TARGET)
	@echo "***** Target $(TARGET) BUILD COMPLETE ******"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR)/$(TARGET): $(OBJECTS) $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(BIN_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)

debug:
	$(CXXFLAGS) += DEBUG -g
	all

release:
	$(CXXFLAGS) += -O2
	all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(BIN_DIR)/*
