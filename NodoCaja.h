#ifndef NODOCAJA_H
#define NODOCAJA_H

#include "NodoCaja.h"
#include "Nodo.h"
class NodoCaja {
public:
    int id;
    int tiempoDeServicio;
    bool ocupado;
    Nodo *cliente;
    NodoCaja *anterior;
    NodoCaja *siguiente;
    NodoCaja(int id);
    void setCliente(Nodo *cliente);
    void setStatus(bool flag);
    bool estaOcupado();
    Nodo* getCliente();
    void vaciarCaja();
    
};


#endif /* NODOCAJA_H */

