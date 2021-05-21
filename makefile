all:run

dep.o: src/Menu.cpp src/Controler.cpp src/Locais.cpp src/Insumo.cpp src/Vacina.cpp src/Medicamento.cpp src/Epi.cpp  # Define as dependências a serem compiladas
	g++ -c src/Menu.cpp	src/Controler.cpp src/Locais.cpp src/Insumo.cpp src/Vacina.cpp src/Medicamento.cpp src/Epi.cpp

main: src/main.cpp dep.o
	g++ -o main src/main.cpp *.o

run: main
	rm *.o
	clear
	./main.exe
	

.PHONY: all run	