/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SuperMarket.h
 * Author: anclenius
 *
 * Created on June 17, 2019, 5:43 PM
 */

#ifndef SUPERMARKET_H
#define SUPERMARKET_H
#include "Nodo.h"
#include "NodoCaja.h"
#include "Pila.h"
#include "Cola.h"
#include "ListaCircular.h"
#include "ListaDoble.h"
//Agregar objeto cliente

class SuperMarket{
public:
    SuperMarket();
    Cola *clientes; //Clientes entrando al supermercado
    Pila *pilaCarreta1; //Pila de carretas 1
    Pila *pilaCarreta2; //Pila de carretas 2
    Cola *clientesEnEspera; //Lo mismo de clientes, se tiene aqui por si se va a implementar algo mas
    Cola *colaDePagos; //Cola de clientes para poder pagar
    ListaCircular *clientesComprando; //Clientes adentro del supermercado
    ListaDoble *cajas; //Lista doble de las cajas que estan disponibles para atender;
    
    void agregarACompras(Nodo* cliente); //El cliente entra a una lista circular, para salir hay que generar un numero aleatorio del 0 al 100
    //Si el numero generado es mayor al tamaño de la lista, entonces ningun cliente pasa a la cola de pago. Caso contrario, el indice del cliente sale.
    void agregarClienteAEspera(Nodo* cliente); //Los clientes entran directo a tomar una carreta, si no hay carretas, les toca esperar
    bool hayCarretas(); //Retorna verdadero si hay carretas disponibles.
    bool guardarCarreta(Nodo *carreta); //Al finalizar la compra del cliente, la carreta se guarda en la pila. Se hace un aleatorio de 1 y 2, que corresponde a la pila
    Nodo* sacarCarreta(); //Se hace pop a la pila de la carreta
    bool encolarCliente(Nodo* cliente); //Se encola gente a la cola de pagos, en caso que las cajas esten llenas
    Nodo* sacarCliente(); //Saca al cliente de la cola de pagos y finaliza la venta;
    void finalizarCompra(); //Finaliza la compra, llama al metodo sacarCliente() y guarda la carreta;
    void graficarSistema(); //Grafica todo el sistema, es recomendable usar subgraphs.
    Nodo* crearCliente(int id);
    NodoCaja* crearCaja(int id);
    
};


#endif /* SUPERMARKET_H */

