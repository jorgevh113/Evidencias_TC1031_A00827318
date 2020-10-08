#ifndef Datos_h
#define Datos_h

#include "Hora.h"
#include <string>

struct datos{
    datos();
    int mes;
    int dia;
    Hora tiempo;
    std::string id;
    std::string nombreMes;
    std::string error;
    std::string hourS;
    std::string minS;
    std::string segS;
    int llave;
    bool operator<(datos comp);
    bool operator<=(datos comp);
    bool operator==(datos comp);
    bool operator>=(datos comp);
    bool operator>(datos comp);
};

datos::datos(){
    mes=0;
    dia=0;
    tiempo=Hora();
    id="";
    nombreMes="";
    error="";
    hourS="";
    minS="";
    segS="";
    llave=0;
}

bool datos::operator<(datos comp){
    if(llave<comp.llave){
        return true;
    } else{
        return false;
    }
}

bool datos::operator<=(datos comp){
    if(llave<=comp.llave){
        return true;
    } else{
        return false;
    }
}

bool datos::operator==(datos comp){
    if(llave==comp.llave){
        return true;
    } else{
        return false;
    }
}

bool datos::operator>=(datos comp){
    if(llave>=comp.llave){
        return true;
    } else{
        return false;
    }
}
bool datos::operator>(datos comp){
    if(llave>comp.llave){
        return true;
    } else{
        return false;
    }
}
#endif