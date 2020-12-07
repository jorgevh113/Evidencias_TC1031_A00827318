#ifndef HashL_h
#define HashL_h

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class HashL{
    private:
        int hashing(string);
        int lineartest(int index);
        int linearfind(int index,string data);
        void addData(string);
        bool isFull();
        int qty;
    public:
        HashL();
        HashL(vector<string> lista);
        string operator[](int);
        void operator=(HashL);
        int findData(string);
        void print();
        vector<string> table;
        int size;
        vector<int> estado; // 0-vacío 1-Ocupado 2-Borrado
};

HashL::HashL(){
    table={""};
    size=0;
    estado={0};
    table.clear();
    estado.clear();
    
}

HashL::HashL(vector<string> lista){
    size=lista.size();
    vector<string> tmpTable(size);
    table=tmpTable;
    vector<int> tmpStatus(size,0);
    estado=tmpStatus;
    for(auto data : lista){
        addData(data);
    }
}

void HashL::addData(string data){
    if(!isFull()){
        int index=hashing(data);
        int newIndex=lineartest(index);
        table[newIndex]=data;
        estado[newIndex]=1;
        qty++;
    }
}

bool HashL::isFull(){
    return size==qty;
}

int HashL::hashing(string data){
    int key=0;
    for(auto c : data){
        key+= (unsigned char)c;
    }

    return key%size;
}

int HashL::lineartest(int index){
    if(estado[index]!=1){
        return index;
    }
    int newIndex=index;
    while(estado[newIndex]==1){
        newIndex+=1;
        if(newIndex>size-1){
            newIndex=0;
        }
    }
    return newIndex;
}

int HashL::linearfind(int index,string data){
    if(table[index]==data){
        return index;
    }
    int cont=0;
    int newIndex=index;
    while(table[newIndex]!=data && cont<size){
        newIndex+=1;
        if(newIndex>size-1){
            newIndex=0;
        }
        cont++;
    }
    return newIndex;
    
}

string HashL::operator[](int index){
    return table[index];
}

int HashL::findData(string data){
    int index=hashing(data);
    if(table[index]==data){
        return index;
    }
    int newIndex=linearfind(index,data);
    return newIndex;
}

void HashL::print(){
    for(auto i : table){
        cout<<i<<endl;
    }
}

void HashL::operator=(HashL lista){
    size=lista.size;
    table.clear();
    estado.clear();
    for(auto i : lista.table){
        table.push_back(i);
    }
    for(auto i : lista.estado){
        estado.push_back(i);
    }
}
#endif