#!/bin/bash
# PreCompilador
echo "Iniciando Compilacion"
cd pro
qmake -Wall -o ../temp
echo "Makefile Creado en /temp"
cd ../temp
make
echo "Compilado Finalizado"
echo "1)Correr"
read opcion
if [ opcion=1 ]; then
	cd ../
	./easyGraph
else
	echo "Terminando"
fi

