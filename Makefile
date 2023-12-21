################################################################################
#                                                                              #
#                      OPEN DATA STRUCTURES in C (libodsc)                     #
#                                                                              #
################################################################################

#
# Name of the library
#
LIB = libodsc

#
# C compiler
#
# Replace this with c89, cc, clang, or whatever. ODSC conforms to ANSI C (C89)
# specifications. Make sure to check COMPILE and SHARED_LIB variables to match
# the arguments of your compiler.
#
CC = gcc

#
# Arguments to force ANSI specs. I only use this to make sure the code complies
# with ANSI C specs.
# 
ifeq ($(ansi),true)
	ANSI_ARGS = -ansi -pedantic -Wall -Werror
endif

SRC = $(wildcard src/*.c)

#
# Compile arguments
#
# Runs for each file in src/. $@ is the output (.o), $< is the input (.c)
#
COMPILE = $(CC) $(ANSI_ARGS) -fpic -I include/ -c -o $@ $<

#
# Shared library arguments
#
SHARED_LIB = $(CC) -shared -o $(LIB).so $^ -lm

#
# Shared library install directory
#
INSDIR = /usr/lib
BUILD_DIR := build
# OBJ = arraystack.o arrayqueue.o arraydeque.o dualarraydeque.o \
#       rootisharraystack.o sllist.o dllist.o selist.o skiplistsset.o skiplist.o \
#       chainedhashtable.o binarysearchtree.o

OBJ = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRC))

lib: $(OBJ)
	echo $(SRC)
	$(SHARED_LIB)
	

install: lib
	mv $(LIB).so $(INSDIR)/$(LIB).so && rm -f *.o



$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# %.o: src/%.c
# 	$(COMPILE)
	
	

clean:
	rm -f *.o *.so *.a a.out