CC = clang
LL = clang

LIBTARGET = lib/libmatrixview.a
TARGET = bin/matrixview

BDIR = build
ODIR = $(BDIR)/obj
SDIR = src
IDIR = $(SDIR)/inc

CFLAGS = -O3 -Wall -Wextra -I$(IDIR) -fstack-protector-all -fpie -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=3
LFLAGS = -fuse-ld=lld -flto -lm -s -pie -Wl,-z,nodlopen -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now

_HEADS = matrixview.h
HEADS = $(patsubst %,$(IDIR)/%,$(_HEADS))

_LIBOBJS = matrixview.o
LIBOBJS = $(patsubst %,$(ODIR)/%,$(_LIBOBJS))

_OBJS = main.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(BDIR)/$(TARGET): $(OBJS) $(BDIR)/$(LIBTARGET)
	$(CC) -o $@ $^ $(LFLAGS)

$(BDIR)/$(LIBTARGET): $(LIBOBJS)
	ar -rcs $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(HEADS) $(BDIR)/bin $(BDIR)/lib $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/bin:
	mkdir $@

$(BDIR)/lib:
	mkdir $@

$(ODIR):
	mkdir $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BDIR)/$(LIBTARGET) $(BDIR)/$(TARGET)
