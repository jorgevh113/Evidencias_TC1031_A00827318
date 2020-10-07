#include <iostream>

using namespace std;

#include "Doubly.h"

int main(){
    Doubly<int> lista;
    lista.addFirst(2);
    lista.addFirst(1);
    lista.addLast(3);
    lista.deleteAt(2);
    lista.print();
}