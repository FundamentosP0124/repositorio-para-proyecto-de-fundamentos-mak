#include <iostream>
using namespace std;

//Funciones
void instruccion(void){
    cout << "Este es un juego de EQUIS-CERO (o tambien llamado Tic Tac Toe)\n";
    cout << "Consiste en poner una X o un 0 de forma horizontal, diagonal o vertical\n";
}
void ayuda(void){
    cout << "¿Como jugar?\n";
    cout << "EQUIS-CERO consiste en colocar X o 0 de manera que formen una fila, columna o diagonal\n";
    cout << "Gana quien complete primero una de estas tres formas\n";
    cout << "Para jugar, tiene que ingresar su nombre de jugador y entre parentesis se le indicara que tipo de opcion es (x) o (0)\n";
    cout << "Luego de ingresar los datos, se mostrara en pantalla el turno del jugador (EJ: NOMBREJUGADOR (X)... )\n";
    cout << "Posterior a eso, tiene que ingresar el numero de la casilla donde desea colocar su opcion\n";
    cout << "Despues de colocar la opcion, le toca el turno al siguiente jugador y asi sucesivamente\n";
    cout << "Seran 3 partidas";

}
void creadoras(void){
    cout << "Este es un juego creado por:\n Monica Diaz 00165224\n Andrea Marquez 00033924\n Katherine Martinez 00045724\n";
}

int main()
{
    int respuesta;
    string opcion, si, no, SI, NO;
    cout << "JUEGO DE EQUIS-CERO";
    cout << "\n1. Jugar\n2. Ayuda\n3.Creadoras\n";
    cout << "(Selecciona una opcion)\n";
    cin >> respuesta;

    switch (respuesta)
    {
        case 1:
        instruccion();
        cout << "Desea ver *como jugar?* antes de comenzar?\n";
        cin >> opcion;
        cout << "\n";
        if (opcion == si || opcion == SI)
        {
            cout << endl;
            ayuda();
        }
    
        case 2:
        ayuda();
        break;

        case 3:
        creadoras();
        break;
    }
}