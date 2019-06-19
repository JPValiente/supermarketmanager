#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <thread>

#include "ListaCircular.h"
#include "Nodo.h"

using namespace std;


ListaCircular::ListaCircular(){
    this->inicio = nullptr;
    this->fin = nullptr;
    this->totalElementos = 0;
}

void ListaCircular::insertar(Nodo *nodo){
    if(estaVacia() == 1){
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

Nodo* ListaCircular::borrar(int id){
    if(estaVacia() == 1){
        cout<<"Lista Circular Vacia";
    } else {
        Nodo* auxiliar;
        if(inicio == fin && inicio->id == id) {
            auxiliar = inicio;
            inicio = fin = nullptr;
            
        } else {
            if(inicio->id == id){
                auxiliar = inicio;
                fin = inicio->siguiente;
                inicio->siguiente = fin;
                inicio = inicio->siguiente;
            } else if(fin->id == id) {
                auxiliar = fin;
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
                auxiliar = aux;
            }
            
        }
        this->totalElementos = this->totalElementos - 1;
        return auxiliar;
    }
}

int ListaCircular::estaVacia(){
    if(inicio == nullptr && fin == nullptr){
        return 1;
    } else {
        return 0;
    }
}