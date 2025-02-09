CC = gcc

LIBTARGET = lib/libmatrixview.a

BDIR = build
ODIR = $(BDIR)/obj
SDIR = src
IDIR = $(SDIR)/inc

CFLAGS = -I$(IDIR) -O2 -fpic -shared -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2 \
		 -fstack-clash-protection -fstack-protector-all -fstack-protector-strong -fcf-protection=full

_HEADS = matrixview.h
HEADS = $(patsubst %,$(IDIR)/%,$(_HEADS))

_LIBOBJS = matrixview.o
LIBOBJS = $(patsubst %,$(ODIR)/%,$(_LIBOBJS))

$(BDIR)/$(LIBTARGET): $(LIBOBJS)
	ar -rcs $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(HEADS) $(BDIR)/lib $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/lib:
	mkdir $@

$(ODIR):
	mkdir $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BDIR)/$(LIBTARGET)
