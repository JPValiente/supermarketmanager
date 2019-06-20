/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>
#include <thread>
#include <fstream>
//#include <pthread.h>
#include "SuperMarket.h"
#include "Pila.h"
#include "Cola.h"
#include "ListaDoble.h"
#include "ListaCircular.h"
#include <string>

using namespace std;

void SuperMarket::agregarClienteAEspera(Nodo* cliente){
    this->clientes->encolar(cliente);
}

SuperMarket::SuperMarket() {
    clientes = new Cola();
    pilaCarreta1 = new Pila();
    pilaCarreta2 = new Pila();
    clientesEnEspera = new Cola();
    colaDePagos = new Cola();
    clientesComprando = new ListaCircular();
    cajas = new ListaDoble();
}


bool SuperMarket::hayCarretas(){
    Nodo *carretaSaliendo;
    if(!pilaCarreta1->estaVacia() || !pilaCarreta2->estaVacia()) {
    }  else {
        cout<<"No hay carretas disponibles en este momento, cliente en espera"<<endl;
        return false;
    }
    
    return true;
}

Nodo* SuperMarket::sacarCarreta(){
    Nodo *carretaSaliendo;
    if(!pilaCarreta1->estaVacia()) {
        carretaSaliendo = pilaCarreta1->desapilar();
    } else if(!pilaCarreta2->estaVacia()){
        carretaSaliendo = pilaCarreta2->desapilar();
    } else {
        cout<<"No hay carretas disponibles en este momento, cliente en espera"<<endl;
        return nullptr;
    }
    
    return carretaSaliendo;
}

void SuperMarket::asignarCarretaACliente(Nodo* cliente,Nodo* carreta){
    cliente->info = carreta;
    cout<<"Carreta "<<carreta->id<<" fue tomada por el cliente "<<cliente->id<<endl;
}

/*
if(clientes->estaVacia()){
        Nodo *clienteSaliendo = clientes->descolar();
        clienteSaliendo->info = carretaSaliendo;
        agregarACompras(clienteSaliendo);
    } else {
        cout<<"No hay mas clientes que atender"<<endl;
        return false;
    } 
*/
Nodo* SuperMarket::sacarClienteDeCompras(){
    int totalClientes = this->clientesComprando->totalElementos;
    int total = this->clientesComprando->total;
    srand((int)time(0));
    int random = (rand() % 10) + 1;
    cout<<"Numero generado "<<random<<endl;
    
    if(random <= total && clientesComprando->buscarNodo(random) != nullptr) {
        
        cout<<"El cliente"<<random<<" salio de la lista de compras"<<endl;
        
        Nodo* cliente = clientesComprando->borrar(random);
        return cliente;
    } else {
        cout<<"No se hizo nada porque el numero random fue "<<random<<" y se esperaba un numero menos de "<<totalClientes<<endl;
        return nullptr;
    }
    
}

bool SuperMarket::encolarCliente(Nodo* cliente){
    this->colaDePagos->encolar(cliente);
}

void SuperMarket::agregarACompras(Nodo* cliente){
    this->clientesComprando->insertar(cliente);
}

bool SuperMarket::guardarCarreta(Nodo* carreta){
    sleep(0);
    srand((int)time(0));
    int pila = (rand() % 2) + 1;
    if(pila == 1){
        this->pilaCarreta1->apilar(carreta);
        cout<<"Carreta "<<carreta->id<<" guardada en la pila 1"<<endl;
    } else {
        this->pilaCarreta2->apilar(carreta);
        cout<<"Carreta "<<carreta->id<<" guardada en la pila 2"<<endl;
    }
}



NodoCaja* SuperMarket::asignarClienteACaja(){
    Nodo* cliente = this->colaDePagos->descolar();
    NodoCaja* aux = this->cajas->inicio;
    bool flag = false;
    while(aux->siguiente != nullptr){
        if(!aux->ocupado){
            flag = true;
            break;
        }
        aux = aux->siguiente;
    }
    if(flag){
        aux->ocupado = true;
        aux->cliente = cliente;
        return aux;
        
    } else {
        cout<<"Todas las cajas estan ocupadas"<<endl;
        return nullptr;
    }
    
}

