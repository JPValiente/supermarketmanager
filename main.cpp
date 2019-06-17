/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: anclenius
 *
 * Created on June 16, 2019, 8:03 AM
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Nodo.h"
#include "Pila.h"
#include "Cola.h"
using namespace std;
Nodo* crearNodo(int,void*);
/*
 * 
 */
int main(int argc, char** argv) {
    int dato = 5;
    Pila *pila;
    Cola *cola;
    Nodo *nodo1 = crearNodo(1,&dato);
    Nodo *nodo2 = crearNodo(2,&dato);
    Nodo *nodo3 = crearNodo(3,&dato);
    pila->apilar(nodo1);
    pila->apilar(nodo2);
    pila->apilar(nodo3);
    pila->imprimirDatos();
    cout<<"Nueva salida"<<endl;
    Nodo* nodo4 = pila->desapilar();
    cout<<"Nodo que salio: "<<nodo4->id<<endl;
    pila->imprimirDatos();
    return 0;
}

Nodo* crearNodo(int id,void *info){
    Nodo* nuevoNodo = new Nodo(id,info);
    return nuevoNodo;
}

