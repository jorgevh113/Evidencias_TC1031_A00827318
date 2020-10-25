//Autor: Jorge Antonio Villegas Hernández
//Matrícula: A00827318
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Datos.h"
#include "Heap.h"

struct IP{
    IP();
    IP(string id);
    string id;
    int cont;
    void addOne(){cont++;};
    bool operator==(IP id);
    bool operator>(IP id);
    bool operator>=(IP id);
    bool operator<(IP id);
    bool operator<=(IP id);
    void operator=(IP id);
};

IP::IP(){
    id="  ";
    cont=0;
}

IP::IP(string id){
    this->id=id;
    cont=1;
}

bool IP::operator==(IP id){
    return id==id;
}

bool IP::operator<(IP id){
    return this->cont<id.cont;
}

bool IP::operator<=(IP id){
    return this->cont<=id.cont;
}

bool IP::operator>(IP id){
    return this->cont>id.cont;
}

bool IP::operator>=(IP id){
    return this->cont>=id.cont;
}

void IP::operator=(IP id){
    this->cont=id.cont;
    this->id=id.id;
}


template<class T>
void HeapSort(DLL<T> &list, string order = "ascending") {
    if (!list.isEmpty()) {
        Heap<T> heapAux(list);
        list.clear();
        while (!heapAux.isEmpty()) {
            T aux = heapAux.remove();
            if (order == "ascending") {
                list.addFirst(aux);
            } else {
                list.addLast(aux);
            }
        }
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

void imprimir(Heap<datos> lista,int inicio,int final){
    ofstream salida;
    salida.open("salida.txt");
    string hour;
    for(int i=inicio;i<final;i++){
        salida<<lista[i].nombreMes<<" "<<lista[i].dia<<" "<<lista[i].hourS<<":"<<lista[i].minS<<":"<<lista[i].segS<<" "<<lista[i].id<<" "<<lista[i].error<<endl;  
    }
    salida.close();
}

int main(){
string mesTemp,idTemp,errorTemp;
    int diaTemp,horas,min,seg,claveTemp=0;
    string horaTemp;
    datos datosTemp;
    Hora tiempoTemp;
    DLL<datos> base;
    ifstream bitacora;
    bitacora.open("bitacora2.txt");

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

        base.addFirst(datosTemp);
    }
    bitacora.close();
    HeapSort(base,"descending");
    imprimir(base,1,base.getSize()+1);

    IP ipTemp(base[1].id.substr(0,base[1].id.find(":")));
    DLL<IP> visitas;
    for(int i=2;i<base.getSize()+1;i++){
        if(ipTemp.id==base[i].id.substr(0,base[i].id.find(":"))){
            ipTemp.addOne();
        } else{
            visitas.addLast(ipTemp);
            ipTemp=base[i].id.substr(0,base[i].id.find(":"));
            ipTemp.cont=1;
        }
    }
    HeapSort(visitas,"descending");
    for(int i=1;i<=5;i++){
        cout<<visitas[i].id<<" "<<visitas[i].cont<<endl;
    }
    
    return 0;
}