#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>

#include "ListaDoble.h"
#include "NodoCaja.h"

using namespace std;

ListaDoble::ListaDoble(){
    this->inicio = this->fin = nullptr;
    this->totalElementos = 0;
}

void ListaDoble::insertar(NodoCaja *nodo){
    if(estaVacia() == 1){
        this->inicio = this->fin = nodo;
    } else {
        if(nodo->id <= inicio->id){
            nodo->siguiente = inicio;
            inicio->anterior = nodo;
            inicio = nodo;
        } else if (nodo->id >= fin->id) {
            fin->siguiente = nodo;
            nodo->anterior = fin;
            fin = nodo;
        } else {
            NodoCaja *aux = inicio;
            while(aux->siguiente != nullptr){
                if(nodo->id >= aux->id) {
                    break;
                }
                aux = aux->siguiente;
            }
            NodoCaja *siguiente = aux->siguiente;
            aux->siguiente = nodo;
            nodo->anterior = aux;
            nodo->siguiente = siguiente;
            siguiente->anterior = nodo;
        }
    }
    this->totalElementos = this->totalElementos + 1;
}

void ListaDoble::borrar(int id){
    if(this->estaVacia() == 1){
        cout<<"Lista Circular Vacia";
    } else {
        
        if(this->inicio == this->fin && this->inicio->id == id) {
            this->inicio = this->fin = nullptr;
        } else {
            if(this->inicio->id == id){
                this->inicio = this->inicio->siguiente;
            } else if(this->fin->id == id) {
                this->fin = this->fin->anterior;
            } else {
                NodoCaja* aux = this->inicio;
                while(aux->siguiente != nullptr){
                    if(aux->id == id){
                        break;
                    }
                    aux = aux->siguiente;
                }
                NodoCaja* anterior = aux->anterior;
                NodoCaja* siguiente = aux->siguiente;
                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;
            }
            
        }
        totalElementos = totalElementos - 1;
    }
}

int ListaDoble::estaVacia(){
    if(this->inicio == nullptr && this->fin == nullptr){
        return 1;
    } else {
        return 0;
    }
}

