/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCircular.h
 * Author: anclenius
 *
 * Created on June 16, 2019, 3:42 PM
 */

#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include "Nodo.h"
class ListaCircular{
public:
    Nodo *inicio;
    Nodo *fin;
    int totalElementos;
    int total;
    ListaCircular();
    void insertar(Nodo* nodo);
    Nodo* borrar(int id);
    int estaVacia();
    Nodo* buscarNodo(int id);
    void graficar();
    void recorrerLista();
};


#endif /* LISTACIRCULAR_H */

