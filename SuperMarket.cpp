/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>
#include <thread>
//#include <pthread.h>
#include "SuperMarket.h"
#include "Pila.h"
#include "Cola.h"
#include "ListaDoble.h"
#include "ListaCircular.h"

using namespace std;

void SuperMarket::agregarClienteAEspera(Nodo* cliente){
    this->clientes->encolar(cliente);
}

SuperMarket::SuperMarket() {
    
}


bool SuperMarket::hayCarretas(){
    Nodo *carretaSaliendo;
    if(!pilaCarreta1->estaVacia()) {
    } else if(!pilaCarreta2->estaVacia()){
    } else {
        cout<<"No hay carretas disponibles en este momento, cliente en espera"<<endl;
        return false;
    }
    
    return true;
}

Nodo* SuperMarket::sacarCarreta(){
    Nodo *carretaSaliendo;
    if(!pilaCarreta1->estaVacia()) {
        carretaSaliendo = pilaCarreta1->desapilar();
    } else if(!pilaCarreta2->estaVacia()){
        carretaSaliendo = pilaCarreta2->desapilar();
    } else {
        cout<<"No hay carretas disponibles en este momento, cliente en espera"<<endl;
        return nullptr;
    }
    
    return carretaSaliendo;
}

void SuperMarket::asignarCarretaACliente(Nodo* cliente,Nodo* carreta){
    cliente->info = carreta;
}

/*
if(clientes->estaVacia()){
        Nodo *clienteSaliendo = clientes->descolar();
        clienteSaliendo->info = carretaSaliendo;
        agregarACompras(clienteSaliendo);
    } else {
        cout<<"No hay mas clientes que atender"<<endl;
        return false;
    } 
*/
Nodo* SuperMarket::sacarClienteDeCompras(){
    int totalClientes = this->clientesComprando->totalElementos;
    srand((int)time(0));
    int random = (rand() % 100) + 1;
    if(random <= totalClientes) {
        Nodo* cliente = clientesComprando->borrar(random);
        return cliente;
    } else {
        cout<<"No se hizo nada porque el numero random fue "<<random<<" y se esperaba un numero menos de "<<totalClientes<<endl;
        return nullptr;
    }
    
}

bool SuperMarket::encolarCliente(Nodo* cliente){
    this->colaDePagos->encolar(cliente);
}

void SuperMarket::agregarACompras(Nodo* cliente){
    this->clientesComprando->insertar(cliente);
}

bool SuperMarket::guardarCarreta(Nodo* carreta){
    srand((int)time(0));
    int pila = (rand() % 2) + 1;
    if(pila == 1){
        this->pilaCarreta1->apilar(carreta);
        cout<<"Carreta "<<carreta->id<<" guardada en la pila 1"<<endl;
    } else {
        this->pilaCarreta2->apilar(carreta);
        cout<<"Carreta "<<carreta->id<<" guardada en la pila 2"<<endl;
    }
}



NodoCaja* SuperMarket::asignarClienteACaja(){
    Nodo* cliente = this->colaDePagos->descolar();
    NodoCaja* aux = this->cajas->inicio;
    bool flag = false;
    while(aux->siguiente != nullptr){
        if(!aux->ocupado){
            flag = true;
            break;
        }
        aux = aux->siguiente;
    }
    if(flag){
        aux->ocupado = true;
        aux->cliente = cliente;
        return aux;
        
    } else {
        cout<<"Todas las cajas estan ocupadas"<<endl;
        return nullptr;
    }
    
}

void SuperMarket::atenderCajas(){
    sleep(200);
    NodoCaja* caja = cajas->inicio;
    while(caja != nullptr){
        if(caja->cumplioTiempo()){
            Nodo* carreta = (Nodo*)caja->cliente->info;
            cout<<"Cliente: "<<caja->cliente->id<<" atendido en caja "<<caja->id<<"."<<endl;
            caja->vaciarCaja();
            this->guardarCarreta(carreta);
        }
        caja = caja->siguiente;
    }
    
}


Nodo* SuperMarket::crearCliente(int id){
    Nodo* nuevoCliente = new Nodo(id,nullptr);
    return nuevoCliente;
}

NodoCaja* SuperMarket::crearCaja(int id){
    NodoCaja* nuevaCaja = new NodoCaja(id);
    return nuevaCaja;
}

Nodo* SuperMarket::crearCarreta(int id){
    Nodo* carreta = new Nodo(id,nullptr);
    return carreta;
}

void SuperMarket::agregarCajaAlSistema(NodoCaja* caja){
    this->cajas->insertar(caja);
}