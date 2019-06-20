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
        inicio->anterior = nodo;
        fin = nodo;
    }
    this->totalElementos = this->totalElementos + 1;
    this->total = this->total + 1;
}

Nodo* ListaCircular::borrar(int id){
    if(estaVacia() == 1){
        cout<<"Lista Circular Vacia";
    } else {
        if(buscarNodo(id) != nullptr){
            Nodo* auxiliar;
            if(inicio == fin && inicio->id == id) {
                auxiliar = inicio;
                inicio = fin = nullptr;

            } else {
                if(inicio->id == id){
                    auxiliar = inicio;
                    Nodo* siguiente = auxiliar->siguiente;
                    Nodo* anterior = auxiliar->anterior;
                    anterior->siguiente =siguiente;
                    siguiente->anterior = anterior;
                    inicio = siguiente;
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
                    }if(aux->id == id){
                        Nodo* anterior = aux->anterior;
                        Nodo* siguiente = aux->siguiente;
                        anterior->siguiente = siguiente;
                        siguiente->anterior = anterior;
                        auxiliar = aux;
                    }
                }

            }
            this->totalElementos = this->totalElementos - 1;
            return auxiliar;
        } else {
            cout<<"El cliente ya no esta"<<endl;
        }
        
    }
}

int ListaCircular::estaVacia(){
    if(inicio == nullptr && fin == nullptr){
        return 1;
    } else {
        return 0;
    }
}

Nodo* ListaCircular::buscarNodo(int id){
    Nodo* aux = inicio;
    cout<<"Buscando id: "<<id<<endl;
    if(inicio->id == id){
        aux = inicio;
        
    } else if( fin->id == id) {
        aux = fin;
        ;
    } else {
        while(aux->siguiente != fin){
            if(aux->id == id){
                break;
            }
            aux = aux->siguiente;
        }
    }
    if(aux->id == id){
        cout<<id<<" encontrado."<<endl;
        return aux;
    }
    return nullptr;
}

void ListaCircular::recorrerLista(){
    cout<<"Este es el estado de la lista circular"<<endl;
    Nodo* aux = inicio;
    while(aux->siguiente != fin){
        cout<<"ID: "<<aux->id<<" Anterior: "<<aux->anterior->id<<" Siguiente: "<<aux->siguiente->id<<endl;
        aux = aux->siguiente;
    }
    cout<<"ID: "<<aux->id<<" Anterior: "<<aux->anterior->id<<" Siguiente: "<<aux->siguiente->id<<endl;
}