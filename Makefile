CC = gcc
LIBTARGET = lib/libmatrixview.a
TARGET = bin/matrixview

ODIR = obj
SDIR = src
IDIR = $(SDIR)/inc

CFLAGS = -g -Wall -Wextra -I$(IDIR)
LIBS = -lm

_HEADS = matrixview.h
HEADS = $(patsubst %,$(IDIR)/%,$(_HEADS))

_LIBOBJS = matrixview.o
LIBOBJS = $(patsubst %,$(ODIR)/%,$(_LIBOBJS))

_OBJS = main.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(TARGET): $(OBJS) $(LIBTARGET)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(LIBTARGET): $(LIBOBJS)
	ar -rcs $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(HEADS) bin lib obj
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

bin:
	mkdir $@

lib:
	mkdir $@

obj:
	mkdir $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(LIBTARGET) $(TARGET)
