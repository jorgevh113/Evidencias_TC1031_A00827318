#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "HashL.h"
#include "GrafoL.h"

int main(){
    ifstream archivo;
    int cantIp,cantRegistros,cont=0,pos;
    string ip,ipDestin,omitir;
    vector<string> vecStr;
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
    HashL hash(vecStr);
    vector<string> temp={"0"};
    for(int i=0;i<vecStr.size();i++){
        listAdy.push_back(temp);
    }
    int index;
    archivo>>omitir>>omitir>>ip>>ipDestin>>omitir;
    pos=ip.find(":");
    ip=ip.substr(0,pos);
    pos=ipDestin.find(":");
    ipDestin=ipDestin.substr(0,pos);
    getline(archivo,omitir);
    index=hash.findData(ip);
    listAdy[index].push_back(ipDestin);
    

    while(archivo>>omitir>>omitir>>omitir>>ip>>ipDestin>>omitir){
        getline(archivo,omitir);
        pos=ip.find(":");
        ip=ip.substr(0,pos);
        pos=ipDestin.find(":");
        ipDestin=ipDestin.substr(0,pos);
        index=hash.findData(ip);
        listAdy[index].push_back(ipDestin);
    }
    

    GrafoL<string> Grafo(listAdy,hash);
    cout<<"IP a buscar"<<endl;
    cin>>ip;
    Grafo.printAdy(ip);
}
