IDIR =../include
CC = g++ -std=c++11
CFLAGS=-I$(IDIR) -fprofile-argcs -ftest-coverage	

ODIR=obj
LDIR =../lib

_DEPS = arvore.hpp jogo.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = arvore.o teste_arvore.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ2 = arvore.o jogo.o teste_jogo.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

_OBJ3 = arvore.o jogo.o jogo_20_perguntas.o
OBJ3 = $(patsubst %,$(ODIR)/%,$(_OBJ3))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

teste_arvore : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

teste_jogo : $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

jogo_20_perguntas : 
	g++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~