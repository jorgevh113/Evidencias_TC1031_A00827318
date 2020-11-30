#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "GrafoL.h"
#include "Ip.h"
#include "Heap.h"

template<class T>
void HeapSort(vector<T> &list) {
    if (!list.empty()) {
        Heap<T> heapAux(list);
        list.clear();
        while (!heapAux.isEmpty()) {
            T aux = heapAux.remove();
            list.push_back(aux);
        }
    }
}

int main(){
    ifstream archivo;
    int cantIp,cantRegistros,cont=0,pos;
    string ip,ipDestin,omitir;
    vector<string> vecStr;
    vector<string> ady;
    vector< vector<string> > listAdy;
    archivo.open("bitacora.txt");

    archivo>>cantIp>>cantRegistros;
    while(archivo>>ip){
        if(cont==cantIp){
            break;
        }
        vecStr.push_back(ip);
        cont++;
    }
    archivo>>omitir>>omitir>>ip>>ipDestin>>omitir;
    pos=ip.find(":");
    ip=ip.substr(0,pos);
    ady.push_back(ip);
    pos=ipDestin.find(":");
    ipDestin=ipDestin.substr(0,pos);
    ady.push_back(ipDestin);
    getline(archivo,omitir);
    listAdy.push_back(ady);
    while(archivo>>omitir>>omitir>>omitir>>ip>>ipDestin>>omitir){
        getline(archivo,omitir);
        ady.clear();
        pos=ip.find(":");
        ip=ip.substr(0,pos);
        ady.push_back(ip);
        pos=ipDestin.find(":");
        ipDestin=ipDestin.substr(0,pos);
        ady.push_back(ipDestin);
        listAdy.push_back(ady);
    }

    GrafoL<string> Grafo(listAdy,vecStr);
    
    vector<Ip> visitas;
    Ip temp;

    for(auto vert : Grafo.ady){
        temp.ip=vert[0];
        temp.visitas=vert.size()-1;
        visitas.push_back(temp);
    }

    HeapSort(visitas);

    for(int i=0;i<5;i++){
        visitas[i].print();
    }

    
}