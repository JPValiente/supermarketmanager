#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "ListaDoble.h"
#include "Nodo.h"

using namespace std;

ListaDoble::ListaCircular(){
    this->inicio = this->fin = nullptr;
    this->totalElementos = 0;
}

ListaDoble::insertar(Nodo *nodo){
    if(inicio == nullptr == fin){
        inicio = fin = nodo;
    } else {
        fin->siguiente = nodo;
        nodo->anterior = fin;
        fin = nodo;
    }
    this->totalElementos = this->totalElementos + 1;
}

ListaDoble::borrar(int id){
    if(this->estaVacia() == 1){
        cout<<"Lista Circular Vacia";
    } else {
        
        if(inicio == fin && inicio->id == id) {
            inicio = fin = nullptr;
        } else {
            if(inicio->id == id){
                inicio = inicio->siguiente;
            } else if(fin->id == id) {
                fin = fin->anterior;
            } else {
                Nodo* aux = inicio;
                while(aux->siguiente != nullptr){
                    if(aux->id == id){
                        break;
                    }
                    aux = aux->siguiente;
                }
                Nodo* anterior = aux->anterior;
                Nodo* siguiente = aux->siguiente;
                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;
            }
            
        }
    }
}

ListaCircular::estaVacia(){
    if(inicio == fin == nullptr){
        return 1;
    } else {
        return 0;
    }
}

