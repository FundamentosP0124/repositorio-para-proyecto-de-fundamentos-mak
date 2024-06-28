#include <iostream>
using namespace std;

const int TAMANO = 3;
const char JUGADOR_X = 'X';
const char JUGADOR_O = 'O';
const char VACIO = ' ';

// Función para inicializar el tablero vacío
void inicializarTablero(char tablero[TAMANO][TAMANO]) {
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

int main() {
    char tablero[TAMANO][TAMANO];
    inicializarTablero(tablero);
    mostrarTablero(tablero);

    // Calcular y mostrar el puntaje
    int puntaje = calcularPuntaje(tablero, JUGADOR_X);
    cout << "Puntaje para X: " << puntaje << "\n";
   
    cout<< "puntaje para 0: " << puntaje << "\n";

    return 0;
}

    

