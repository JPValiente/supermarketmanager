#ifndef NODOCAJA_H
#define NODOCAJA_H

#include "Nodo.h"

class NodoCaja {
public:
    int id;
    int tiempoDeServicio;
    bool ocupado;
    Nodo *cliente;
    Nodo *carreta;
    NodoCaja *anterior;
    NodoCaja *siguiente;
    NodoCaja(int id);
    
};


#endif /* NODOCAJA_H */

