CXX			:= -g++ -g
CXXFLAGS	:= -pedantic-errors -Wall -Wextra -Werror
LDFLAGS		:= -L/usr/lib -lstdc++ -lm
DEPFLAGS    = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
BUILD		:= .
OBJ_DIR		:= $(BUILD)/obj
BIN_DIR		:= $(BUILD)/bin
LIB_DIR		:= $(BUILD)/lib
DEP_DIR     := $(BUILD)/.deps
SRC_DIR		:= $(BUILD)/src
INC_DIR		:= $(BUILD)/include
TARGET		:= sigpro
INCLUDE		:= -I$(INC_DIR)/
SRC			:= \
	$(wildcard src/*.cc)

CLEANSRC	:= $(patsubst src/%,%,$(SRC))

OBJECTS		:= $(CLEANSRC:%.cc=$(OBJ_DIR)/%.o)

DEPFILES    := $(CLEANSRC:%.cc=$(DEP_DIR)/%.d)

all: $(BIN_DIR)/$(TARGET) $(SRC)
	@echo "***** Target $(TARGET) BUILD COMPLETE ******"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(DEP_DIR)/%.d | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

$(DEP_DIR):
	mkdir -p $@

$(BIN_DIR)/$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $@ $(OBJECTS)

.PHONY: all clean debug release


debug:
	$(CXXFLAGS) += DEBUG -g
	all

release:
	$(CXXFLAGS) += -O3
	all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(DEP_DIR)/*
	-@rm -rvf $(BIN_DIR)/*

$(DEPFILES):

include $(wildcard $(DEPFILES))
