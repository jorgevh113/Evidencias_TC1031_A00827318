//Autor: Jorge Villegas
//Matrícula:: A00827318

#ifndef Deque_h
#define Deque_h

#include "Node.h"
template<class T>

struct Deque{
    Node<T>* head;
    Node<T>* tail;
    int size;
    Deque();
    T dequeue();
    void enqueue(T data);
    T front(){return head->data;};
    T back(){return tail->data;};
    int getSize(){return size;};
    void clear();
    void print();
    bool isEmpty(){return size==0;};
    T operator[](int index);
};

template<class T>
Deque<T>::Deque(){
    head=NULL;
    tail=NULL;
    size=0;
}

template<class T>
void Deque<T>::enqueue(T data){
    if(isEmpty()){
        head=new Node<T>(data);
        tail=head;
        size++;
    } else{
        tail->next=new Node<T>(data, tail);
        tail = tail->next;
        if(size == 1){
            head->next = tail;
        }
        size++;
    }
}

template<class T>
T Deque<T>::dequeue(){
    if(!isEmpty()){
        T valor;
        Node<T>* aux=head;
        valor=head->data;
        head=aux->next;
        delete aux;
        size--;
        return valor;
    } else{
        std::cout<<"No fue posible realizar el proceso"<<endl;
    }
}

template<class T>
void Deque<T>::clear(){
    for(int i=0;i<size;i++){
        Node<T>* aux=head;
        head=head->next;
        delete aux;
    }
    tail=head;
    size=0;
}

template<class T>
void Deque<T>::print(){
    if(!isEmpty()){
        Node<T>* aux=head;
        for(int i=0;i<size;i++){
            std::cout<<aux->data<<" ";
            aux=aux->next;
        }
        std::cout<<endl;
    } else{
        std::cout<<"Lista vacia"<<endl;
    }
}

template<class T>
T Deque<T>::operator[](int index){
    if(index>=0 && index<size){
        Node<T>* aux=head;
        for(int i=0;i<size;i++){
            if(i==index){
                return aux->data;
            } else{
                aux=aux->next;
            }
        }
    } else{
        throw out_of_range("Posicion invalida en queue");
    }
}

#endif