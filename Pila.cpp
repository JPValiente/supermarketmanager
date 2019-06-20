#include<stdlib.h>
#include<stdio.h>
#include"Pila.h"
#include "Nodo.h"
#include<iostream>
#include <thread>

using namespace std;

Nodo *tope,*fondo;


Pila::Pila(){
    tope = fondo = nullptr;
    this->inicio = fondo;
    this->fin = tope;
}
void Pila::apilar(Nodo*nodo){
    if(tope == nullptr && fondo == nullptr) {
        fondo = tope =  nodo;
        inicio = fin = nodo;
    } else {
        nodo->siguiente = tope;
        tope = nodo;
        fin = nodo;
    }
    this->total = this->total + 1;
}

Nodo* Pila::desapilar(){
    if(tope != nullptr && fondo != nullptr){
        Nodo*aux = aux;
        aux = tope;
        if(tope == fondo){
            tope = fondo = nullptr;
            inicio = fin = nullptr;
        } else {
            tope = tope->siguiente;
            fin = fin->siguiente;
        }
        this->total = this->total - 1;
        return aux;
    } else {
        cout<<"Lista vacia";
    }
    
}

void Pila::imprimirDatos(){
    Nodo * aux = tope;
    while(aux->siguiente != nullptr){
        cout<<"ID: "<<aux->id<<endl;
        aux = aux->siguiente;
    }
    cout<<"ID: "<<aux->id<<endl;
}

bool Pila::estaVacia() {
    if(tope == nullptr && fondo == nullptr) {
        return true;
    }
    return false;
}