//Autor: Jorge Antonio Villegas Hernández
//Matrícula: A00827318

#ifndef Node_h
#define Nodo_h

template<class T>
struct Node{
    Node<T>* next;
    Node<T>* prev;
    T data;
    int size;
    Node();
    Node(T data);
};

template<class T>
Node<T>::Node(){
    next=NULL;
    prev=NULL;
    data=0;
}

template<class T>
Node<T>::Node(T data){
    next=NULL;
    prev=NULL;
    this->data=data;
}
#endif