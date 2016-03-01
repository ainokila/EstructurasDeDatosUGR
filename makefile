#Makefile
#
#Carpetas:
BIN=./bin
INCLUDE=include
SRC=./src
OBJ=./obj
LIB=./lib
DOC = ./doc
#
#
#Compiladores
CXX = g++
#
#
#Flags
CPPFLAGS = -Wall -g -c -I$(INCLUDE)
#
#
#
#
#TODO
all: crear clean $(BIN)/principal
#
#COMPILACION

$(BIN)/principal : $(OBJ)/principal.o 
	$(CXX) $(OBJ)/principal.o  -o $(BIN)/principal 

$(OBJ)/principal.o : $(SRC)/principal.cpp $(INCLUDE)/conjunto.h $(INCLUDE)/crimen.h $(INCLUDE)/fecha.h
	$(CXX) $(CPPFLAGS)  $(SRC)/principal.cpp -o $(OBJ)/principal.o 


#
#
#
#
# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	@echo "Limpiando archivos objetos "
	@rm -f $(OBJ)/*
	@rm -f $(LIB)/*
	@rm -f $(BIN)/*

crear:
	mkdir bin
	mkdir obj
	
mrproper: clean

