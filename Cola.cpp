#include"Cola.h"
#include "Nodo.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <thread>
using namespace std;

Nodo *inicio,*fin;


Cola::Cola() {
    inicio = fin = nullptr;
    total = 0;
}
void Cola::encolar(Nodo*nodo){
    
    if(inicio == nullptr && fin == nullptr) {
        inicio = fin =  nodo;
    } else {
        fin->siguiente = nodo;
        fin = nodo;
    }
    total++;
    cout<<"Cliente "<<nodo->id<<" entro a la cola"<<endl;
    
}

Nodo* Cola::descolar(){
    if(inicio != nullptr && fin != nullptr){
        Nodo * aux = inicio;
        inicio = inicio->siguiente;
        total--;
        cout<<"Cliente "<<aux->id<<" salio de la cola"<<endl;
        return aux;
    } else {
        cout<<"Lista vacia";
    }
    
}

bool Cola::estaVacia() {
    if(inicio == nullptr && fin == nullptr) {
        return true;
    }
    return false;
}





