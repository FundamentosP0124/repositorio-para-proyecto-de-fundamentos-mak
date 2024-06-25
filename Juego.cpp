#include <iostream>
using namespace std;

//Funciones
void instruccion(void){
    cout << "Este es un juego de EQUIS-CERO\nConsiste en poner una X o un 0 de forma horizontal, diagonal o vertical"; ;
}
void ayuda(void){
    cout << "¿Como jugar?\n";
    cout << "EQUIS-CERO consiste en colocar X o 0 de manera que formen una fila, columna o diagonal\n";
    cout << "Gana quien complete primero una de estas tres formas\n";
    cout << "Seran 3 partidas";
}
void creadoras(void){
    cout << "Este es un juego creado por:\n Monica Diaz\n Andrea Marquez\n Katherine Martinez";
}
void ayuda(void){
    cout << "EQUIS-CERO consiste en colocar X o 0 de manera que formen una fila, columna o diagonal\nGana quien complete primero una de estas tres formas";
}
void opcion(void){
    cout << "Este es un juego creado por:\n Monica Diaz\n Andrea Marquez\n Katherine Martinez";
}

int main()
{
    int respuesta;
    string opcion, si, SI, no, NO;
    cout << "JUEGO DE EQUIS-CERO";
    cout << "\n1. Jugar\n2. Ayuda\n3.Creadoras\n";
    cout << "(Selecciona una opcion)\n";
    cin >> respuesta;

    switch (respuesta)
    {
        case 1:
        instruccion();
        cout << endl;
        cout << "Desea ver *como jugar?* antes de continuar?\n   SI   NO\n";
        cin >> opcion;
        if (opcion == si||opcion == SI)
        {
            ayuda();
        }
        break;

        case 2:
        ayuda();
        break;

        case 3:
        creadoras();
        break;
    }
}