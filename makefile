all:run

dep.o: src/Menu.cpp src/Controler.cpp src/Locais.cpp   # Define as dependências a serem compiladas
	g++ -c src/Menu.cpp	src/Controler.cpp src/Locais.cpp

main: src/main.cpp dep.o
	g++ -o main src/main.cpp *.o

run: main
	rm *.o
	clear
	./main.exe
	

.PHONY: all run	