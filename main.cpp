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

        ofstream Archivo("CABAL_0" + to_string(N) + ".TXT",ios::app); ///NOMBRAR AL ARCHIVO

        cout << "[CABALLOS EN AJEDREZ]" << endl << endl;

        int tablero[N][N];

        int M; ///maximo de caballos

        M = N*N; ///calcular el maximo de caballos

        cout << "MAXIMO DE CABALLOS: " << M << endl << endl;
        cout << "Soluciones: 1" << endl << endl;
        ///SE AGREGARN LOS DATOS M Y DE SOLUCIONES AL ARCHIVO
        Archivo << M << endl;
        Archivo << "1" << endl << endl;

        ///IMPLEMENTACION DEL TABLERO
        for(int indice = 1; indice <= N; indice++){
            for(int index = 1; index <= N; index++){
                tablero[indice][index] = 1;
                cout << tablero[indice][index];
                ///SE GRABA EN UN ARCHIVO EL TABLERO
                Archivo << tablero[indice][index] << " ";
            }
            cout << endl;
            Archivo << endl;
        }
        cout << endl;

        Archivo.close();

    }else if((N % 2) != 0){ ///SABER SI N ES IMPAR

        clearScreen();
        string nombreDelArchivo;

        ///CONDICIONES PARA NOMBRAR AL ARCHIVO
        if(N < 10){
            nombreDelArchivo = "CABAL_0" + to_string(N) + ".TXT";
        }else{
            nombreDelArchivo = "CABAL_" + to_string(N) + ".TXT";
        }

        ofstream Archivo(nombreDelArchivo,ios::app); ///NOMBRAR AL ARCHIVO

        cout << "[CABALLOS EN AJEDREZ]" << endl << endl;

        int tablero[N][N];

        int M;

        M = ((N*N) / 2) + 1; ///calcular el maximo de caballos

        cout << "MAXIMO DE CABALLOS: " << M << endl << endl;
        cout << "1 SOLUCIONES" << endl << endl;
        cout << "Soluciones: 1" << endl << endl;
        ///AGREGAR AL DISCO EL VALOR DE M Y CANTIDAD DE SOLUCIONES
        Archivo << M << endl;
        Archivo << "1" << endl << endl;

        ///IMPLEMENTACION DEL TABLERO
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
                ///SE GRABA EN UN ARCHIVO EL TABLERO
                Archivo << tablero[indice][index] << " ";
            }
            cout << endl;
            Archivo << endl;
        }
        cout << endl;

        Archivo.close();

    }else if((N % 2) == 0){ ///SABER SI ES PAR
        clearScreen();

        string nombreDelArchivo;

        ///CONDICIONES PARA NOMBRAR AL ARCHIVO
        if(N < 10){
            nombreDelArchivo = "CABAL_0" + to_string(N) + ".TXT";
        }else{
            nombreDelArchivo = "CABAL_" + to_string(N) + ".TXT";
        }

        ofstream Archivo(nombreDelArchivo,ios::app); ///NOMBRAR AL ARCHIVO

        cout << "[CABALLOS EN AJEDREZ]" << endl << endl;

        int tablero[N][N];

        int M;

        M = (N*N) / 2; ///calcular el maximo de caballos

        cout << "MAXIMO DE CABALLOS: " << M << endl << endl;
        cout << "Soluciones: 2" << endl << endl;
        ///AGREGAR AL DISCO EL VALOR DE M Y CANTIDAD DE SOLUCIONES
        Archivo << M << endl;
        Archivo << "2" << endl << endl;

        cout << "[SOLUCION 1]" << endl << endl;

        ///IMPLEMENTACION DEL TABLERO
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
                ///SE GRABA EN UN ARCHIVO EL TABLERO
                Archivo << tablero[indice][index] << " ";
            }
            cout << endl;
            Archivo << endl;
        }
        cout << endl << endl;
        Archivo << endl << endl;

        cout << "[SOLUCION 2]" << endl << endl;

        ///IMPLEMENTACION DEL TABLERO
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
                ///SE GRABA EN UN ARCHIVO EL TABLERO
                Archivo << tablero[indice][index] << " ";
            }
            cout << endl;
            Archivo << endl;
        }
        cout << endl;
        Archivo.close();
    }
}
