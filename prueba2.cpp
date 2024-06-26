#include <iostream>
#include <cstdlib>
using namespace std;

char fila;
char columna;
char empate;

bool turnoDeX = false;

char tablero[][3]= { {'_','_','_'},
                     {'_','_','_'},
                     {'_','_','_'}
                    
};

char hayGanador(){
    //validacion horizontal
    for(int i= 0; i<3;i++){

        if(tablero[i][0] != '_' && tablero [i][0] == tablero[i][1] && tablero [i][1]  == tablero[i][2] ){
        return tablero[i][0];

    }
    
    }

    //validacion vertical
    for(int i= 0; i<3;i++){

        if(tablero[0][i] != '_' && tablero [0][i] == tablero[1][i] && tablero [1][i]  == tablero[2][i] ){
        return tablero[0][i];
    }
    }
    //validacion diagonal de izquierda a derecha
     if(tablero[0][0] != '_' && tablero [0][0] == tablero[1][1] && tablero [1][1]  == tablero[2][2] ){
        return tablero[0][0];
    }
    //validacion diagonal derecha a izquierda
     if(tablero[0][2] != '_' && tablero [0][2] == tablero[1][1] && tablero [1][1]  == tablero[2][0] ){
        return tablero[0][2];
    }

} 

bool hayEmpate(){
    for(int i= 0; i<3; i++){
        for(int j = 0; j<3; j++){
           if(tablero[i][j]=='_'){
            return false;
           }
        }
        
    }
    return true;

}

void mostrarTablero(){
    char jugador = turnoDeX ? 'X' : '0';
    for(int i= 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout <<tablero[i][j] <<"\n";
        }
        cout<< endl;
    }

    cout<<"es el turno de "<< jugador << endl;
    cout<<"en que fila desea jugar: ";
    cin>> fila;
    cout<<"en que columna desea jugar: ";
    cin>> columna;
    tablero[fila][columna] = jugador;
    turnoDeX = !turnoDeX;
    char ganador = hayGanador();
    if(ganador != '_'){
        cout<<" ha ganado"<< ganador << endl;
        exit(0);
    }
    if(hayEmpate()){
        cout<<"hay empate"<< empate <<endl;
        exit(0);
    }
}
int main(int argc, char **argv){
    while(true)
    mostrarTablero();
}