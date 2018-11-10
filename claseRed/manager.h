#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string.h>
#include <time.h>
#include<fstream>

using namespace std;

class Nodos{
protected:
    char nombre[1000]={'A','B','C'};//Nodos
    typedef vector<int>numeros;
    typedef vector<numeros> numeros2;
    numeros2 matriz = {{99,99,99},{99,99,99},{99,99,99}};//Esa es la matriz de los enlaces de enrutadores.
    numeros2 matriz1={{0,0,0},{0,0,0},{0,0,0}};//Es una matriz copia de la anterior, para rectificar el camino mas rapido.
    int len;//Longitud de la matriz.
private:
    int opcion;//opccion elegida por el usuario para continuar.
    int bloqueo=1;//hace que se cree una vez la matriz aleatoria
    int nodos;//
public:
    Nodos();
    void setnombre(char _nombre[1000]);//set:dar o establecer
    char getpuntonombre(int);
    int getpuntovector(int,int);
    void crearenrutador();
    void eliminarenrutador();
    void setMatriz(const numeros2 &value);
    void mostrar(const numeros2 &value);
};
Nodos::Nodos()
{
    nodos=3;

}

void Nodos::setnombre(char _nombre[1000])
{
    for(int i;i<len;i++){
    nombre[i]=_nombre[i];
    }
}