void SuperMarket::atenderCajas(){
    sleep(1);
    NodoCaja* caja = cajas->inicio;
    while(caja->siguiente != nullptr){
        cout<<"Atendiendo caja "<<caja->id<<endl;
        if(caja->cumplioTiempo() && caja->ocupado){ //Valida al instante, no espera el tiempo
            Nodo* carreta = (Nodo*)caja->cliente->info;
            cout<<"ID de carreta: "<<carreta->id;
            cout<<"Cliente: "<<caja->cliente->id<<" atendido en caja "<<caja->id<<"."<<endl;
            caja->vaciarCaja();
            this->guardarCarreta(carreta);
        }
        caja = caja->siguiente;
    }
    
}


Nodo* SuperMarket::crearCliente(int id){
    Nodo* nuevoCliente = new Nodo(id,nullptr);
    return nuevoCliente;
}

NodoCaja* SuperMarket::crearCaja(int id){
    NodoCaja* nuevaCaja = new NodoCaja(id);
    return nuevaCaja;
}

Nodo* SuperMarket::crearCarreta(int id){
    Nodo* carreta = new Nodo(id,nullptr);
    return carreta;
}

void SuperMarket::agregarCajaAlSistema(NodoCaja* caja){
    this->cajas->insertar(caja);
    cout<<"Caja numero "<<caja->id<<" disponible en el sistema"<<endl;
}

void SuperMarket::graficar(){
    cout<<"Graficando..."<<endl;
    string salida = "";
    salida = salida + "digraph G {\n";
    //cout<<"Graficando clientes..."<<endl;
    salida = salida + graficarClientes();
    //cout<<"Graficando carretas 1..."<<endl;
    salida = salida + graficarCarretas1();
    //cout<<"Graficando carretas 2..."<<endl;
    salida = salida + graficarCarretas2();
    //cout<<"Graficando cola de pagos..."<<endl;
    salida = salida + graficarColaDePagos();
    //cout<<"Graficando clientes comprando..."<<endl;
    salida = salida + graficarClientesComprando();
    //cout<<"Graficando cajas..."<<endl;
    salida = salida + graficarCajas();
    salida = salida + "\n}";
    //cout<<"Terminando de graficar"<<endl;
    graphviz(salida);   
}

string SuperMarket::graficarClientes(){
    string salida = "subgraph cluster_a {\n";
    salida = salida + "style=filled;\ncolor=lightgrey;\nnode [style=filled,color=white];\n";
    Nodo* aux = this->clientes->inicio;
    if(aux != nullptr){
        salida = salida + "Cliente_ID_" + to_string(aux->id);
        while(aux->siguiente != nullptr){
            salida = salida + " -> ";
            salida = salida + "Cliente_ID_" + to_string(aux->id);
            aux = aux->siguiente;
        }
        salida = salida + " -> ";
        salida = salida + "Cliente_ID_" + to_string(aux->id);
    }
    salida = salida + "\nlabel = \"Cola de espera\n Clientes\"};\n\n\n";
    return salida;
}

string SuperMarket::graficarCarretas1(){
    string salida = "subgraph cluster_b {\n";
    salida = salida + "style=filled;\ncolor=lightgrey;\nnode [style=filled,color=white];\n";
    Nodo* aux = this->pilaCarreta1->inicio;
    if(aux != nullptr){
        salida = salida + "Carreta_ID_" + to_string(aux->id);
        while(aux->siguiente != nullptr){
            salida = salida + " -> ";
            salida = salida + "Carreta_ID_" + to_string(aux->id);
            aux = aux->siguiente;
        }
        salida = salida + " -> ";
        salida = salida + "Carreta_ID_" + to_string(aux->id);
    }
    salida = salida + "\nlabel = \"Pila de carretas 1\"};\n\n\n";
    return salida;
}

