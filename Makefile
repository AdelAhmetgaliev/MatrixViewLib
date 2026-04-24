CC = clang
AR = llvm-ar

BDIR = build
ODIR = $(BDIR)/objects
LDIR = $(BDIR)/library
DDIR = $(BDIR)/deps
BEDIR = $(BDIR)/examples
SDIR = source
IDIR = include
EDIR = examples

LIBTARGET = $(LDIR)/libmatrixview.a

_HEADS = matrixview.h
HEADS = $(patsubst %,$(IDIR)/%,$(_HEADS))

_LIBSRCS = matrixview.c
LIBSRCS = $(patsubst %,$(SDIR)/%,$(_LIBSRCS))

_LIBOBJS = matrixview.o
LIBOBJS = $(patsubst %,$(ODIR)/%,$(_LIBOBJS))

_DEPS = matrixview.d
DEPS = $(patsubst %,$(DDIR)/%,$(_DEPS))

CFLAGS = -I$(IDIR) \
		 -Wall -Wextra -Werror -Wpedantic \
		 -std=c99 \
		 -fPIC \
		 -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2 \
		 -fstack-clash-protection \
		 -fstack-protector-all \
		 -fcf-protection=full \
		 -O2

LDFLAGS_EXAMPLES = -L$(LDIR) -lm -lmatrixview

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS := $(filter-out -O2, $(CFLAGS))
	CFLAGS += -g -O0 -DDEBUG
endif

DEPFLAGS = -MT $@ -MMD -MP -MF $(DDIR)/$*.d

EXAMPLES = $(wildcard $(EDIR)/*.c)
EXECS = $(patsubst $(EDIR)/%.c,$(BEDIR)/%,$(EXAMPLES))

.PHONY: all clean rebuild debug info help examples clean-examples

all: $(LIBTARGET)

$(LIBTARGET): $(LIBOBJS) | $(LDIR)
	@echo "Линковка библиотеки: $@"
	@$(AR) -rcs $@ $^

$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR) $(DDIR)
	@echo "Компиляция: $<"
	@$(CC) -c -o $@ $< $(CFLAGS) $(DEPFLAGS)

$(BEDIR)/%: $(EDIR)/%.c | $(BEDIR)
	@echo "Сборка примера: $<"
	@$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS_EXAMPLES)

examples: $(EXECS)
	@echo "Примеры собраны: $(EXECS)"

$(ODIR) $(DDIR) $(LDIR) $(BEDIR):
	@mkdir -p $@

-include $(DEPS)

debug: DEBUG = 1
debug: clean all examples
	@echo "Debug-сборка завершена"

clean: clean-examples
	@echo "Очистка..."
	@rm -rf $(BDIR)

clean-examples:
	@echo "Очистка примеров..."
	@rm -rf build/examples

rebuild: clean all

info:
	@echo "Компилятор: $(CC)"
	@echo "Флаги компиляции: $(CFLAGS)"
	@echo "Объектные файлы: $(LIBOBJS)"
	@echo "Целевая библиотека: $(LIBTARGET)"
	@echo "Режим отладки: $(DEBUG)"
	@echo "Примеры: $(EXAMPLES)"
	@echo "Исполняемые файлы примеров: $(EXECS)"

help:
	@echo "Доступные команды:"
	@echo "  all             - Собрать библиотеку"
	@echo "  examples        - Собрать примеры"
	@echo "  debug           - Собрать с символами отладки (библиотека + примеры)"
	@echo "  clean           - Удалить артефакты сборки"
	@echo "  clean-examples  - Удалить только примеры"
	@echo "  rebuild         - Очистить и собрать всё"
	@echo "  info            - Показать переменные сборки"
	@echo "  help            - Показать эту справку"