char Nodos::getpuntonombre(int l)
{
    return nombre[l];

}

 int Nodos::getpuntovector(int l, int j)
{

   // return matriz[l][j];

 }

 void Nodos::crearenrutador()
 {
     bool cuality;
     bool re=true;
     while(re!=false){
         cout<<"ingrese una opcion: "<<endl<<"1) mostrar la tabla de enrutadores"<<endl<<"2) crear y agregar nodo alaetorio a la tabla  de enrutamiento existente ."<<endl;
         cin>>opcion;
         switch (opcion) {
         case 1:
         {
             cuality=true;
             re=false;
             break;
         }
         case 2:
         {
           cuality=false;
           re=false;
           break;

         }
         default:{
             cout<<"ENTRE UNO Y DOS PENDEJO porfavor"<<endl;
             break;
         }
     }
     }
     len = matriz.size();
     srand(time(NULL));
     int repeat=2;

     //ESTE FOR LLENA TODA LA MATRIZ CON NÚMEROS ALEATORIOS Y DEPENDIENDO DE UNA SEMILLA..
     if(bloqueo==1){
         //int semilla = 1+rand()%2;
         int semilla=1;
         for (int i=0;i<len;i++)
         {
             for (int j= 0; j<len; j++)
             {
                 int num= 10+rand()%30;
                 matriz[i][j]=num;
                 j+=semilla;
             }
         }
         bloqueo=2;
     }
     int csemilla=1+rand()%2;
         if(cuality==false){
             vector<int>juanca;
             for (int i = 0 ; i<=len;i++)
             {
                 if(i!=csemilla){
                 int num= 10+rand()%30;
                 juanca.push_back(num);
                 }
                 else{
                     juanca.push_back(99);
                     csemilla+=2;
                 }
             }

             matriz.push_back(juanca);
             matriz1.push_back(juanca);
             for(int o=0;o<len;o++){
                 matriz[o].push_back(juanca[o]);
                 matriz1[o].push_back(juanca[o]);

             }

             len = matriz.size();


         }

 //    //ESTE FOR HACE QUE TODAS LAS DIAGONALES DE LA MATRIZ SEAN CEROS.
     for (int i = 0 ;i <len ; i++)
     {
         for (int j=0;j<len;j++)
         {
             if (i==j)
             {
                 matriz[i][j]=0;
             }
         }
     }
 //    //ESTE FOR EMPIEZA A LLENAR LA MATRIZ SEGUN LA CANTIDAD DE NODOS Y TODO DEPENDIENDO
 //    // DEL PRIMER NODO.
     for (int i = 0 ;i <len ; i++)
     {
         for (int j=0;j<len;j++)
         {
             if (i!=j)
             {
                 matriz[j][i]=matriz[i][j];
             }
         }
     }
 //    //ESTE FOR MUESTRA LA MATRIZ

     nombre[len-1]=nombre[len-2]+1;
     cout<<"  ";
     for(int i=0;i<len;i++){
         cout<<nombre[i]<<"  ";
     }
     cout<<endl;
     mostrar(matriz);
     setMatriz(matriz);
     Nodos nodo1;
     nodo1.setMatriz(matriz);
 }
 void Nodos::eliminarenrutador()
 {
     char letra;
     int contador=0;
     int r=0;
     int l=0;
     cout<<"ingrese el enrutador que desa eliminar"<<endl;
     cin>>letra;
     while (nombre[contador]!=letra) {
         contador++;
     }
     while(r!=len){
         if(r!=contador){
            nombre[r]=nombre[l];
            r++;
            l++;
         }
         else{
             l++;
             nombre[r]=nombre[l];
             r++;
             l++;
         }
     }
     matriz.erase (matriz.begin()+contador);
     len--;
     for (int i=0;i<len;i++)
     {
         for (int j = 0 ; j <len ; j++)
         {
             if(j==contador){
                 matriz[i].erase (matriz[i].begin()+contador);
             }
         }
     }
     cout<<"  ";
     for(int i=0;i<len;i++){
        cout<<nombre[i]<<"  ";
     }
     cout<<endl;
     mostrar(matriz);
     setMatriz(matriz);
 }
 void Nodos::setMatriz(const Nodos::numeros2 &_matriz)
 {
     matriz=_matriz;
 }
 void Nodos::mostrar(const Nodos::numeros2 &matriz)
 {
     for (int i=0;i<len;i++)
         {
             cout<<nombre[i]<<" ";
             for (int j = 0 ; j <len ; j++)
             {
                 if(matriz[i][j]!=99){
                    cout<<matriz[i][j]<<" ";
                 }
                 else{
                     cout<<"~~"<<" ";
                 }
             }
             cout<<endl;
         }
 }
 class Red: public Nodos{
 private:
     //int tem[100]={99,99,99,99,99,99,99,99,99};
 public:
     Red();
     void caminosmascorto();
     void abrir_archivo();
 };
 Red::Red()
 {
 }
 void Red::caminosmascorto()
 {
     int op;
     cout<<"ingrese:"<<endl<<"1)calcular tabla del camino mas corto"<<endl<<"2)mostrar el camino mas rapido desde un router determinado a el resto de nodos"<<endl<<"3)calcular el costo desde un router inicial y final, como tambien el camino a seguir"<<endl;
     cin>>op;
     int BV=0;
     int cal;
     int r;
     switch (op) {
     case 1:{
         cal=len;
         BV=0;
         break;
     }
     case 2:{
         cal=1;
         char let;
         cout<<"ingrese el nodo inicial en mayusculas porfavor"<<endl;
         cin>>let;
         for(int cont=0;cont<len;cont++){
             if(nombre[cont]==let){
                 BV=cont;
             }
         }
         break;
     }
     case 3:{
         cal=1;
         char let;
         char letf;
         cout<<"ingrese el nodo inicial en mayusculas porfavor"<<endl;
         cin>>let;
         cout<<"ingrese el nodo final en mayusculas porfavor"<<endl;
         cin>>letf;
         for(int cont=0;cont<len;cont++){
             if(nombre[cont]==let){
                 BV=cont;
             }
             else if(nombre[cont]==letf){
                 r=cont;
             }
         }
         break;
     }
     }
     int iter=0;
     int menor=0;
     for(int re=0;re<cal;re++,BV++){
         int tem[100]={99,99,99,99,99};
         int temp;
         int final[100]={};
         int contador=0;
         int numero=0;
         int temporal=0;
         int c=0;
         int recor[100]={};
         int cr=0;
         int a=0;
         int identificar=0;
         int identi=99;
         for(int i=0;i<len;i++){
             tem[i]=99;
         }
         for(int y=0;y<len;y++){
             for(int o=0;o<len;o++){
                 matriz1[y][o]=matriz[y][o];
             }
         }
         for(int put=BV;numero<len-1;put=temp,numero++){
             for(int repu=0;repu<len;repu++){
                 if(matriz[put][repu]==0){
                     tem[repu]=0;
                 }
                 else{
                     if(matriz[put][repu]+menor<tem[repu]){
                     tem[repu]=matriz[put][repu]+temporal;
                     }
                     else{
                         if(tem[repu]!=0){
                            identificar=1;
                            if(tem[repu]<identi){
                               identi=tem[repu];
                            }
                         }
                     }
                 }
             }
             int n1;
             int n2=99;
             for(int elquelolea=0;elquelolea<len;elquelolea++)
             {
                 n1= tem[elquelolea];
                 if (n1<n2 and n1!=99 and n1!=0 )
                 {
                     menor=n1;
                     n2=n1;
                      contador=elquelolea;
                      if(n1==identi){
                          identificar=2;
                      }
                 }
             }
             temp=contador;
             final[temp]=menor;
             if(identificar==2){
                 temporal=menor;
             }
             else{
                 temporal+=menor;
             }
             c++;
      }
         if(op!=3){
             if(iter==0){
                 for(int r=0;r<len;r++){
                     cout<<"  "<<nombre[r];
                 }
                 cout<<endl;
                 iter++;
             }
             cout<<nombre[iter-1]<<" ";
             for(int r=0;r<len;r++){
                 cout<<final[r]<<" ";
             }
             cout<<endl;
             iter++;
         }
         else{
             int y=BV;
             int o=r;
             recor[cr]=nombre[r];
             if( matriz1[y][o]==final[o]){
                 recor[0]=nombre[r];
                 a=2;
             }
             cout<<"el costo del camino usado para llegar al destino es: "<<endl;
             cout<<final[r]<<endl;
             cout<<"el camino para llegar al destino es: "<<endl;
             for(int r=0;r<=a;r++){
                     cout<<char(recor[r])<<", ";
             }
         }
     }
 }
 void Red::abrir_archivo()
 {
     ofstream fout;
     ifstream fin;
     int array[300];
     int i=0;
     int numeroPoner;
     fin.open("datos.txt");
     int len1=len;
     int enter=0;
     while(fin.good())
     {
         int temp = fin.get();
         if (fin.good())
         {
             if (temp >char(47) and temp < char(58))
             {
                 numeroPoner=temp-48;
                 array[i]=numeroPoner;
                 i++;
             }
             if(temp==char(10)){
                 enter++;
             }
         }
     }
     //len1=enter+1;
     int contador=0;
     for (int x=0;x<len1;x++)
     {
         for (int y=0;y<len1;y++)
         {
             matriz[x][y]=array[contador];
             contador++;
             if (matriz[x][y]==9)
             {
                 matriz[x][y]=99;
             }
         }
     }
         fin.close();
 //ACA TERMINA DE ABRIR Y CARGAR LA MATRIZ DEL ARCHIVO.
     //CONVERTIMOS LA DIAGONAL..
     for (int i = 0 ;i <len ; i++)
     {
         for (int j=0;j<len1;j++)
         {
             if (i==j)
             {
                 matriz[i][j]=0;
             }
         }
     }
     //ESTE FOR EMPIEZA A LLENAR LA MATRIZ SEGUN LA CANTIDAD DE NODOS Y TODO DEPENDIENDO
     // DEL PRIMER NODO.
     for (int i = 0 ;i <len1 ; i++)
     {
         for (int j=0;j<len1;j++)
         {
             if (i!=j)
             {

                 matriz[j][i]=matriz[i][j];
             }
         }
     }
     setMatriz(matriz);

 }
#endif // MANAGER_H
