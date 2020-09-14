#ifndef Hora_h
#define Hora_h

class Hora{
    public:
        Hora();
        Hora(int hora,int min,int seg);
        void setHora(int hora){this->hora=hora;};
        int getHora(){return hora;};
        void setMin(int min){this->min=min;};
        int getMin(){return min;};
        void setSeg(int seg){this->seg=seg;};
        int getSeg(){return seg;};
        void mostrar();

    private:
        int hora;
        int min;
        int seg;
};

Hora::Hora(){
    hora=0;
    min=0;
    seg=0;
}

Hora::Hora(int hora,int min,int seg){
    this->hora=hora;
    this->min=min;
    this->seg=seg;
}

void Hora::mostrar(){
    cout<<hora<<":"<<min<<":"<<seg;
}
#endif