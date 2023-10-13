
#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream>
#include <vector>   //Para las acciones
#include <set>      //Para ordenar las acciones
#include <queue>
#include <string>   
#include <fstream> // Para usar ficheros
using namespace std;

struct zonas_comparador{
    bool operator()(const int & a, const int & b) const{
        return a > b;
    }
};

queue<int> numDardosGreedy(set<int, zonas_comparador> zonas, int modo, int puntuacion){

    queue<int> solucion;

    bool esPosible = true;
    bool zonaEncontrada;

    while (puntuacion > 0 && esPosible){

        set<int>::iterator it;
        zonaEncontrada = false;

        for(it = zonas.begin(); it != zonas.end() && !zonaEncontrada; ++it){
            if((*it)*modo <= puntuacion){
                puntuacion -= (*it)*modo;
                solucion.push(*it);
                zonaEncontrada = true;
            }
        }

        if(!zonaEncontrada){
            while(!solucion.empty()){
                solucion.pop();
            }
            solucion.push(-1);
            esPosible = false;
        }

    }
    return solucion;
}

int main(int argc, char *argv[]) {

    set<int, zonas_comparador> zonas;
    queue<int> solucion;
    int modo, puntuacion;

	if (argc <= 1) {
		cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr<<argv[0]<<" NombreFicheroEntrada1 .. NombreFicheroEntradaN\n\n";
		return 0;
	}

    for (int argumento = 1; argumento<argc; argumento++) {

        ifstream ficheroProblema;
        string cadena;
        char delimitador = '\t';            //Usamos el tab como delimitador de linea
        int dato;

        ficheroProblema.open(argv[argumento]);

        if (ficheroProblema.is_open()){
            ficheroProblema >> cadena;
            puntuacion = stoi(cadena);

            ficheroProblema >> cadena;
            modo = stoi(cadena);

            while(!ficheroProblema.eof()){
                int aux;
                ficheroProblema >> cadena;
                aux = stoi(cadena);
                zonas.insert(aux);
            }
        }

        ficheroProblema.close();

        cout << "Buscamos solucion para una puntuacion de " << puntuacion<< ", jugando al modo "<<modo<<" y con un tablero de "<<zonas.size()<<" zonas"<<endl;
        
        if (modo % 2 == 1 || (modo % 2 == 0 && puntuacion % 2 != 1)){
            solucion = numDardosGreedy(zonas, modo, puntuacion);
        }
        else{
            solucion.push(-1);
        }

        if(solucion.front() != -1){
            cout<<"Solucion encontrada con "<<solucion.size() <<" dardo(s). Secuencia a seguir: "<<endl;
            while(!solucion.empty()){
                cout<<" --> "<<solucion.front();
                solucion.pop();
            }
            cout<<endl;
        } else{
            cout<<"No se ha encontrado una solucion"<<endl;
        }

        cout << "-------------------------------------------------------" <<endl;

        zonas.clear();
        while(!solucion.empty()){
            solucion.pop();
        }

    }

	return 0;
}