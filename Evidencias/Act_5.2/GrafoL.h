#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#include "HashL.h"

template<class T>
class GrafoL{
private:
    HashL hashVert;
    int findVertex(string);
    void dfsR(T vertex, vector<bool> &status);
public:
    vector < vector<T> > ady;
    GrafoL(vector< vector<T> >,HashL);
    void printAdy(string dato);
    void print();
    void bfs();
    void dfs();
};

template<class T>
GrafoL<T>::GrafoL(vector< vector<T> > lista,HashL vert){
    hashVert=vert;
    ady=lista;
}

template<class T>
int GrafoL<T>::findVertex(string dato){
    int index=hashVert.findData(dato);
    return index;
}

template<class T>
void GrafoL<T>::printAdy(string dato){
    int index=hashVert.findData(dato);
    cout<<dato<<" ";
    for(auto i : ady[index]){
        cout<<i<<" ";
    }
    cout<<endl;
}