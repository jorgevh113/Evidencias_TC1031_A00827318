//Autor: Jorge Antonio Villegas Hernández
//Matrícula: A00827318
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

#include "Hora.h"

//Estructura de datos
struct datos{
    int mes;
    int dia;
    Hora tiempo;
    string id;
    string nombreMes;
    string error;
    string hourS;
    string minS;
    string segS;
    int llave;
};

//Ordenamiento por inserción
void ordenar(vector<datos> &lista){
    datos aux;
    for(int i=1;i<lista.size();i++){
        for(int j=i;j>0;j--){
            if(lista[j].llave<lista[j-1].llave){
                aux=lista[j];
                lista[j]=lista[j-1];
                lista[j-1]=aux;
            }
        }
    }
}

//Impresion de datos
void imprimir(vector<datos> lista,int inicio,int final){
    ofstream salida;
    salida.open("salida.txt");
    string hour;
    for(int i=inicio;i<final;i++){
        salida<<lista[i].nombreMes<<" "<<lista[i].dia<<" "<<lista[i].hourS<<":"<<lista[i].minS<<":"<<lista[i].segS<<" "<<lista[i].id<<" "<<lista[i].error<<endl;
    }
    salida.close();
}

//Búsqueda binaria
int binaria(vector<datos> &lista,int llaveI){
    int inicio=0,ultimo=lista.size(),central,cont=0;
    int indexI=0,indexF=0;
    central=(inicio+ultimo)/2;
    while(lista[central].llave!=llaveI & (cont<lista.size()*2)){
        if(lista[central].llave<llaveI){
            inicio=central++;
            central=(inicio+ultimo)/2;
        }
        else if(lista[central].llave>llaveI){
            ultimo=central--;
            central=(inicio+ultimo)/2;
        }
        cont++;
    }
    if(lista[central].llave==llaveI){
        return central;
    }
    else{
        cout<<"No existe la fecha buscada"<<endl;
    }
}

//Conversion de mes a entero
int conversionMes(string mesTemp){
    if(mesTemp=="Ene"){
        return 1;
    }
    else if(mesTemp=="Feb"){
        return 2;
    }
    else if(mesTemp=="Mar"){
        return 3;
    }
    else if(mesTemp=="Abr"){
        return 4;
    }
    else if(mesTemp=="May"){
        return 5;
    }
    else if(mesTemp=="Jun"){
        return 6;
    }
    else if(mesTemp=="Jul"){
        return 7;
    }
    else if(mesTemp=="Aug"){
        return 8;
    }
    else if(mesTemp=="Sep"){
        return 9;
    }
    else if(mesTemp=="Oct"){
        return 10;
    }
    else if(mesTemp=="Nov"){
        return 11;
    }
    else{
        return 12;
    }
}


int main(){
    string mesTemp,idTemp,errorTemp;
    int diaTemp,horas,min,seg,claveTemp=0;
    string horaTemp;
    datos datosTemp;
    Hora tiempoTemp;
    vector<datos> base;
    ifstream bitacora;
    bitacora.open("bitacora.txt");
    //Lectura de archivo de texto y creación de estructura de datos
    while(bitacora>>mesTemp>>diaTemp>>horaTemp>>idTemp){
        getline(bitacora,errorTemp);
        datosTemp.mes=conversionMes(mesTemp);
        claveTemp=(datosTemp.mes*100000000);
        datosTemp.nombreMes=mesTemp;

        datosTemp.dia=diaTemp;
        claveTemp+=(diaTemp*1000000);

        horas=stoi(horaTemp.substr(0,2));
        datosTemp.hourS=horaTemp.substr(0,2);
        claveTemp+=(horas*10000);
        min=stoi(horaTemp.substr(3,5));
        datosTemp.minS=horaTemp.substr(3,2);
        claveTemp+=(min*100);
        seg=stoi(horaTemp.substr(6,8));
        datosTemp.segS=horaTemp.substr(6,2);
        claveTemp+=(seg);
        tiempoTemp.setHora(horas);
        tiempoTemp.setMin(min);
        tiempoTemp.setSeg(seg);
        datosTemp.tiempo=tiempoTemp;

        datosTemp.id=idTemp;

        datosTemp.error=errorTemp;

        datosTemp.llave=claveTemp;

        base.push_back(datosTemp);
    }
    bitacora.close();
    ordenar(base);
    
    int opcion;
    
    do{
        cout<<"Accion a realizar (se visualiza en el archivo salida.txt)"<<endl;
        cout<<"1) Ordenar la lista "<<endl;
        cout<<"2) Busqueda de archivos"<<endl;
        cout<<"3) Salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                imprimir(base,0,base.size());
                break;
            case 2:
                string mesI,mesF,horaI,horaF;
                int claveI,claveF,diaI,diaF,indexI,indexF;
                cout<<"Inserte la fecha y hora de inicio"<<endl;
                cin>>mesI>>diaI>>horaI;
                claveI=(conversionMes(mesI)*100000000);
                claveI+=(diaI*1000000);
                claveI+=((stoi(horaI.substr(0,2)))*10000);
                claveI+=((stoi(horaI.substr(3,2)))*100);
                claveI+=(stoi(horaI.substr(6,2)));
                indexI=binaria(base,claveI);
                cout<<"Posicion: "<<indexI<<endl;

                cout<<"Inserte la fecha y hora finales"<<endl;
                cin>>mesF>>diaF>>horaF;
                claveF=(conversionMes(mesF)*100000000);
                claveF+=(diaF*1000000);
                claveF+=((stoi(horaF.substr(0,2)))*10000);
                claveF+=((stoi(horaF.substr(3,2)))*100);
                claveF+=(stoi(horaF.substr(6,2)));
                indexF=binaria(base,claveF);
                cout<<"Posicion: "<<indexF<<endl;

                imprimir(base,indexI,indexF+1);
                break;
        }
    }while(opcion!=3);

    return 0;
}