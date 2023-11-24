CC=gcc
CFLAGS=-I.

SRC_DIR = inisialisasi
FITUR_DIR = fitur
LIB_DIR = Lib

# List of source files
SRC_FILES = $(SRC_DIR)/draf/draf.c \
            $(SRC_DIR)/utas/utas.c \
            $(SRC_DIR)/pengguna/pengguna.c \
            $(SRC_DIR)/kicauan/kicauan.c \
            $(FITUR_DIR)/drafKicauan/drafKicauan.c \
            $(FITUR_DIR)/teman/teman.c \
            $(LIB_DIR)/globalFunction.c

# Output file
OUT = main

all: $(OUT)

$(OUT): main.c $(SRC_FILES)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OUT)
