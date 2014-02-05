CC := gcc
WIRINGPI_BASEDIR := /usr/local/src/wiringPi/wiringPi
CFLAGS := $(shell dpkg-buildflags --get CFLAGS) \
    -W -Wall -g \
    -I$(WIRINGPI_BASEDIR)
LDFLAGS := $(shell dpkg-buildflags --get LDFLAGS) \
    -L$(WIRINGPI_BASEDIR) -lwiringPi
RM := rm

BIN := pcf8574_test.bin
OBJ := $(patsubst %.c,%.o,$(wildcard *.c))


all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $(BIN) $(OBJ)

.PHONY: clean

clean:
	-$(RM) $(BIN) $(OBJ)
