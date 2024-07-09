#include <iostream>
using namespace std;
//Variables
char cuadro[10] = {'0','1','2','3','4','5','6','7','8','9'};
string jugador1, jugador2;
const int TAMANO = 3;
char JUGADOR_X = 'X';
char JUGADOR_O = 'O';
char VACIO = ' ';

//Funciones de menu
void instruccion(void){
    cout << "Este es un juego de EQUIS-CERO (o tambien llamado Tic Tac Toe)\n";
    cout << "Consiste en poner una X o un 0 de forma horizontal, diagonal o vertical\n" ;
}
void ayuda(void){
    void ayuda(void);
    cout << "¿Como jugar?\n";
    cout << "EQUIS-CERO consiste en colocar X o 0 de manera que formen una fila, columna o diagonal\n";
    cout << "Gana quien complete primero una de estas tres formas\n";
    cout << "Para jugar, tiene que ingresar su nombre de jugador y entre parentesis se le indicara que tipo de opcion es (x) o (0)\n";
    cout << "Luego de ingresar los datos, se mostrara en pantalla el turno del jugador (EJ: NOMBREJUGADOR (X)... )\n";
    cout << "Posterior a eso, tiene que ingresar el numero de la casilla donde desea colocar su opcion\n";
    cout << "Despues de colocar la opcion, le toca el turno al siguiente jugador y asi sucesivamente\n";
    cout << "Seran 3 partidas\n";
    cout << endl;
}
void creadoras(void){
    cout << "Este es un juego creado por:\n Monica Diaz 00165224\n Andrea Marquez 00033924\n Katherine Martinez 00045724\n";
}

//Funciones de tablero
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
            cuadro[j] = char(j +1);

    } while (true);
}

// Función para inicializar el tablero vacío
void inicializarTablero(char tablero[TAMANO][TAMANO]) {
    const int TAMANO = 3;
   
    for (int i = 0; i < TAMANO; ++i) {
        for (int j = 0; j < TAMANO; ++j) {
            tablero[i][j] = VACIO;
        }
    }
}
// Función para mostrar el tablero
void mostrarTablero(char tablero[TAMANO][TAMANO]) {
    for (int i = 0; i < TAMANO; ++i) {
        for (int j = 0; j < TAMANO; ++j) {
            cout << tablero[i][j];
            if (j < TAMANO - 1) cout << " | ";
        }
        cout << "\n";
        if (i < TAMANO - 1) cout << "--+---+--" << "\n";
    }
}
// Función para verificar si hay un ganador
char verificarGanador(char tablero[TAMANO][TAMANO]) {
    // Verificar filas
    for (int i = 0; i < TAMANO; ++i) {
        if (tablero[i][0] != VACIO && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            return tablero[i][0];
        }
    }

    // Verificar columnas
    for (int i = 0; i < TAMANO; ++i) {
        if (tablero[0][i] != VACIO && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            return tablero[0][i];
        }
    }

    // Verificar diagonales
    if (tablero[0][0] != VACIO && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        return tablero[0][0];
    }
    if (tablero[0][2] != VACIO && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        return tablero[0][2];
    }

    // No hay ganador aún
    return VACIO;
}
// Función para calcular el puntaje
int calcularPuntaje(char tablero[TAMANO][TAMANO], char jugador) {
    char ganador = verificarGanador(tablero);
    if (ganador == jugador) {
        return 10;  // Ganar
    } else if (ganador != VACIO && ganador != jugador) {
        return -10;  // Perder
    } else {
        return 0;  // Empate o juego en curso
    }
}

int main()
{
    char jugador_X;
    int puntaje;
    int respuesta;
    const int TAMANO = 3;
    
    char tablero[TAMANO][TAMANO];
    inicializarTablero(tablero);
    mostrarTablero(tablero);
    cout << "JUEGO DE EQUIS-CERO";
    cout << "\n1. Jugar\n2. Ayuda\n3.Creadoras\n";
    cout << "(Selecciona una opcion)\n";
    cout << "**Si usted quiere tener indicaciones mas detalladas seleccione *Ayuda*\n";
    cin >> respuesta;

    
    switch (respuesta)
    {
       
        case 1:
        instruccion();
        cout << "Ingrese el nombre del Jugador 1 (O): ";
        cin >> jugador1;
        cout << "Ingrese el nombre del Jugador 2 (X): ";
        cin >> jugador2;
        iniciarPartida();
        // Calcular y mostrar el puntaje
        calcularPuntaje(tablero, jugador_X);
        cout << "Puntaje para X: " << puntaje << "\n";
        cout << "puntaje para 0: " << puntaje << "\n";
        return 0;
        break;
    
        case 2:
        ayuda();
        cout << "Ingrese el nombre del Jugador 1 (O): ";
        cin >> jugador1;
        cout << "Ingrese el nombre del Jugador 2 (X): ";
        cin >> jugador2;
        iniciarPartida();
        // Calcular y mostrar el puntaje
        calcularPuntaje(tablero, jugador_X);
        cout << "Puntaje para X: " << puntaje << "\n";
        cout<< "puntaje para 0: " << puntaje << "\n";
        return 0;
        break;

        case 3:
        creadoras();
        break;
    }
}
