# PROGRAMA
    PROG = resolveEDO
    OBJS = resolveEDO.o edo.o utils.o # mod1.o mod2.o
	LIKWID_HOME=/home/soft/likwid

# Compilador
    CC     = gcc -Wall
	LIKWID_PERFMON = -DLIKWID_PERFMON	
	LIKWID_INCLUDE = /home/soft/likwid/include
	LIKWID_LIB = /home/soft/likwid/lib

# Acrescentar onde apropriado as opções para incluir uso da biblioteca LIKWID
    CFLAGS = -O0 -mavx2 -march=native -L/home/soft/likwid/lib -I$(LIKWID_HOME)/include -DLIKWID_PERFMON
    LFLAGS = -lm -L/home/soft/likwid/lib -llikwid

# Lista de arquivos para distribuição. Acrescentar mais arquivos se necessário.
DISTFILES = *.c *.h LEIAME* Makefile edos.dat
DISTDIR = ${USER}

.PHONY: clean purge dist all

%.o: %.c %.h utils.h
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	@echo "Limpando sujeira ..."
	@rm -f *~ *.bak

purge:  clean
	@echo "Limpando tudo ..."
	@rm -f $(PROG) $(OBJS) core a.out $(DISTDIR) $(DISTDIR).tgz

dist: purge
	@echo "Gerando arquivo de distribuição ($(DISTDIR).tgz) ..."
	@ln -s . $(DISTDIR)
	@tar -chvzf $(DISTDIR).tgz $(addprefix ./$(DISTDIR)/, $(DISTFILES))
	@rm -f $(DISTDIR)
