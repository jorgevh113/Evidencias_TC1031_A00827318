#include <string>
#include <iostream>

using namespace std;

struct Ip{
    string ip;
    int visitas;
    void print();
    bool operator<(Ip comp);
    bool operator<=(Ip comp);
    bool operator==(Ip comp);
    bool operator>=(Ip comp);
    bool operator>(Ip comp);
};

void Ip::print(){
    cout<<ip<<" "<<visitas<<endl;
}

bool Ip::operator<(Ip comp){
    if(visitas<comp.visitas){
        return true;
    } else{
        return false;
    }
}

bool Ip::operator<=(Ip comp){
    if(visitas<=comp.visitas){
        return true;
    } else{
        return false;
    }
}

bool Ip::operator==(Ip comp){
    if(visitas==comp.visitas){
        return true;
    } else{
        return false;
    }
}

bool Ip::operator>=(Ip comp){
    if(visitas>=comp.visitas){
        return true;
    } else{
        return false;
    }
}

bool Ip::operator>(Ip comp){
    if(visitas>comp.visitas){
        return true;
    } else{
        return false;
    }
}