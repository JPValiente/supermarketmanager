#include"Cola.h"
#include "Nodo.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

Nodo *inicio,*fin;


Cola::Cola() {
    
}
void Cola::encolar(Nodo*nodo){
    if(inicio == nullptr && fin == nullptr) {
        inicio = fin =  nodo;
    } else {
        fin->siguiente = nodo;
        fin = nodo;
    }
    
}

Nodo* Cola::descolar(){
    if(inicio != nullptr && fin != nullptr){
        Nodo * aux = inicio;
        inicio = inicio->siguiente;
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





