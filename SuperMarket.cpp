/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#include "SuperMarket.h"
void SuperMarket::agregarClienteAEspera(Nodo* cliente){
    this->clientes->encolar(cliente);
}


bool SuperMarket::hayCarretas(){
    Nodo *carretaSaliendo;
    if(!pilaCarreta1->estaVacia()) {
        carretaSaliendo = pilaCarreta1->desapilar();
    } else if(!pilaCarreta2->estaVacia()){
        carretaSaliendo = pilaCarreta2->desapilar();
    } else {
        cout<<"No hay carretas disponibles en este momento, cliente en espera"<<endl;
        return false;
    }
    if(clientes->estaVacia()){
        Nodo *clienteSaliendo = clientes->descolar();
        this->clientesComprando->insertar(clienteSaliendo);
    } else {
        cout<<"No hay mas clientes que atender"<<endl;
        return false;
    }
    return true;
}


Nodo* SuperMarket::crearCliente(int id){
    Nodo* nuevoCliente = new Nodo(id,nullptr);
    return nuevoCliente;
}

Nodo* SuperMarket::crearCaja(int id){
    NodoCaja* nuevaCaja = new NodoCaja(id);
    return nuevaCaja;
}