string SuperMarket::graficarCarretas2(){
    string salida = "subgraph cluster_c {\n";
    salida = salida + "style=filled;\ncolor=lightgrey;\nnode [style=filled,color=white];\n";
    
    Nodo* aux = this->pilaCarreta2->inicio;
    if(aux != nullptr){
        salida = salida + "Carreta_ID_" + to_string(aux->id);
        while(aux->siguiente != nullptr){
            salida = salida + " -> ";
            salida = salida + "Carreta_ID_" + to_string(aux->id);
            aux = aux->siguiente;
        }
        salida = salida + " -> ";
        salida = salida + "Carreta_ID_" + to_string(aux->id);
    }
    
    salida = salida + "\nlabel = \"Pila de carretas 2\"};\n\n\n";
    return salida;
}

string SuperMarket::graficarColaDePagos(){
    string salida = "subgraph cluster_d {\n";
    salida = salida + "style=filled;\ncolor=lightgrey;\nnode [style=filled,color=white];\n";
    if(!colaDePagos->estaVacia()){
        Nodo* aux = this->colaDePagos->inicio;
        if(aux != nullptr){
            salida = salida + "Cliente_ID_" + to_string(aux->id);
            while(aux->siguiente != nullptr){
                salida = salida + " -> ";
                salida = salida + "Carreta_ID_" + to_string(aux->id);
                aux = aux->siguiente;
            }
            salida = salida + " -> ";
            salida = salida + "Cliente_ID_" + to_string(aux->id);
        }  
    }
    
    
    salida = salida + "\nlabel = \"Cola de espera para cajas\"};\n\n\n";
    return salida;
}

string SuperMarket::graficarClientesComprando(){
    string salida = "subgraph cluster_e {\n";
    salida = salida + "style=filled;\ncolor=lightgrey;\nnode [style=filled,color=white];\n";
    
    Nodo* aux = this->clientesComprando->inicio;
    Nodo* finl = this->clientesComprando->fin;
    if(aux != nullptr){
        salida = salida + "Cliente_ID_" + to_string(aux->id);
        while(aux->siguiente != finl){
            salida = salida + " -> ";
            salida = salida + "Carreta_ID_" + to_string(aux->id);
            aux = aux->siguiente;
        }
        salida = salida + " -> ";
        salida = salida + "Cliente_ID_" + to_string(aux->id);
        salida = salida + " -> ";
        salida = salida + "Cliente_ID_" + to_string(this->clientesComprando->inicio->id);
    }
    
    salida = salida + "\nlabel = \"Lista circular de clientes\"};\n\n\n";
    return salida;
}

string SuperMarket::graficarCajas(){
    string salida = "subgraph cluster_f {\n";
    salida = salida + "style=filled;\ncolor=lightgrey;\nnode [style=filled,color=white];\n";
    
    cout<<"Graficando normal"<<endl;
    NodoCaja* aux = this->cajas->inicio;
    if(aux != nullptr){
        salida = salida + "Caja_ID_" + to_string(aux->id);
        while(aux->siguiente != nullptr){
            salida = salida + " -> ";
            salida = salida + "Caja_ID_" + to_string(aux->id);
            aux = aux->siguiente;
        }
        salida = salida + " -> ";
        salida = salida + "Caja_ID_" + to_string(aux->id) + ";\n";
        
        
        aux = this->cajas->fin;
        cout<<"Graficando inverso"<<endl;
        salida = salida + "Caja_ID_" + to_string(aux->id);
        while(aux->anterior != nullptr){
            salida = salida + " -> ";
            salida = salida + "Caja_ID_" + to_string(aux->id);
            aux = aux->anterior;
        }
        if(aux != nullptr){
            salida = salida + " -> ";
            salida = salida + "Caja_ID_" + to_string(aux->id) + ";\n";
        }
        cout<<"Terminando de graficar cajas"<<endl;
    }
    
    salida = salida + "\nlabel = \"Lista doble de cajas\";}\n\n\n";
    return salida;
}

void SuperMarket::graphviz(string salida){
  ofstream f2;
  f2.open("grafico.dot", ofstream::out | ofstream::trunc);
  f2<<salida;
  f2<<endl;
  system("dot -Tpng grafico.dot -o graficosupermarket");
  f2.close();

}