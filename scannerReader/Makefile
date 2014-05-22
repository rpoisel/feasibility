RM := rm
CC := gcc

VPATH := src
CFLAGS := -g -O0 -Iinclude

BIN := main
SRC := \
      main.c \
      threads.c
OBJ = $(patsubst %.c,%.o,$(SRC))
LIBS := -pthread

.PHONY: clean

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $(LIBS) -o $@ $?

clean:
	-$(RM) $(OBJ) $(BIN)
