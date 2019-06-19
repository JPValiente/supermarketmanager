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
#include <unistd.h>
#include <thread>
#include <ctime>
//Headers
#include "Nodo.h"
#include "NodoCaja.h"
#include "Pila.h"
#include "Cola.h"
#include "ListaCircular.h"
#include "ListaDoble.h"
#include "SuperMarket.h"
using namespace std;

//Declaracion de funciones
void asignarClientes();
void start();
void llenar(int,int,int);
void simularSupermercado(int,int,int);

//Declaracion de variables globales
SuperMarket* supermercado;

//Hilos

/*
 * 
 */
int main(int argc, char** argv) {
    //start();
    supermercado = new SuperMarket();
    start();
    return 0;
}

void simularSupermercado(int clientes, int cajas, int carretas){
    cout<<"Comenzando la simulacion"<<endl<<endl<<endl;
    int conteo = 0;
    clientes = supermercado->clientes->total;
    cout<<"Total de clientes adentro: "<<clientes<<endl;
    while(clientes > 0){
        conteo++;
        clientes = supermercado->clientes->total + supermercado->clientesComprando->totalElementos + supermercado->colaDePagos->total;
        usleep(100000);
        cout<<endl<<endl<<endl<<endl<<"Clientes en cola de espera: "<<clientes<<endl;
        cout<<"Clientes comprando: "<<supermercado->clientesComprando->totalElementos<<endl;
        cout<<"Clientes en cola de pagos: "<<supermercado->colaDePagos->total<<endl;
        cout<<"######### Paso "<<conteo<<" #########"<<endl<<endl;
        if(supermercado->hayCarretas()){
            Nodo* carreta = supermercado->sacarCarreta();
            Nodo* cliente = supermercado->clientes->descolar();
            supermercado->asignarCarretaACliente(cliente,carreta);
            supermercado->agregarACompras(cliente);
            
            Nodo* clienteSaliente = supermercado->sacarClienteDeCompras();
            if(clienteSaliente != nullptr){
                supermercado->encolarCliente(clienteSaliente);
                NodoCaja* caja = supermercado->asignarClienteACaja();
                if(caja != nullptr){
                    supermercado->atenderCajas(); //Aqui se combina de una vez el guardar la carreta, en liberar al cliente.
                }   
            }
        } else {
            
        }
    }
    
    
}

void start(){
    int clientes,cajas,carretas;
    supermercado = new SuperMarket();
    cout<<"Cuantos clientes entraran?"<<endl;
    cin>>clientes;
    cout<<"Cuantas cajas estaran disponibles?"<<endl;
    cin>>cajas;
    cout<<"Cuantas carretas estaran disponibles?"<<endl;
    cin>>carretas;
    llenar(clientes,cajas,carretas);
    simularSupermercado(clientes,cajas,carretas);
}

void llenar(int clientes,int cajas, int carretas){
    cout<<"Cargando"<<endl;
    Nodo* cliente;
    Nodo* carreta;
    NodoCaja* caja;
    for(int i = 1; i <= clientes; i++){
        cliente = supermercado->crearCliente(i);
        supermercado->agregarClienteAEspera(cliente);
    }
    cout<<"."<<endl;
    for(int i = 1; i <= cajas; i++){
        caja = supermercado->crearCaja(i);
        supermercado->agregarCajaAlSistema(caja);
    }
    cout<<".."<<endl;
    for(int i = 1; i <= carretas; i++){
        carreta = supermercado->crearCarreta(i);
        supermercado->guardarCarreta(carreta);
    }
    cout<<"..."<<endl;
    
}




