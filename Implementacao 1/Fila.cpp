#include "Fila.h"

void Fila::enfileirar(int valor) {
    fila.push(valor);
}

bool Fila::encontrar(int valor) {
    queue<int> filaTemp = fila;
    while (!filaTemp.empty()) {
        if (filaTemp.front() == valor) {
            return true;
        }
        filaTemp.pop();
    }
    return false;
}

void Fila::desenfileirar() {
    if (!fila.empty()) {
        fila.pop();
    }
}

void Fila::removerK(int k) {
    for (int i = 0; i < k && !fila.empty(); ++i) {
        fila.pop();
    }
}
