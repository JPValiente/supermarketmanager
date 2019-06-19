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

//Headers
#include "Nodo.h"
#include "Pila.h"
#include "Cola.h"
#include "ListaCircular.h"
#include "ListaDoble.h"
#include "SuperMarket.h"
using namespace std;

//Declaracion de funciones
void asignarClientes();
void start();
void simularSupermercado(int,int,int);

//Declaracion de variables globales
SuperMarket* supermercado;

//Hilos

/*
 * 
 */
int main(int argc, char** argv) {
    cout<<"Termino el hilo"<<endl;
    return 0;
}

void simularSupermercado(int clientes, int cajas, int carretas){
    cout<<"Comenzando la simulacion";
    int conteo = 1;
    while(clientes > 0){
        cout<<"######### Paso "<<1<<" #########"<<endl<<endl;
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
    simularSupermercado(clientes,cajas,carretas);
}




