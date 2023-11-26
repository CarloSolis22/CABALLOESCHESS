#include <iostream>
#include <fstream>

using namespace std;

void clearScreen(){
    system("cls");
    fflush(stdin);
}

int main() {
    int N;

    bool cambio = true;

    clearScreen();
    cout << "[CABALLOS EN AJEDREZ]" << endl << endl;

    cout << "Tamano del Tablero: ";
    cin >> N;

    if(N < 1 or N > 20){ //VALIDACION DEL TAMANO DEL TABLERO

        cout << "[CABALLOS EN AJEDREZ]" << endl << endl;

        cout << "El tamano no debe de ser menor de 1 o mayor de 20" << endl;
        cin.get();

    }else if(N == 2){///SI N ES IGUAL A 2
        clearScreen();

        ofstream Archivo("N",ios::app); ///NOMBRAR AL ARCHIVO

        cout << "[CABALLOS EN AJEDREZ]" << endl << endl;

        int tablero[N][N];

        int M; ///maximo de caballos

        M = N*N; ///calcular el maximo de caballos

        cout << "MAXIMO DE CABALLOS: " << M << endl << endl;
        cout << "Soluciones: 1" << endl << endl;
        Archivo << N;
        Archivo.close();

        for(int indice = 1; indice <= N; indice++){
            for(int index = 1; index <= N; index++){
                tablero[indice][index] = 1;
                cout << tablero[indice][index];
            }
            cout << endl;
        }
        cout << endl;

    }else if((N % 2) != 0){ ///SABER SI N ES IMPAR

        clearScreen();

        cout << "[CABALLOS EN AJEDREZ]" << endl << endl;

        int tablero[N][N];

        int M;

        M = ((N*N) / 2) + 1; ///calcular el maximo de caballos

        cout << "MAXIMO DE CABALLOS: " << M << endl << endl;
        cout << "2 SOLUCIONES" << endl << endl;
        cout << "Soluciones: 1" << endl << endl;

        for(int indice = 1; indice <= N; indice++){
            for(int index = 1; index <= N; index++){
                if(cambio){
                    tablero[indice][index] = 1;
                    cambio = false;
                }else{
                    tablero[indice][index] = 0;
                    cambio = true;
                }
                cout << tablero[indice][index];
            }
            cout << endl;
        }
        cout << endl;
    }else if((N % 2) == 0){ ///SABER SI ES PAR
        clearScreen();

        cout << "[CABALLOS EN AJEDREZ]" << endl << endl;

        int tablero[N][N];

        int M;

        M = (N*N) / 2; ///calcular el maximo de caballos

        cout << "MAXIMO DE CABALLOS: " << M << endl << endl;
        cout << "Soluciones: 2" << endl << endl;

        cout << "[SOLUCION 1]" << endl << endl;

        for(int indice = 1; indice <= N; indice++){
            for(int index = 1; index <= N; index++){
                if((indice + index) % 2 == 0){
                    tablero[indice][index] = 1;
                    cambio = false;
                }else{
                    tablero[indice][index] = 0;
                    cambio = true;
                }
                cout << tablero[indice][index];
            }
            cout << endl;
        }
        cout << endl << endl;

        cout << "[SOLUCION 2]" << endl << endl;

        for(int indice = 1; indice <= N; indice++){
            for(int index = 1; index <= N; index++){
                if((indice + index) % 2 == 0){
                    tablero[indice][index] = 0;
                    cambio = false;
                }else{
                    tablero[indice][index] = 1;
                    cambio = true;
                }
                cout << tablero[indice][index];
            }
            cout << endl;
        }
        cout << endl;
    }
}
