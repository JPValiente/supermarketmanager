/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pila.h
 * Author: anclenius
 *
 * Created on June 16, 2019, 11:20 AM
 */

#ifndef PILA_H
#define PILA_H
#include"Nodo.h"
class Pila {
public:
    Nodo *inicio;
    Nodo *fin;
    int total;
    Pila();
    void apilar (Nodo *nodo);
    Nodo* desapilar ();
    void imprimirDatos();
    bool estaVacia();
    void graficar();
};



#endif /* PILA_H */

