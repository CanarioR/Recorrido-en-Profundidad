#include "administradora.h"

using namespace std;

administradora::administradora() : cabeza(nullptr) {}

void administradora::limpiarLista() {
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;  // Libera la memoria del Nodo
    }
    // Asegúrate de restablecer el puntero 'cola' u otros valores pertinentes si es necesario
}


void administradora::agregarInicio(Neurona& neu ){
    Nodo* nuevoNodo = new Nodo(neu);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void administradora::agregarFinal(Neurona& neu){
    Nodo* nuevoNodo = new Nodo(neu);

        // Si la lista está vacía, simplemente establece la cabeza como el nuevo nodo.
        if (!cabeza) {
            cabeza = nuevoNodo;
            return;
        }

        // Encuentra el último nodo en la lista.
        Nodo* temp = cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }

        // Conecta el último nodo con el nuevo nodo.
        temp->siguiente = nuevoNodo;
}

string administradora::mostrar(){
    Nodo* temp = cabeza;
    std::string res;  // Inicializa res como una cadena vacía
    while (temp)
    {
        res += temp->dato.print(); // Usa += para agregar datos a res
        temp = temp->siguiente;
    }
    return res;
}

int administradora::numeroDeNeuronas() {
    int contador = 0;
    Nodo* temp = cabeza;
    while (temp) {
        contador++;
        temp = temp->siguiente;
    }
    return contador;
}

Neurona* administradora::obtenerNeuronaEnPosicion(int posicion) {
    int contador = 0;
    Nodo* temp = cabeza;

    while (temp) {
        if (contador == posicion) {
            // Se encontró la neurona en la posición deseada
            return &(temp->dato);
        }
        contador++;
        temp = temp->siguiente;
    }

    // Si no se encontró la neurona en la posición especificada, devuelve nullptr
    return nullptr;
}

Neurona* administradora::buscarNeuronaPorID(int idBuscado) {
    Nodo* temp = cabeza;
    while (temp) {
        if (temp->dato.getID() == idBuscado) {
            // La neurona fue encontrada, devuelve un puntero a la neurona
            return &(temp->dato);
        }
        temp = temp->siguiente;
    }
    // Si no se encontró la neurona, devuelve nullptr
    return nullptr;
}

void administradora::ordenarPorID() {
    Nodo* current;
    Nodo* index = nullptr;
    Neurona* temp;

    if (cabeza == nullptr) {
        return;
    } else {
        for (current = cabeza; current->siguiente != nullptr; current = current->siguiente) {
            for (index = current->siguiente; index != nullptr; index = index->siguiente) {
                if (current->dato.getID() > index->dato.getID()) {
                    temp = new Neurona(current->dato);
                    current->dato = index->dato;
                    index->dato = *temp;
                }
            }
        }
    }
}

void administradora::ordenarPorVoltaje() {
    Nodo* current;
    Nodo* index = nullptr;
    Neurona* temp;

    if (cabeza == nullptr) {
        return;
    } else {
        for (current = cabeza; current->siguiente != nullptr; current = current->siguiente) {
            for (index = current->siguiente; index != nullptr; index = index->siguiente) {
                if (current->dato.getaVolt() > index->dato.getaVolt()) {
                    temp = new Neurona(current->dato);
                    current->dato = index->dato;
                    index->dato = *temp;
                }
            }
        }
    }
}


