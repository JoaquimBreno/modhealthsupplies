all:run

dep.o: src/Menu.cpp src/Controler.cpp src/Locais.cpp src/Insumo.cpp src/Vacina.cpp src/Medicamento.cpp src/Epi.cpp src/StorageManager.cpp  # Define as dependências a serem compiladas
	g++ -c src/Menu.cpp	src/Controler.cpp src/Locais.cpp src/Insumo.cpp src/Vacina.cpp src/Medicamento.cpp src/Epi.cpp src/StorageManager.cpp

main: src/main.cpp dep.o
	g++ -o main src/main.cpp *.o

run: main
	rm *.o
	./main.exe
	

.PHONY: all run	