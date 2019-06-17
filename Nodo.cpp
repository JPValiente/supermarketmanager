
#include "Nodo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Nodo::Nodo(int id, void* info){
    this->id = id;
    this->info = info;
}