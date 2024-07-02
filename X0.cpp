#include <iostream>
using namespace std;

char cuadro[10] = {'0','1','2','3','4','5','6','7','8','9'};
string jugador1, jugador2;

void limpiarPantalla() {
     system("cls");
}

void tablero()
{
    limpiarPantalla();
    cout << "Tic Tac Toe: " << jugador1 << " (O) vs " << jugador2 << " (X)" << endl;
    cout << " " << cuadro[1] << " | " << cuadro[2] << " | " << cuadro[3] << endl;
    cout << " -------" << endl;
    cout << " " << cuadro[4] << " | " << cuadro[5] << " | " << cuadro[6] << endl;
    cout << " -------" << endl;
    cout << " " << cuadro[7] << " | " << cuadro[8] << " | " << cuadro[9] << endl;
}

int RevisarGanador()
{
    if (cuadro[1] == cuadro[2] && cuadro[2] == cuadro[3])
        return 1;
    else if (cuadro[4] == cuadro[5] && cuadro[5] == cuadro[6])
        return 1;
    else if (cuadro[7] == cuadro[8] && cuadro[8] == cuadro[9])
        return 1;
    else if (cuadro[1] == cuadro[4] && cuadro[4] == cuadro[7])
        return 1;
    else if (cuadro[2] == cuadro[5] && cuadro[5] == cuadro[8])
        return 1;
    else if (cuadro[3] == cuadro[6] && cuadro[6] == cuadro[9])
        return 1;
    else if (cuadro[1] == cuadro[5] && cuadro[5] == cuadro[9])
        return 1;
    else if (cuadro[3] == cuadro[5] && cuadro[5] == cuadro[7])
        return 1;
    else if (cuadro[1] != '1' && cuadro[2] != '2' && cuadro[3] != '3'
             && cuadro[4] != '4' && cuadro[5] != '5' && cuadro[6] != '6'
             && cuadro[7] != '7' && cuadro[8] != '8' && cuadro[9] != '9')
        return 0;  
    else
        return -1; 
}

void iniciarPartida()
{
    int eleccion;
    char simbolo;
    int i;

    do
    {
        limpiarPantalla();
        cout << "Tic Tac Toe: " << jugador1 << " (O) vs " << jugador2 << " (X)" << endl;

        int jugador = 1;

        do
        {
            tablero();
            jugador = (jugador % 2) ? 1 : 2;
            cout << ((jugador == 1) ? jugador1 : jugador2) << " (" << ((jugador == 1) ? 'O' : 'X') << "), ingrese un numero:  ";
            cin >> eleccion;
            simbolo = (jugador == 1) ? 'O' : 'X';

            if (eleccion >= 1 && eleccion <= 9 && cuadro[eleccion] == char(eleccion + 48))
                cuadro[eleccion] = simbolo;
            else
            {
                cout << "Movimiento invalido. Intente de nuevo." << endl;
                continue;   
            }

            i = RevisarGanador();
            jugador++;
        } while (i == -1);

        tablero();

        if (i == 1)
            cout << "==>\a" << ((jugador - 1 == 1) ? jugador1 : jugador2) << " Gano la partida!" << endl;
        else
            cout << "==>\aEmpate!" << endl;

        cout << "¿Desea jugar otra partida? (s/n): ";
        char respuesta;
        cin >> respuesta;

        if (respuesta != 's' && respuesta != 'S')
            break;

        for (int j = 1; j < 10; ++j)
            cuadro[j] = char(j + 48);

    } while (true);
}

int main()
{
    cout << "Ingrese el nombre del Jugador 1 (O): ";
    cin >> jugador1;
    cout << "Ingrese el nombre del Jugador 2 (X): ";
    cin >> jugador2;

    iniciarPartida();

    return 0;
}

 
