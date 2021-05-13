all:Executar limpar
Executar: main.o grafos.o dados.o
    g++ -Wall -o Projeto2 main.o grafos.o dados.o

main.o:main.cpp grafos.cpp grafos.h dados.cpp dados.h
    g++ -c main.cpp

grafos.o:grafos.cpp grafos.h
    g++ -c grafos.cpp

dados.o:dados.cpp dados.h
    g++ -c dados.cpp

limpar:
    rm -rf *.o