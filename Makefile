CC = clang
LL = clang

LIBTARGET = lib/libmatrixview.a
TARGET = bin/matrixview

ODIR = obj
SDIR = src
IDIR = $(SDIR)/inc

CFLAGS = -O3 -Wall -Wextra -I$(IDIR)
LFLAGS = -fuse-ld=lld -flto -lm

_HEADS = matrixview.h
HEADS = $(patsubst %,$(IDIR)/%,$(_HEADS))

_LIBOBJS = matrixview.o
LIBOBJS = $(patsubst %,$(ODIR)/%,$(_LIBOBJS))

_OBJS = main.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(TARGET): $(OBJS) $(LIBTARGET)
	$(CC) -o $@ $^ $(LFLAGS)

$(LIBTARGET): $(LIBOBJS)
	ar -rcs $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(HEADS) bin lib $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

bin:
	mkdir $@

lib:
	mkdir $@

$(ODIR):
	mkdir $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(LIBTARGET) $(TARGET)
