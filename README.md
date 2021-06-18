# Moderator Health Supplies 
This project seeks to create a system for the management of supplies for Covid-19

## 1. Project objectives:

Attempting to explore the public health sector demmand, the project uses concepts of OOP in C++

To study data structure, primitive software engineering and mainly object orientation.

## 2. Project diagram:

The diagram preserves the system fucionality. Then, you can find this same schema in UI implamentation:

![image](Diagrama_Projeto.jpg)

## 3. How to execute the prompt system:

Clone the project in branch master:

```
git clone --branch master https://github.com/JoaquimBreno/modhealthsupplies.git
```

In case you have GCC/G++ Compilator and make Unix tool, run command:

```
make
```
Otherwise, run:

```
g++ src/main.cpp src/Menu.cpp src/StorageManager.cpp src/Controler.cpp src/Locais.cpp src/Insumo.cpp src/Vacina.cpp src/Medicamento.cpp src/Epi.cpp -o main
```

Or only execute `main.exe`

## 4. How to execute the system UI for Windows 7/8/10 x64:

Clone the project in branch qtspace:

```
git clone --branch qtspace https://github.com/JoaquimBreno/modhealthsupplies.git
```

Run:

```
modhealthsupplies.exe
```

