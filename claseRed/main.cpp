#include "manager.h"
#include <iostream>
using namespace std;

int main()
{
    int eleccion;
    typedef vector<int>numeros;
    typedef vector<numeros> numeros2;
    numeros2 matriz = {{99,99,99},{99,99,99},{99,99,99}};
    int len=matriz.size();
    int salida=0;
    Nodos nodo1;
    Red red1;
    red1.crearenrutador();
    while (salida!=3) {
        cout<<"ingrese una opcion: "<<endl<<"1) Crear y agregar nodo alaetorio a la tabla  de enrutamiento existente y mostrar la tabla de enrutadores  ."<<endl<<"2) Eliminar un enrutador "<<endl<<"3)tabla del camino mas rapido dirigida a los diferentes enrutadores "<<endl<<"4)abrir la matriz desde un archivo."<<endl<<"5) salir"<<endl;

        cin>>eleccion;
//        Nodos nodo1;
        switch (eleccion) {
        case 1:{

            red1.crearenrutador();
            break;
        }
        case 2:{
            red1.eliminarenrutador();
            break;
        }
        case 3:{
            red1.caminosmascorto();
            break;
        }
        case 4:{
            red1.abrir_archivo();
            break;
        }
        case 5:{
            salida=3;
            break;
        }

        }
    }

}
