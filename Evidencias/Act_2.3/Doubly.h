//Autor: Jorge Antonio Villegas Hernández
//Matrícula:: A00827318

#include "Node.h"

template<class T>
struct Doubly{
    Node<T>* head;
    Node<T>* tail;
    int size;

    bool isEmpty(){return size==0;};

    Doubly();
    void addFirst(T data);
    void addLast(T data);
    void print();
    
    bool deleteData(T data);
    bool deleteAt(int index);
    void updateAt(int index,T data);
    T getData(int index);
    bool updateData(T search,T replace);
    int findData(T search);
    void clear();
    T operator[](int index);
    void operator=(T data);
};

template<class T>
Doubly<T>::Doubly(){
    head=NULL;
    tail=NULL;
    size=0;
}

template<class T>
void Doubly<T>::addFirst(T data){
    if(isEmpty()){
        head=new Node<T>(data);
        tail=head;
        size++;
    } else{
        head->prev=new Node<T>(data);
        head->prev->next=head;
        head=head->prev;
        size++;
    }
}

template<class T>
void Doubly<T>::addLast(T data){
    if(isEmpty()){
        head=new Node<T>(data);
        tail=head;
        size++;
    } else{
        tail->next=new Node<T>(data);
        tail->next->prev=tail;
        tail=tail->next;
        size++;
    }
}

template<class T>
void Doubly<T>::print(){
    Node<T>* aux=head;
    for(int i=0;i<size;i++){
        std::cout<<aux->data<<" ";
        aux=aux->next;
    }
    std::cout<<endl;
}

template<class T>
bool Doubly<T>::deleteData(T data){
    if(!isEmpty()){
        Node<T> *aux=head;
        if(aux->data==data){ 
            head=aux->next;
            delete aux;
            size--;
            return true;
        } else{
            if(aux->next!=NULL){
                Node<T> *previo=aux;
                aux=aux->next;
                
                while(aux!=NULL){
                    if(aux->data==data){
                        previo->next=aux->next;
                        size--;                        
                        return true;
                    } else{
                        previo=aux;
                        aux=aux->next; 
                    }
            }
        }
    }
    } else{
        return false;
    }
}

template<class T>
bool Doubly<T>::deleteAt(int index){
    if(index>=0 && index<size){
        int i=0;
        Node<T>* aux=head;
        if(i==index){
            head=head->next;
            delete aux;
            size--;
            return true;
        } else{
            for (i=0;i<index;i++){
                aux=aux->next;
            }
            aux->prev->next=aux->next;
            delete aux;
            size--;
            return true;
        }
    } else{
        throw out_of_range("Posicion invalida en deleteAt");
    }
}

template<class T>
T Doubly<T>::getData(int index){
    cout<<"Dentro"<<endl;
    cout<<index<<" "<<size<<endl;
    if(index>=0 && index<size){
        Node<T>* aux=head;
        for(int i=0;i<size-1;i++){           
            if(i==index){
                return aux->data;
            } else{
                aux=aux->next;
            }
        }
    } else{
        throw out_of_range("Posicion invalida en getData");
    }
}

template<class T>
void Doubly<T>::updateAt(int pos,T nuevoDato){
    int tam=size;
     if(!isEmpty()){
        if (pos >= 0 && pos < tam){
            if(pos < tam/2){
                Node<T>* aux = head;
                int i = 0;
                while (aux != nullptr){
                    if (i == pos){
                        aux->data= nuevoDato;
                        return;
                    }
                aux = aux->next;
                i++;
                }
            }else{
                Node<T>* aux = tail;
                int i = tam-1;
                while (aux != nullptr){
                    if (i == pos){
                        aux->data = nuevoDato;
                        return;
                    }
                aux = aux->prev;
                i--;
                }
            }
        }else{
            throw out_of_range("Posicion invalida");
        }
    }else{
        throw out_of_range("Posicion invalida");
    }
}

template<class T>
T Doubly<T>::operator[](int index){
    if(index>=0 && index<size){
        Node<T>* aux=head;
        for(int i=0;i<size;i++){
            if(i==index){
                return aux->data;
            } else{
                aux=aux->next;
            }
        }
    }
}
