//Autor: Jorge Antonio Villegas Hernández
//Matrícula: A00827318

#ifndef Node_h
#define Node_h

template<class T>
struct Node{
    Node<T>* next;
    Node<T>* prev;
    T data;
    int size;
    Node();
    Node(T data);
    Node(T data,Node<T>* next,Node<T>* prev);
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

template<class T>
Node<T>::Node(T data,Node<T>* next,Node<T>* prev){
    this->next=next;
    this->prev=prev;
    this->data=data;
}
#endif