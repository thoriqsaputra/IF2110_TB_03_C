CC=gcc
CFLAGS=-I.

SRC_DIR = inisialisasi
FITUR_DIR = fitur
LIB_DIR = Lib

# List of source files
SRC_FILES = main.c \
            $(SRC_DIR)/draf/draf.c \
            $(SRC_DIR)/utas/utas.c \
            $(SRC_DIR)/pengguna/pengguna.c \
            $(SRC_DIR)/kicauan/kicauan.c \
            $(SRC_DIR)/balasan/balasan.c \
            $(FITUR_DIR)/drafKicauan/drafKicauan.c \
            $(FITUR_DIR)/balas/balas.c \
            $(FITUR_DIR)/teman/teman.c \
            $(LIB_DIR)/globalFunction.c \
            $(FITUR_DIR)/load/loadnsave.c

# Output file
OUT = main

all: $(OUT)

$(OUT): $(SRC_FILES)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OUT)
