/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: anclenius
 *
 * Created on June 16, 2019, 8:54 AM
 */

#ifndef NODO_H
#define NODO_H

//En el apuntador de info, en el caso de clientes, se va a guardar la carreta para optimizar codigo
class Nodo {
public:
    int id;
    void *info;
    Nodo *anterior;
    Nodo *siguiente;
    Nodo(int id,void*info);
    void* getInfo();
    void setInfo(Nodo *info);
};








#endif /* NODO_H */

