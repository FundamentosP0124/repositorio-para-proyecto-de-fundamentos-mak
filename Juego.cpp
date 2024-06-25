#include <iostream>
using namespace std;

void instruccion(void){
    cout << "Este es un juego de EQUIS-CERO\nConsiste en poner una X o un 0 de forma horizontal, diagonal o vertical"; 
}
void ayuda(void){
    cout << "EQUIS-CERO consiste en colocar X o 0 de manera que formen una fila, columna o diagonal\nGana quien complete primero una de estas tres formas";
}
void opcion(void){
    cout << "Este es un juego creado por:\n Monica Diaz\n Andrea Marquez\n Katherine Martinez";
}

int main()
{
    int numero;
    cout << "JUEGO DE EQUIS-CERO";
    cout << "1. Jugar\n2. Ayuda\n3.Opciones";

    switch (numero)
    {
        case 1:
        instruccion;

        case 2:
        ayuda;

        case 3:
        opcion;

    }
    
}