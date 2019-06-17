/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDoble.h
 * Author: anclenius
 *
 * Created on June 16, 2019, 7:36 PM
 */

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

class ListaDoble{
public:
    Nodo *inicio;
    Nodo *fin;
    int totalElementos;
    ListaCircular();
    void insertar();
    void borrar(int id);
    int estaVacia();
};

#endif /* LISTADOBLE_H */

