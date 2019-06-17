#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#include "ListaCircular.h"
#include "Nodo.h"

using namespace std;


ListaCircular::ListaCircular(){
    this->inicio = nullptr;
    this->fin = nullptr;
    this->totalElementos = 0;
}

ListaCircular::insertar(Nodo *nodo){
    if(inicio == nullptr == fin){
        inicio = fin = nodo;
        inicio->siguiente = fin;
        inicio->anterior = fin;
        fin->siguiente = inicio;
        fin->anterior = inicio;
    } else {
        fin->siguiente = nodo;
        nodo->anterior = fin;
        nodo->siguiente = inicio;
        fin = nodo;
    }
    this->totalElementos = this->totalElementos + 1;
}

ListaCircular::borrar(int id){
    if(estaVacia() == 1){
        cout<<"Lista Circular Vacia";
    } else {
        
        if(inicio == fin && inicio->id == id) {
            inicio = fin = nullptr;
        } else {
            if(inicio->id == id){
                fin = inicio->siguiente;
                inicio->siguiente = fin;
                inicio = inicio->siguiente;
            } else if(fin->id == id) {
                fin = fin->anterior;
                fin->siguiente = inicio;
                inicio->anterior = fin;
                
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