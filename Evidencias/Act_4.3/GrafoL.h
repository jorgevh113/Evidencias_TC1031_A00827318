#ifndef GrafoL_h
#define GrafoL_h

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

template<class T>
class GrafoL{
private:
    vector<T> vertices;
    int findVertex(T);
    void dfsR(T vertex, vector<bool> &status);
public:
    vector < vector<T> > ady;
    GrafoL(vector< vector<T> >,vector<T>);
    void print();
    void bfs();
    void dfs();
};

template<class T>
GrafoL<T>::GrafoL(vector< vector<T> > lista,vector<T> vert){
    for(int i=0;i<vert.size();i++){
        vertices.push_back(vert[i]);
    }

    sort(vertices.begin(),vertices.end());

    T temp;
    vector<T> vertTemp;
    for(auto vert : vertices){
        vertTemp.clear();
        temp=vert;
        vertTemp.push_back(temp);
        ady.push_back(vertTemp);
    }

    for(auto relacion : lista){
        int pos=findVertex(relacion[0]);
        if(pos!=-1){
            ady[pos].push_back(relacion[1]);
        }
    }
}

template<class T>
int GrafoL<T>::findVertex(T dato){
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), dato);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
}

template<class T>
void GrafoL<T>::print(){
    for(int i=0;i<vertices.size();i++){
        for(auto arista : ady[i]){
            cout<<arista<<" ";
        }
        cout<<endl;
    }
}


template<class T>
void GrafoL<T>::bfs(){
    vector<bool> status(vertices.size(),false);
    queue<int> q;
    q.push(0);
    status[0] = true;
    while (!q.empty()) {
        int vertex = q.front();
        cout << vertices[vertex] << " ";
        for (auto adj : ady[vertex]) {
            int pos = findVertex(adj.destino);
            if (!status[pos]) {
                q.push(pos);
                status[pos] = true;
            }
        }
        q.pop();
    }
    cout << endl;
}

template<class T>
void GrafoL<T>::dfs(){
    vector<bool> status(vertices.size(),false);
    dfsR(vertices[0],status);
    cout << endl;
}

template<class T>
void GrafoL<T>::dfsR(T vertex, vector<bool> &status) {
    int pos = findVertex(vertex);
    if (!status[pos]) {
        cout << vertex << " ";
        status[pos] = true;
        for (auto adj : ady[pos]) {
            int posAdj = findVertex(adj.destino);
            if (!status[posAdj]) {
                dfsR(adj.destino,status);
            }
        }
    }
}

#endif