# PROGRAMA
PROG = resolveEDO
OBJS = resolveEDO.o edo.o utils.o
LIKWID_HOME = /home/soft/likwid

# Compilador
CC = gcc -Wall
CFLAGS = -O0 -mavx2 -march=native -I$(LIKWID_HOME)/include -DLIKWID_PERFMON
LFLAGS = -lm -L$(LIKWID_HOME)/lib -llikwid

# Lista de arquivos para distribuição
DISTFILES = *.c *.h LEIAME* Makefile edos.dat
DISTDIR = ${USER}

.PHONY: clean purge dist all

%.o: %.c  %.h
	$(CC) -c $(CFLAGS) -o $@ $< $(LFLAGS)

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	@echo "Limpando sujeira ..."
	@rm -f *~ *.bak

purge: clean
	@echo "Limpando tudo ..."
	@rm -f $(PROG) $(OBJS) core a.out $(DISTDIR) $(DISTDIR).tgz

dist: purge
	@echo "Gerando arquivo de distribuição ($(DISTDIR).tgz) ..."
	@ln -s . $(DISTDIR)
	@tar -chvzf $(DISTDIR).tgz $(addprefix ./$(DISTDIR)/, $(DISTFILES))
	@rm -f $(DISTDIR)
