/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.h
 * Author: anclenius
 *
 * Created on June 16, 2019, 9:21 AM
 */

#ifndef COLA_H
#define COLA_H
#include"Nodo.h"
class Cola {
public:
    Nodo *inicio;
    Nodo *fin;
    Cola();
    int total;
    void encolar (Nodo *nodo);
    Nodo* descolar ();
    void graficar();
    bool estaVacia();
};




#endif /* COLA_H */

