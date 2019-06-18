
#include "NodoCaja.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

NodoCaja::NodoCaja(int id){
    this->id = id;
    this->tiempoDeServicio = 1;
    this->ocupado = false;
}

void NodoCaja::setCliente(Nodo* cliente){
    this->cliente = cliente;
}

void NodoCaja::estaOcupado(){
    return this->ocupado;
}

void NodoCaja::getCliente(){
    return this->cliente;
}

void NodoCaja::setStatus(bool flag){
    this->ocupado = flag;
}

void NodoCaja::vaciarCaja() {
    this->ocupado = false;
    this->cliente = nullptr;
}
