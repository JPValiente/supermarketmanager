
#include "Nodo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Nodo::Nodo(int id, void* info){
    this->id = id;
    this->info = info;
}

void* Nodo::getInfo() {
    return this->info;
}

void Nodo::setInfo(Nodo* info){
    this->info = info;
}