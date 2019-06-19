
#include "NodoCaja.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <thread>

using namespace std;

NodoCaja::NodoCaja(int id){
    time_t  now = time(0);
    this->id = id;
    this->tiempoDeServicio = now;
    this->tiempoLimite = now + 60;
    this->ocupado = false;
}

void NodoCaja::setCliente(Nodo* cliente){
    this->cliente = cliente;
}

bool NodoCaja::estaOcupado(){
    return this->ocupado;
}

Nodo* NodoCaja::getCliente(){
    return this->cliente;
}

void NodoCaja::setStatus(bool flag){
    this->ocupado = flag;
}

void NodoCaja::vaciarCaja() {
    this->ocupado = false;
    this->cliente = nullptr;
}

bool NodoCaja::cumplioTiempo() {
    time_t ahorita  = time(0);
    if(ahorita <= this->tiempoLimite){
        cout<<"Tiempo valido"<<endl;
        return true;
    }
    return false;
}
